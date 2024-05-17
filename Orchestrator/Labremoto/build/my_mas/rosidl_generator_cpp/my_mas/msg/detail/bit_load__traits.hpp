// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/BitLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__BIT_LOAD__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__BIT_LOAD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/bit_load__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const BitLoad & msg,
  std::ostream & out)
{
  out << "{";
  // member: path_bit
  {
    out << "path_bit: ";
    rosidl_generator_traits::value_to_yaml(msg.path_bit, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BitLoad & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path_bit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_bit: ";
    rosidl_generator_traits::value_to_yaml(msg.path_bit, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BitLoad & msg, bool use_flow_style = false)
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
  const my_mas::msg::BitLoad & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::BitLoad & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::BitLoad>()
{
  return "my_mas::msg::BitLoad";
}

template<>
inline const char * name<my_mas::msg::BitLoad>()
{
  return "my_mas/msg/BitLoad";
}

template<>
struct has_fixed_size<my_mas::msg::BitLoad>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::BitLoad>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::BitLoad>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__BIT_LOAD__TRAITS_HPP_
