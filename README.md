# Sim2Real ROS2 部署开发

> 目标平台: 地瓜 RDK5 (4核 4GB, aarch64) | 中间件: ROS2 Humble  
> 参考实现: UniLab/Sim2real (C++14/ROS Noetic)


```
Week 1: LPMS-SI2_imu
  ├─ 实现串口通信 (LPMS-SI2协议解析)
  ├─ 发布 /imu/data (sensor_msgs/Imu)
  └─ 用 rqt_plot 验证数据正确性

Week 2: drive_motor
  ├─ 实现CAN/RS485通信 (电机协议)
  ├─ 发布 /motor_state (MotorState)
  ├─ 订阅 /motor_cmd (MotorCmd)
  └─ 用 rqt 验证电机响应

Week 3: sim2real (推理部分)
  ├─ ONNX Runtime 推理封装
  ├─ IMU回调 → 姿态解算
  ├─ MotorState回调 → 坐标变换
  ├─ 观测构造 + 帧堆叠
  ├─ 动作输出 + 逆变换
  └─ 单线程测试推理正确性

Week 4: sim2real (控制部分)
  ├─ 双线程架构 (RL 50Hz + PD 500Hz)
  ├─ /motor_cmd 发布
  ├─ 坠落检测 + 安全模式
  └─ 手柄控制接口

Week 5: 联调 + 实测
  ├─ 方向校准 (每个电机 direction)
  ├─ 零点校准 (每个电机 urdf_offset)
  ├─ action_scale 调参
  └─ 行走验证
```

## 1. 整体架构

```
┌──────────────────────────────────────────────────────────┐
│  物理硬件                                                  │
│  ├─ LPMS-SI2 IMU  ──USB/UART──→ /dev/imu                  │
│  └─ 电机 (CAN/RS485)  ──USB转CANFD──→ /dev/motor             │
└──────────────────────────────────────────────────────────┘
                          │
          ┌───────────────┼───────────────┐
          ▼               ▼               ▼
┌──────────────┐ ┌──────────────┐ ┌──────────────┐
│ LPMS-SI2_imu │ │ drive_motor  │ │   sim2real   │
│              │ │              │ │              │
│  发布话题:    │ │  发布话题:    │ │  核心节点:    │
│  /imu/data   │ │  /motor_state│ │  订阅以上话题  │
│              │ │              │ │  RL推理       │
│              │ │  订阅话题:    │ │  发布:        │
│              │ │  /motor_cmd  │ │  /motor_cmd   │
└──────────────┘ └──────────────┘ └──────────────┘
                          ▲               │
                          │               │
                     motor_state      motor_cmd
                   (位置/速度/力矩)   (目标位置/Kp/Kd)
```

### 数据流

```
LPMS-SI2_imu → /imu/data (sensor_msgs/Imu)
    │
    ▼
┌──────────────────────────────────────────────┐
│  sim2real 节点                                │
│                                                │
│  输入:                                          │
│    /imu/data     → 姿态/角速度/加速度            │
│    /motor_state  → 电机位置/速度/力矩            │
│    /joy          → 手柄指令 (可选)               │
│                                                │
│  RL推理线程 (50Hz):                              │
│    MotorState → RobotState 坐标变换              │
│    构造观测 → 策略推理 → 动作输出                 │
│    RobotOutput → MotorCmd 逆变换                │
│    写入 motor_cmd_ (共享)                       │
│                                                │
│  PD控制线程 (500Hz):                             │
│    读取 motor_cmd_ (ZOH)                        │
│    发送 /motor_cmd                             │
│    坠落检测                                      │
└──────────────────────────────────────────────┘
    │
    ▼
drive_motor ← /motor_cmd → CANFD → 电机
(伺服PD闭环 1-10kHz)
```

---

## 2. 包分工与接口定义

### 2.1 drive_motor — 电机驱动包

**职责**: 硬件抽象层，负责与电机通信、收发指令。

#### 发布话题

| 话题 | 消息类型 | 频率 | 说明 |
|------|---------|------|------|
| `/motor_state` | `MotorState.msg` | 500Hz | 电机当前状态反馈 |

```msg
# MotorState.msg (自定义消息)
float32[] position       # N个关节当前位置 (rad)
float32[] velocity       # N个关节当前速度 (rad/s)
float32[] torque         # N个关节当前力矩 (N·m)
```

**位置数据含义**: 每个电机返回的绝对编码器值，未经任何坐标变换。sim2real会通过 `urdf_offset` 和 `direction` 转换成机器人关节角度。

#### 订阅话题

| 话题 | 消息类型 | 频率 | 说明 |
|------|---------|------|------|
| `/motor_cmd` | `MotorCmd.msg` | 500Hz | sim2real下发的电机指令 |

```msg
# MotorCmd.msg (自定义消息)
float32[] target_q       # N个关节的目标位置 (电机坐标系, rad)
float32[] target_dq      # N个关节的目标速度 (rad/s), 可为0
float32[] target_tau     # N个关节的目标力矩 (N·m), 可为0
float32[] target_kp      # N个关节的PD比例增益
float32[] target_kd      # N个关节的PD微分增益
```

#### 必须实现的核心功能

```
drive_motor 节点内部:
  ┌─────────────────────────────────────────────┐
  │ main_loop() @ 500Hz                         │
  │                                              │
  │ 1. 读取电机编码器                             │
  │    → 每个电机: position, velocity, torque     │
  │                                              │
  │ 2. 发布 /motor_state                         │
  │    → MotorState.position[] = raw_encoder      │
  │    → MotorState.velocity[] = raw_velocity     │
  │    → MotorState.torque[]   = raw_torque       │
  │                                              │
  │ 3. 检查是否有新的 /motor_cmd                  │
  │    if motor_cmd 为空:                         │
  │      → keepLastCmd()  保持上一帧指令           │
  │                                              │
  │ 4. 发送指令到硬件                             │
  │    for each motor i:                         │
  │      cmd[i] = {                               │
  │        position: motor_cmd.target_q[i],       │
  │        velocity: motor_cmd.target_dq[i],      │
  │        torque:   motor_cmd.target_tau[i],     │
  │        kp:       motor_cmd.target_kp[i],      │
  │        kd:       motor_cmd.target_kd[i]       │
  │      }                                        │
  │    serial_send(cmd)                           │
  └─────────────────────────────────────────────┘
```


---

### 2.2 LPMS-SI2_imu — IMU驱动包

**职责**: 驱动LPMS-SI2传感器，发布标准ROS2 IMU消息。

#### 发布话题

| 话题 | 消息类型 | 频率 | 说明 |
|------|---------|------|------|
| `/imu/data` | `sensor_msgs/Imu` | 200-500Hz | 姿态+角速度+加速度 |

```msg
# sensor_msgs/Imu (ROS2 标准消息，无需自定义)
std_msgs/Header header
    builtin_interfaces/Time stamp
    string frame_id                    # "imu_link"

geometry_msgs/Quaternion orientation   # 四元数 w,x,y,z
float64[9] orientation_covariance

geometry_msgs/Vector3 angular_velocity # 角速度 (rad/s)
float64[9] angular_velocity_covariance

geometry_msgs/Vector3 linear_acceleration  # 线加速度 (m/s²)
float64[9] linear_acceleration_covariance
```


#### sim2real 需要从 IMU 获得的维度

| 字段 | 维度 | 用途 |
|------|------|------|
| `orientation` (四元数) | 4 | → Euler角 → 策略观测: 欧拉角或重力投影 |
| `angular_velocity` | 3 | → 策略观测前3维: `base_ang_vel × scale` |
| `linear_acceleration` | 3 | → 坠落检测 (加速度 > 阈值) |

---

## 3. sim2real — 核心推理部署包

### 3.1 节点结构

```
sim2real 节点 (ROS2)
├─ 订阅:
│   ├─ /imu/data       (sensor_msgs/Imu)         @ 200Hz
│   ├─ /motor_state    (MotorState)               @ 500Hz
│   └─ /cmd_vel        (geometry_msgs/Twist)     @ 50Hz
│
├─ RL推理线程: @ 50Hz
│   ├─ motor_state → RobotState 变换
│   ├─ 构造观测向量
│   ├─ ONNX Runtime 推理
│   ├─ 动作裁剪 + 缩放
│   ├─ RobotOutput → MotorCmd 逆变换
│   └─ 写入 motor_cmd_ (outputMutex_)
│
├─ PD控制线程: @ 500Hz
│   ├─ 读取 motor_cmd_ (ZOH)
│   ├─ 发送 /motor_cmd
│   └─ 坠落检测
│
└─ 发布:
    └─ /motor_cmd (MotorCmd) @ 500Hz
```

## 4. sim2real 核心代码框架

### 4.1 目录结构

```
sim2real/
├── sim2real/
│   ├── __init__.py
│   ├── sim2real_node.py        # 主节点 (三线程)
│   ├── policy.py                # 策略基类 + HumanoidgymPolicy
│   ├── inference.py             # ONNX Runtime 推理封装
│   ├── config_loader.py         # YAML配置加载
│   └── fsm.py                   # 状态机
├── config/
│   ├── pd_config.yaml           # 关节映射 + PD增益
│   └── rl_config.yaml           # 策略配置 + 观测参数
├── policy/
│   └── walk_policy.onnx         # ONNX策略模型
├── launch/
│   └── sim2real.launch.py       # ROS2 launch
├── package.xml
└── setup.py
```

## 5. 模型转换与推理后端

### 5.1 RDK5 推理后端选择

```
RDK5 (4核 A55, 4GB, 可能有NPU)
     │
     ├─ 无NPU → ONNX Runtime CPU (推荐)
     │             pip install onnxruntime
     │
     └─ 有NPU (如RK3588s同款) → RKNN
              pip install rknn-toolkit-lite2
```

### 5.2 模型转换

```bash
# 训练产出 .pt (TorchScript) → ONNX
python3 pt2onnx.py

# ONNX → RKNN (如果有NPU)
python3 onnx2rknn.py
```

## 6. 关键配置调参

| 参数 | 起步值 | 说明 |
|------|--------|------|
| `action_scale` | 0.1 → 0.5 | 越小越稳但动作幅度小 |
| `kp` (腿) | 80 → 110 | 越大越硬但可能振荡 |
| `kd` (腿) | 1.0 → 2.0 | 阻尼，抑制振荡 |
| `direction` | ±1 | 必须逐个电机实测 |
| `urdf_offset` | 实测 | 机器人默认站立姿态的电机编码器值 |
| `clip_obs` | 18.0 | 观测截断，防止异常值 |
| `frame_stack` | 4~6 | 堆叠越多越平稳但延迟越大 |

**实测 direction**: 对单个电机发送 `target_q = 0.2`，观察关节旋转方向。若仿真中关节位置增大则 `direction = 1`，减小则 `direction = -1`。

**实测 urdf_offset**: 将机器人摆到训练默认姿态(站立)，记录每个电机当前编码器值即为 `urdf_offset`。
