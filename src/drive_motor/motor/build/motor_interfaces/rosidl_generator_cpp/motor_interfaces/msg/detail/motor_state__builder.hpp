// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motor_interfaces:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motor_interfaces/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motor_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorState_torque
{
public:
  explicit Init_MotorState_torque(::motor_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::motor_interfaces::msg::MotorState torque(::motor_interfaces::msg::MotorState::_torque_type arg)
  {
    msg_.torque = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motor_interfaces::msg::MotorState msg_;
};

class Init_MotorState_velocity
{
public:
  explicit Init_MotorState_velocity(::motor_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_torque velocity(::motor_interfaces::msg::MotorState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_MotorState_torque(msg_);
  }

private:
  ::motor_interfaces::msg::MotorState msg_;
};

class Init_MotorState_position
{
public:
  Init_MotorState_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_velocity position(::motor_interfaces::msg::MotorState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MotorState_velocity(msg_);
  }

private:
  ::motor_interfaces::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motor_interfaces::msg::MotorState>()
{
  return motor_interfaces::msg::builder::Init_MotorState_position();
}

}  // namespace motor_interfaces

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
