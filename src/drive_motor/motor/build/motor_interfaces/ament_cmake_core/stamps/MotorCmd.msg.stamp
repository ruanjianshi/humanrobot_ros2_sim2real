# MotorCmd.msg — 电机控制指令 (发布方: sim2real, 订阅方: drive_motor, 频率: 500Hz)
#
# 数据已经是电机坐标系下的目标值 (sim2real 已做逆变换)。
# drive_motor 直接转发到电机硬件。

float32[] target_q       # N个电机的目标位置 (rad, 电机坐标系)
float32[] target_dq      # N个电机的目标速度 (rad/s)
float32[] target_tau     # N个电机的目标力矩 (N·m)
float32[] target_kp      # N个电机的 PD 比例增益
float32[] target_kd      # N个电机的 PD 微分增益