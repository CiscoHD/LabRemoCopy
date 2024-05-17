// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/FileHexLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/file_hex_load__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const FileHexLoad & msg,
  std::ostream & out)
{
  out << "{";
  // member: path_hex
  {
    out << "path_hex: ";
    rosidl_generator_traits::value_to_yaml(msg.path_hex, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FileHexLoad & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path_hex
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_hex: ";
    rosidl_generator_traits::value_to_yaml(msg.path_hex, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FileHexLoad & msg, bool use_flow_style = false)
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

}  // namespace my_mas

namespace rosidl_generator_traits
{

[[deprecated("use my_mas::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_mas::msg::FileHexLoad & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::FileHexLoad & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::FileHexLoad>()
{
  return "my_mas::msg::FileHexLoad";
}

template<>
inline const char * name<my_mas::msg::FileHexLoad>()
{
  return "my_mas/msg/FileHexLoad";
}

template<>
struct has_fixed_size<my_mas::msg::FileHexLoad>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::FileHexLoad>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::FileHexLoad>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__TRAITS_HPP_
