# MotorState.msg — 电机反馈状态 (发布方: drive_motor, 频率: 500Hz)
#
# 数据为电机原始编码器值 (电机坐标系)，未经 urdf_offset / direction 变换。
# sim2real 会通过坐标变换将其转为机器人关节角度。

float32[] position       # N个电机的当前实际位置 (rad, 电机坐标系)
float32[] velocity       # N个电机的当前实际速度 (rad/s)
float32[] torque         # N个电机的当前实际力矩 (N·m / 电流推算)