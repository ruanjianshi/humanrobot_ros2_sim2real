// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motor_interfaces:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
// Member 'velocity'
// Member 'torque'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorState in the package motor_interfaces.
/**
  * MotorState.msg — 电机反馈状态 (发布方: drive_motor, 频率: 500Hz)
  *
  * 数据为电机原始编码器值 (电机坐标系)，未经 urdf_offset / direction 变换。
  * sim2real 会通过坐标变换将其转为机器人关节角度。
 */
typedef struct motor_interfaces__msg__MotorState
{
  /// N个电机的当前实际位置 (rad, 电机坐标系)
  rosidl_runtime_c__float__Sequence position;
  /// N个电机的当前实际速度 (rad/s)
  rosidl_runtime_c__float__Sequence velocity;
  /// N个电机的当前实际力矩 (N·m / 电流推算)
  rosidl_runtime_c__float__Sequence torque;
} motor_interfaces__msg__MotorState;

// Struct for a sequence of motor_interfaces__msg__MotorState.
typedef struct motor_interfaces__msg__MotorState__Sequence
{
  motor_interfaces__msg__MotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motor_interfaces__msg__MotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
