// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motor_interfaces:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__BUILDER_HPP_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motor_interfaces/msg/detail/motor_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motor_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorCmd_target_kd
{
public:
  explicit Init_MotorCmd_target_kd(::motor_interfaces::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  ::motor_interfaces::msg::MotorCmd target_kd(::motor_interfaces::msg::MotorCmd::_target_kd_type arg)
  {
    msg_.target_kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCmd msg_;
};

class Init_MotorCmd_target_kp
{
public:
  explicit Init_MotorCmd_target_kp(::motor_interfaces::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_target_kd target_kp(::motor_interfaces::msg::MotorCmd::_target_kp_type arg)
  {
    msg_.target_kp = std::move(arg);
    return Init_MotorCmd_target_kd(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCmd msg_;
};

class Init_MotorCmd_target_tau
{
public:
  explicit Init_MotorCmd_target_tau(::motor_interfaces::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_target_kp target_tau(::motor_interfaces::msg::MotorCmd::_target_tau_type arg)
  {
    msg_.target_tau = std::move(arg);
    return Init_MotorCmd_target_kp(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCmd msg_;
};

class Init_MotorCmd_target_dq
{
public:
  explicit Init_MotorCmd_target_dq(::motor_interfaces::msg::MotorCmd & msg)
  : msg_(msg)
  {}
  Init_MotorCmd_target_tau target_dq(::motor_interfaces::msg::MotorCmd::_target_dq_type arg)
  {
    msg_.target_dq = std::move(arg);
    return Init_MotorCmd_target_tau(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCmd msg_;
};

class Init_MotorCmd_target_q
{
public:
  Init_MotorCmd_target_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCmd_target_dq target_q(::motor_interfaces::msg::MotorCmd::_target_q_type arg)
  {
    msg_.target_q = std::move(arg);
    return Init_MotorCmd_target_dq(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motor_interfaces::msg::MotorCmd>()
{
  return motor_interfaces::msg::builder::Init_MotorCmd_target_q();
}

}  // namespace motor_interfaces

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__BUILDER_HPP_
