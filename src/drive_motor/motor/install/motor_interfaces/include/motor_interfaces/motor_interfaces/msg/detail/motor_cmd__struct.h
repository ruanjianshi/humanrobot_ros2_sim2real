// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motor_interfaces:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_q'
// Member 'target_dq'
// Member 'target_tau'
// Member 'target_kp'
// Member 'target_kd'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorCmd in the package motor_interfaces.
/**
  * MotorCmd.msg — 电机控制指令 (发布方: sim2real, 订阅方: drive_motor, 频率: 500Hz)
  *
  * 数据已经是电机坐标系下的目标值 (sim2real 已做逆变换)。
  * drive_motor 直接转发到电机硬件。
 */
typedef struct motor_interfaces__msg__MotorCmd
{
  /// N个电机的目标位置 (rad, 电机坐标系)
  rosidl_runtime_c__float__Sequence target_q;
  /// N个电机的目标速度 (rad/s)
  rosidl_runtime_c__float__Sequence target_dq;
  /// N个电机的目标力矩 (N·m)
  rosidl_runtime_c__float__Sequence target_tau;
  /// N个电机的 PD 比例增益
  rosidl_runtime_c__float__Sequence target_kp;
  /// N个电机的 PD 微分增益
  rosidl_runtime_c__float__Sequence target_kd;
} motor_interfaces__msg__MotorCmd;

// Struct for a sequence of motor_interfaces__msg__MotorCmd.
typedef struct motor_interfaces__msg__MotorCmd__Sequence
{
  motor_interfaces__msg__MotorCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motor_interfaces__msg__MotorCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
