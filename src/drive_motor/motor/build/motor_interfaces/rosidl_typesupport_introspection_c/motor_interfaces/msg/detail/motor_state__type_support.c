// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motor_interfaces:msg/MotorState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motor_interfaces/msg/detail/motor_state__rosidl_typesupport_introspection_c.h"
#include "motor_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motor_interfaces/msg/detail/motor_state__functions.h"
#include "motor_interfaces/msg/detail/motor_state__struct.h"


// Include directives for member types
// Member `position`
// Member `velocity`
// Member `torque`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motor_interfaces__msg__MotorState__init(message_memory);
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_fini_function(void * message_memory)
{
  motor_interfaces__msg__MotorState__fini(message_memory);
}

size_t motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__position(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__resize_function__MotorState__position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__velocity(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__velocity(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__velocity(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__resize_function__MotorState__velocity(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__torque(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__torque(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__torque(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__torque(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__torque(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__torque(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__torque(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__resize_function__MotorState__torque(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_member_array[3] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorState, position),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__position,  // size() function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__position,  // get_const(index) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__position,  // get(index) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__position,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__position,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__resize_function__MotorState__position  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorState, velocity),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__velocity,  // size() function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__velocity,  // get_const(index) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__velocity,  // get(index) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__velocity,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__velocity,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__resize_function__MotorState__velocity  // resize(index) function pointer
  },
  {
    "torque",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces__msg__MotorState, torque),  // bytes offset in struct
    NULL,  // default value
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__torque,  // size() function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__torque,  // get_const(index) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__torque,  // get(index) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__torque,  // fetch(index, &value) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__torque,  // assign(index, value) function pointer
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__resize_function__MotorState__torque  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_members = {
  "motor_interfaces__msg",  // message namespace
  "MotorState",  // message name
  3,  // number of fields
  sizeof(motor_interfaces__msg__MotorState),
  motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_member_array,  // message members
  motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle = {
  0,
  &motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motor_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motor_interfaces, msg, MotorState)() {
  if (!motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle.typesupport_identifier) {
    motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &motor_interfaces__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
