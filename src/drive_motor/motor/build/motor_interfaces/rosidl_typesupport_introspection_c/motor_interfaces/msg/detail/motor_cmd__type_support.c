// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motor_interfaces:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motor_interfaces/msg/detail/motor_cmd__rosidl_typesupport_introspection_c.h"
#include "motor_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motor_interfaces/msg/detail/motor_cmd__functions.h"
#include "motor_interfaces/msg/detail/motor_cmd__struct.h"


// Include directives for member types
// Member `target_q`
// Member `target_dq`
// Member `target_tau`
// Member `target_kp`
// Member `target_kd`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motor_interfaces__msg__MotorCmd__init(message_memory);
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_fini_function(void * message_memory)
{
  motor_interfaces__msg__MotorCmd__fini(message_memory);
}

size_t motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_q(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_q(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_q(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_q(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_q(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_q(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_dq(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_dq(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_dq(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_dq(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_dq(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_dq(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_dq(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_dq(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_tau(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_tau(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_tau(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_tau(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_tau(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_tau(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_tau(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_tau(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_kp(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_kp(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_kp(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_kp(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_kp(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_kp(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_kd(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_kd(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_kd(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_kd(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_kd(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_kd(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_member_array[5] = {
  {
    "target_q",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorCmd, target_q),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_q,  // size() function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_q,  // get_const(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_q,  // get(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_q,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_q,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_q  // resize(index) function pointer
  },
  {
    "target_dq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorCmd, target_dq),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_dq,  // size() function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_dq,  // get_const(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_dq,  // get(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_dq,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_dq,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_dq  // resize(index) function pointer
  },
  {
    "target_tau",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorCmd, target_tau),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_tau,  // size() function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_tau,  // get_const(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_tau,  // get(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_tau,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_tau,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_tau  // resize(index) function pointer
  },
  {
    "target_kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorCmd, target_kp),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_kp,  // size() function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_kp,  // get_const(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_kp,  // get(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_kp,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_kp,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_kp  // resize(index) function pointer
  },
  {
    "target_kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorCmd, target_kd),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__size_function__MotorCmd__target_kd,  // size() function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_const_function__MotorCmd__target_kd,  // get_const(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__get_function__MotorCmd__target_kd,  // get(index) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__fetch_function__MotorCmd__target_kd,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__assign_function__MotorCmd__target_kd,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__resize_function__MotorCmd__target_kd  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_members = {
  "motor_interfaces__msg",  // message namespace
  "MotorCmd",  // message name
  5,  // number of fields
  sizeof(motor_interfaces__msg__MotorCmd),
  motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_member_array,  // message members
  motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle = {
  0,
  &motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motor_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motor_interfaces, msg, MotorCmd)() {
  if (!motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle.typesupport_identifier) {
    motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &motor_interfaces__msg__MotorCmd__rosidl_typesupport_introspection_c__MotorCmd_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
