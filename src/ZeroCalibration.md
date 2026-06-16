
```
电机编码器零点: 电机出厂时定义的机械零点
机器人关节零点: RL 策略训练时定义的默认站立姿态 (q=0)

两者之间存在偏移:
  robot_q = motor_q × direction - urdf_offset
          
其中:
  motor_q    = 电机编码器当前值 (硬件读出)
  robot_q    = 机器人关节位置 (策略使用的值)
  direction  = ±1 (旋转方向, 见第4节)
  urdf_offset= 零点偏移 (本节标定)
```

**目标**: 当机器人处于 RL 训练的默认站立姿态时，策略观测到的 `robot_q = 0`。

### 标定步骤

```
步骤1: 准备工作
  ├─ 确保电机 ID 已正确设置 (第2节)
  ├─ 搭建标定支架 (让机器人保持站立姿态)
  └─ 准备 spread-sheet 记录软件 (Excel/Google Sheets)

步骤2: 定义默认站立姿态
  在仿真中确定训练使用的默认关节角度。例如:
  l_hip_pitch  = 0.0         r_hip_pitch  = 0.0
  l_hip_roll   = 0.0         r_hip_roll   = 0.0
  l_thigh      = -0.25       r_thigh      = -0.25
  l_calf       = 0.65        r_calf       = 0.65
  l_ankle_pitch = -0.40      r_ankle_pitch = -0.40
  l_ankle_roll  = 0.0        r_ankle_roll  = 0.0

步骤3: 物理摆位
  ├─ 手动将每个关节摆到上述角度
  ├─ 使用水平尺/量角器辅助校准
  ├─ 用支架固定身体保持直立
  └─ 双脚底与地面平行

步骤4: 上电读取编码器值
  └─ 运行标定脚本 → 记录每个电机的当前位置

步骤5: 计算 urdf_offset
  ├─ urdf_offset[i] = motor_q[i] × direction[i]   (因为 robot_q=0)
  └─ 填入 pd_config.yaml

步骤6: 验证
  └─ 设置 offset 后重新上电 → 读取 robot_q → 应全为 0
```


##  电机旋转方向标定 (direction)


```
direction = +1: 电机正转 → 关节位置增大 (RL 策略的正方向)
direction = -1: 电机正转 → 关节位置减小 (需要翻转)
```

## 验证清单

```bash
□ 电机 ID 全部唯一且连续 (CAN 扫描通过)
□ direction 逐个电机测试 (小角度正转, 编码器增大=+1)
□ urdf_offset 标定 (摆默认姿态, 读取编码器, 填入配置)
□ robot_q 验证 (标定后读取 robot_q, 全部 < 0.05 rad)
□ PD 增益初始值 (kp=40~80, kd=0.5~1.5, 从低起步)
□ 关节限位设置 (机械限位×0.8 作为软件限位)
□ 全部上电后无异常发热/噪音
□ 零力矩模式测试 (kp=kd=0, 机器人松软可手推动)
□ 硬直模式测试 (kp=80, kd=1.5, 机器人在默认姿态站稳)
```

## 将标定结果写入配置文件

### 填入 pd_config.yaml

```yaml
# pd_config.yaml
dofs: 12

joint_names:
  - l_hip_pitch, l_hip_roll, l_thigh, l_calf, l_ankle_pitch, l_ankle_roll
  - r_hip_pitch, r_hip_roll, r_thigh, r_calf, r_ankle_pitch, r_ankle_roll

# ID 映射: joint_names[0] → CAN ID 5
map_index: [5, 4, 3, 2, 1, 0, 11, 10, 9, 8, 7, 6]

# ─── 以下为标定结果 ───

# 方向标定 (±1)
direction: [1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, -1]

# 零点偏移 (默认站立姿态的电机编码器值)
urdf_offset: [0.52, -0.03, 1.85, 2.30, -0.15, 0.01,
              0.48, 0.02, 1.90, 2.28, -0.12, -0.01]

# PD 增益
kp: [80, 80, 80, 80, 60, 60, 80, 80, 80, 80, 60, 60]
kd: [1.5, 1.5, 1.5, 1.5, 1.0, 1.0, 1.5, 1.5, 1.5, 1.5, 1.0, 1.0]

# 策略融合 PD 增益 (行走时用)
p_kp: [60, 60, 60, 60, 40, 40, 60, 60, 60, 60, 40, 40]
p_kd: [1.0, 1.0, 1.0, 1.0, 0.8, 0.8, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8]

# 关节限位
lower: [-1.57, -0.79, -2.09, -0.87, -0.87, -0.52,
        -1.57, -0.79, -2.09, -0.87, -0.87, -0.52]
upper: [ 1.57,  0.79,  1.57,  2.09,  0.87,  0.52,
         1.57,  0.79,  1.57,  2.09,  0.87,  0.52]
```

### 填入 robot_param.yaml (电机拓扑)

```yaml
# robot_param.yaml - 驱动电机包用的硬件拓扑
SDK_version: 1
serial:
  port: "/dev/motor"
  baudrate: 4000000

can_bus:
  - can_id: 1                          # CAN口1
    motors:
      - name: "l_ankle_roll"           # 电机ID=1
        id: 1
        model: "your_motor_model"
      - name: "l_ankle_pitch"         # 电机ID=2
        id: 2
        model: "your_motor_model"
      - name: "l_calf"                # 电机ID=3
        id: 3
        model: "your_motor_model"
      - name: "l_thigh"               # 电机ID=4
        id: 4
        model: "your_motor_model"
      - name: "l_hip_roll"           # 电机ID=5
        id: 5
        model: "your_motor_model"
      - name: "l_hip_pitch"          # 电机ID=6
        id: 6
        model: "your_motor_model"
      - name: "r_ankle_roll"         # 电机ID=7
        id: 7
        model: "your_motor_model"
      - name: "r_ankle_pitch"        # 电机ID=8
        id: 8
        model: "your_motor_model"
      - name: "r_calf"               # 电机ID=9
        id: 9
        model: "your_motor_model"
      - name: "r_thigh"              # 电机ID=10
        id: 10
        model: "your_motor_model"
      - name: "r_hip_roll"           # 电机ID=11
        id: 11
        model: "your_motor_model"
      - name: "r_hip_pitch"          # 电机ID=12
        id: 12
        model: "your_motor_model"
```

---