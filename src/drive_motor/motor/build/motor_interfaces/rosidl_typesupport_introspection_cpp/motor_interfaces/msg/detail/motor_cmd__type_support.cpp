// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from motor_interfaces:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "motor_interfaces/msg/detail/motor_cmd__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace motor_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorCmd_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) motor_interfaces::msg::MotorCmd(_init);
}

void MotorCmd_fini_function(void * message_memory)
{
  auto typed_message = static_cast<motor_interfaces::msg::MotorCmd *>(message_memory);
  typed_message->~MotorCmd();
}

size_t size_function__MotorCmd__target_q(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorCmd__target_q(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorCmd__target_q(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorCmd__target_q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorCmd__target_q(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorCmd__target_q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorCmd__target_q(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorCmd__target_q(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorCmd__target_dq(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorCmd__target_dq(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorCmd__target_dq(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorCmd__target_dq(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorCmd__target_dq(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorCmd__target_dq(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorCmd__target_dq(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorCmd__target_dq(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorCmd__target_tau(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorCmd__target_tau(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorCmd__target_tau(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorCmd__target_tau(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorCmd__target_tau(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorCmd__target_tau(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorCmd__target_tau(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorCmd__target_tau(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorCmd__target_kp(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorCmd__target_kp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorCmd__target_kp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorCmd__target_kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorCmd__target_kp(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorCmd__target_kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorCmd__target_kp(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorCmd__target_kp(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MotorCmd__target_kd(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorCmd__target_kd(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorCmd__target_kd(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorCmd__target_kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MotorCmd__target_kd(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MotorCmd__target_kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MotorCmd__target_kd(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MotorCmd__target_kd(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorCmd_message_member_array[5] = {
  {
    "target_q",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCmd, target_q),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorCmd__target_q,  // size() function pointer
    get_const_function__MotorCmd__target_q,  // get_const(index) function pointer
    get_function__MotorCmd__target_q,  // get(index) function pointer
    fetch_function__MotorCmd__target_q,  // fetch(index, &value) function pointer
    assign_function__MotorCmd__target_q,  // assign(index, value) function pointer
    resize_function__MotorCmd__target_q  // resize(index) function pointer
  },
  {
    "target_dq",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCmd, target_dq),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorCmd__target_dq,  // size() function pointer
    get_const_function__MotorCmd__target_dq,  // get_const(index) function pointer
    get_function__MotorCmd__target_dq,  // get(index) function pointer
    fetch_function__MotorCmd__target_dq,  // fetch(index, &value) function pointer
    assign_function__MotorCmd__target_dq,  // assign(index, value) function pointer
    resize_function__MotorCmd__target_dq  // resize(index) function pointer
  },
  {
    "target_tau",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCmd, target_tau),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorCmd__target_tau,  // size() function pointer
    get_const_function__MotorCmd__target_tau,  // get_const(index) function pointer
    get_function__MotorCmd__target_tau,  // get(index) function pointer
    fetch_function__MotorCmd__target_tau,  // fetch(index, &value) function pointer
    assign_function__MotorCmd__target_tau,  // assign(index, value) function pointer
    resize_function__MotorCmd__target_tau  // resize(index) function pointer
  },
  {
    "target_kp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCmd, target_kp),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorCmd__target_kp,  // size() function pointer
    get_const_function__MotorCmd__target_kp,  // get_const(index) function pointer
    get_function__MotorCmd__target_kp,  // get(index) function pointer
    fetch_function__MotorCmd__target_kp,  // fetch(index, &value) function pointer
    assign_function__MotorCmd__target_kp,  // assign(index, value) function pointer
    resize_function__MotorCmd__target_kp  // resize(index) function pointer
  },
  {
    "target_kd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCmd, target_kd),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorCmd__target_kd,  // size() function pointer
    get_const_function__MotorCmd__target_kd,  // get_const(index) function pointer
    get_function__MotorCmd__target_kd,  // get(index) function pointer
    fetch_function__MotorCmd__target_kd,  // fetch(index, &value) function pointer
    assign_function__MotorCmd__target_kd,  // assign(index, value) function pointer
    resize_function__MotorCmd__target_kd  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorCmd_message_members = {
  "motor_interfaces::msg",  // message namespace
  "MotorCmd",  // message name
  5,  // number of fields
  sizeof(motor_interfaces::msg::MotorCmd),
  MotorCmd_message_member_array,  // message members
  MotorCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorCmd_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorCmd_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorCmd_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace motor_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<motor_interfaces::msg::MotorCmd>()
{
  return &::motor_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorCmd_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, motor_interfaces, msg, MotorCmd)() {
  return &::motor_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorCmd_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
