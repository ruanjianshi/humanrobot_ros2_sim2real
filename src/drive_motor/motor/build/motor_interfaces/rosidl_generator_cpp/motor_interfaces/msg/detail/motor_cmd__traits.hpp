// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motor_interfaces:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__TRAITS_HPP_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motor_interfaces/msg/detail/motor_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace motor_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_q
  {
    if (msg.target_q.size() == 0) {
      out << "target_q: []";
    } else {
      out << "target_q: [";
      size_t pending_items = msg.target_q.size();
      for (auto item : msg.target_q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_dq
  {
    if (msg.target_dq.size() == 0) {
      out << "target_dq: []";
    } else {
      out << "target_dq: [";
      size_t pending_items = msg.target_dq.size();
      for (auto item : msg.target_dq) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_tau
  {
    if (msg.target_tau.size() == 0) {
      out << "target_tau: []";
    } else {
      out << "target_tau: [";
      size_t pending_items = msg.target_tau.size();
      for (auto item : msg.target_tau) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_kp
  {
    if (msg.target_kp.size() == 0) {
      out << "target_kp: []";
    } else {
      out << "target_kp: [";
      size_t pending_items = msg.target_kp.size();
      for (auto item : msg.target_kp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_kd
  {
    if (msg.target_kd.size() == 0) {
      out << "target_kd: []";
    } else {
      out << "target_kd: [";
      size_t pending_items = msg.target_kd.size();
      for (auto item : msg.target_kd) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_q.size() == 0) {
      out << "target_q: []\n";
    } else {
      out << "target_q:\n";
      for (auto item : msg.target_q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: target_dq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_dq.size() == 0) {
      out << "target_dq: []\n";
    } else {
      out << "target_dq:\n";
      for (auto item : msg.target_dq) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: target_tau
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_tau.size() == 0) {
      out << "target_tau: []\n";
    } else {
      out << "target_tau:\n";
      for (auto item : msg.target_tau) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: target_kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_kp.size() == 0) {
      out << "target_kp: []\n";
    } else {
      out << "target_kp:\n";
      for (auto item : msg.target_kp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: target_kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_kd.size() == 0) {
      out << "target_kd: []\n";
    } else {
      out << "target_kd:\n";
      for (auto item : msg.target_kd) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCmd & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace motor_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use motor_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motor_interfaces::msg::MotorCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  motor_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motor_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const motor_interfaces::msg::MotorCmd & msg)
{
  return motor_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motor_interfaces::msg::MotorCmd>()
{
  return "motor_interfaces::msg::MotorCmd";
}

template<>
inline const char * name<motor_interfaces::msg::MotorCmd>()
{
  return "motor_interfaces/msg/MotorCmd";
}

template<>
struct has_fixed_size<motor_interfaces::msg::MotorCmd>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motor_interfaces::msg::MotorCmd>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motor_interfaces::msg::MotorCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_CMD__TRAITS_HPP_
