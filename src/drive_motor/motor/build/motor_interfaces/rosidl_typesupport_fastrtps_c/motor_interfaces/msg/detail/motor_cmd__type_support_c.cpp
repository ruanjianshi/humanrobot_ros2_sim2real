// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from motor_interfaces:msg/MotorCmd.idl
// generated code does not contain a copyright notice
#include "motor_interfaces/msg/detail/motor_cmd__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "motor_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "motor_interfaces/msg/detail/motor_cmd__struct.h"
#include "motor_interfaces/msg/detail/motor_cmd__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // target_dq, target_kd, target_kp, target_q, target_tau
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // target_dq, target_kd, target_kp, target_q, target_tau

// forward declare type support functions


using _MotorCmd__ros_msg_type = motor_interfaces__msg__MotorCmd;

static bool _MotorCmd__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorCmd__ros_msg_type * ros_message = static_cast<const _MotorCmd__ros_msg_type *>(untyped_ros_message);
  // Field name: target_q
  {
    size_t size = ros_message->target_q.size;
    auto array_ptr = ros_message->target_q.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_dq
  {
    size_t size = ros_message->target_dq.size;
    auto array_ptr = ros_message->target_dq.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_tau
  {
    size_t size = ros_message->target_tau.size;
    auto array_ptr = ros_message->target_tau.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_kp
  {
    size_t size = ros_message->target_kp.size;
    auto array_ptr = ros_message->target_kp.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_kd
  {
    size_t size = ros_message->target_kd.size;
    auto array_ptr = ros_message->target_kd.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MotorCmd__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorCmd__ros_msg_type * ros_message = static_cast<_MotorCmd__ros_msg_type *>(untyped_ros_message);
  // Field name: target_q
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_q.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->target_q);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->target_q, size)) {
      fprintf(stderr, "failed to create array for field 'target_q'");
      return false;
    }
    auto array_ptr = ros_message->target_q.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_dq
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_dq.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->target_dq);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->target_dq, size)) {
      fprintf(stderr, "failed to create array for field 'target_dq'");
      return false;
    }
    auto array_ptr = ros_message->target_dq.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_tau
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_tau.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->target_tau);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->target_tau, size)) {
      fprintf(stderr, "failed to create array for field 'target_tau'");
      return false;
    }
    auto array_ptr = ros_message->target_tau.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_kp
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_kp.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->target_kp);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->target_kp, size)) {
      fprintf(stderr, "failed to create array for field 'target_kp'");
      return false;
    }
    auto array_ptr = ros_message->target_kp.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_kd
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_kd.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->target_kd);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->target_kd, size)) {
      fprintf(stderr, "failed to create array for field 'target_kd'");
      return false;
    }
    auto array_ptr = ros_message->target_kd.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motor_interfaces
size_t get_serialized_size_motor_interfaces__msg__MotorCmd(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorCmd__ros_msg_type * ros_message = static_cast<const _MotorCmd__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name target_q
  {
    size_t array_size = ros_message->target_q.size;
    auto array_ptr = ros_message->target_q.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_dq
  {
    size_t array_size = ros_message->target_dq.size;
    auto array_ptr = ros_message->target_dq.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_tau
  {
    size_t array_size = ros_message->target_tau.size;
    auto array_ptr = ros_message->target_tau.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_kp
  {
    size_t array_size = ros_message->target_kp.size;
    auto array_ptr = ros_message->target_kp.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_kd
  {
    size_t array_size = ros_message->target_kd.size;
    auto array_ptr = ros_message->target_kd.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorCmd__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_motor_interfaces__msg__MotorCmd(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motor_interfaces
size_t max_serialized_size_motor_interfaces__msg__MotorCmd(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: target_q
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_dq
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_tau
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_kp
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_kd
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = motor_interfaces__msg__MotorCmd;
    is_plain =
      (
      offsetof(DataType, target_kd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MotorCmd__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_motor_interfaces__msg__MotorCmd(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MotorCmd = {
  "motor_interfaces::msg",
  "MotorCmd",
  _MotorCmd__cdr_serialize,
  _MotorCmd__cdr_deserialize,
  _MotorCmd__get_serialized_size,
  _MotorCmd__max_serialized_size
};

static rosidl_message_type_support_t _MotorCmd__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorCmd,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, motor_interfaces, msg, MotorCmd)() {
  return &_MotorCmd__type_support;
}

#if defined(__cplusplus)
}
#endif
