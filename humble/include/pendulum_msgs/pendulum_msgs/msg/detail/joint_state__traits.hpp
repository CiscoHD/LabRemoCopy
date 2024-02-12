// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pendulum_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

#ifndef PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pendulum_msgs/msg/detail/joint_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pendulum_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointState & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: effort
  {
    out << "effort: ";
    rosidl_generator_traits::value_to_yaml(msg.effort, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }

  // member: effort
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "effort: ";
    rosidl_generator_traits::value_to_yaml(msg.effort, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointState & msg, bool use_flow_style = false)
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

}  // namespace pendulum_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pendulum_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pendulum_msgs::msg::JointState & msg,
  std::ostream & out, size_t indentation = 0)
{
  pendulum_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pendulum_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pendulum_msgs::msg::JointState & msg)
{
  return pendulum_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pendulum_msgs::msg::JointState>()
{
  return "pendulum_msgs::msg::JointState";
}

template<>
inline const char * name<pendulum_msgs::msg::JointState>()
{
  return "pendulum_msgs/msg/JointState";
}

template<>
struct has_fixed_size<pendulum_msgs::msg::JointState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pendulum_msgs::msg::JointState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pendulum_msgs::msg::JointState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_
