// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from logging_demo:srv/ConfigLogger.idl
// generated code does not contain a copyright notice

#ifndef LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__TRAITS_HPP_
#define LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "logging_demo/srv/detail/config_logger__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace logging_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const ConfigLogger_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: logger_name
  {
    out << "logger_name: ";
    rosidl_generator_traits::value_to_yaml(msg.logger_name, out);
    out << ", ";
  }

  // member: level
  {
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConfigLogger_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: logger_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "logger_name: ";
    rosidl_generator_traits::value_to_yaml(msg.logger_name, out);
    out << "\n";
  }

  // member: level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConfigLogger_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace logging_demo

namespace rosidl_generator_traits
{

[[deprecated("use logging_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const logging_demo::srv::ConfigLogger_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  logging_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use logging_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const logging_demo::srv::ConfigLogger_Request & msg)
{
  return logging_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<logging_demo::srv::ConfigLogger_Request>()
{
  return "logging_demo::srv::ConfigLogger_Request";
}

template<>
inline const char * name<logging_demo::srv::ConfigLogger_Request>()
{
  return "logging_demo/srv/ConfigLogger_Request";
}

template<>
struct has_fixed_size<logging_demo::srv::ConfigLogger_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<logging_demo::srv::ConfigLogger_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<logging_demo::srv::ConfigLogger_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace logging_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const ConfigLogger_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConfigLogger_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConfigLogger_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace logging_demo

namespace rosidl_generator_traits
{

[[deprecated("use logging_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const logging_demo::srv::ConfigLogger_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  logging_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use logging_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const logging_demo::srv::ConfigLogger_Response & msg)
{
  return logging_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<logging_demo::srv::ConfigLogger_Response>()
{
  return "logging_demo::srv::ConfigLogger_Response";
}

template<>
inline const char * name<logging_demo::srv::ConfigLogger_Response>()
{
  return "logging_demo/srv/ConfigLogger_Response";
}

template<>
struct has_fixed_size<logging_demo::srv::ConfigLogger_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<logging_demo::srv::ConfigLogger_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<logging_demo::srv::ConfigLogger_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<logging_demo::srv::ConfigLogger>()
{
  return "logging_demo::srv::ConfigLogger";
}

template<>
inline const char * name<logging_demo::srv::ConfigLogger>()
{
  return "logging_demo/srv/ConfigLogger";
}

template<>
struct has_fixed_size<logging_demo::srv::ConfigLogger>
  : std::integral_constant<
    bool,
    has_fixed_size<logging_demo::srv::ConfigLogger_Request>::value &&
    has_fixed_size<logging_demo::srv::ConfigLogger_Response>::value
  >
{
};

template<>
struct has_bounded_size<logging_demo::srv::ConfigLogger>
  : std::integral_constant<
    bool,
    has_bounded_size<logging_demo::srv::ConfigLogger_Request>::value &&
    has_bounded_size<logging_demo::srv::ConfigLogger_Response>::value
  >
{
};

template<>
struct is_service<logging_demo::srv::ConfigLogger>
  : std::true_type
{
};

template<>
struct is_service_request<logging_demo::srv::ConfigLogger_Request>
  : std::true_type
{
};

template<>
struct is_service_response<logging_demo::srv::ConfigLogger_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LOGGING_DEMO__SRV__DETAIL__CONFIG_LOGGER__TRAITS_HPP_
