// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pendulum_msgs:msg/RttestResults.idl
// generated code does not contain a copyright notice

#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__TRAITS_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pendulum_msgs/msg/detail/rttest_results__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'command'
#include "pendulum_msgs/msg/detail/joint_command__traits.hpp"
// Member 'state'
#include "pendulum_msgs/msg/detail/joint_state__traits.hpp"

namespace pendulum_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RttestResults & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: command
  {
    out << "command: ";
    to_flow_style_yaml(msg.command, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
    out << ", ";
  }

  // member: cur_latency
  {
    out << "cur_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_latency, out);
    out << ", ";
  }

  // member: mean_latency
  {
    out << "mean_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_latency, out);
    out << ", ";
  }

  // member: min_latency
  {
    out << "min_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.min_latency, out);
    out << ", ";
  }

  // member: max_latency
  {
    out << "max_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.max_latency, out);
    out << ", ";
  }

  // member: minor_pagefaults
  {
    out << "minor_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.minor_pagefaults, out);
    out << ", ";
  }

  // member: major_pagefaults
  {
    out << "major_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.major_pagefaults, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RttestResults & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command:\n";
    to_block_style_yaml(msg.command, out, indentation + 2);
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }

  // member: cur_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cur_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_latency, out);
    out << "\n";
  }

  // member: mean_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_latency, out);
    out << "\n";
  }

  // member: min_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.min_latency, out);
    out << "\n";
  }

  // member: max_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.max_latency, out);
    out << "\n";
  }

  // member: minor_pagefaults
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "minor_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.minor_pagefaults, out);
    out << "\n";
  }

  // member: major_pagefaults
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "major_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.major_pagefaults, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RttestResults & msg, bool use_flow_style = false)
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
  const pendulum_msgs::msg::RttestResults & msg,
  std::ostream & out, size_t indentation = 0)
{
  pendulum_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pendulum_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pendulum_msgs::msg::RttestResults & msg)
{
  return pendulum_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pendulum_msgs::msg::RttestResults>()
{
  return "pendulum_msgs::msg::RttestResults";
}

template<>
inline const char * name<pendulum_msgs::msg::RttestResults>()
{
  return "pendulum_msgs/msg/RttestResults";
}

template<>
struct has_fixed_size<pendulum_msgs::msg::RttestResults>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<pendulum_msgs::msg::JointCommand>::value && has_fixed_size<pendulum_msgs::msg::JointState>::value> {};

template<>
struct has_bounded_size<pendulum_msgs::msg::RttestResults>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<pendulum_msgs::msg::JointCommand>::value && has_bounded_size<pendulum_msgs::msg::JointState>::value> {};

template<>
struct is_message<pendulum_msgs::msg::RttestResults>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__TRAITS_HPP_
