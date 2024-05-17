// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/Operacion.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__OPERACION__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__OPERACION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/operacion__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const Operacion & msg,
  std::ostream & out)
{
  out << "{";
  // member: nameoperacion
  {
    out << "nameoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.nameoperacion, out);
    out << ", ";
  }

  // member: descoperacion
  {
    out << "descoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.descoperacion, out);
    out << ", ";
  }

  // member: estatusoperacion
  {
    out << "estatusoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.estatusoperacion, out);
    out << ", ";
  }

  // member: fechaoperacion
  {
    out << "fechaoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.fechaoperacion, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operacion & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nameoperacion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nameoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.nameoperacion, out);
    out << "\n";
  }

  // member: descoperacion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "descoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.descoperacion, out);
    out << "\n";
  }

  // member: estatusoperacion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estatusoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.estatusoperacion, out);
    out << "\n";
  }

  // member: fechaoperacion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fechaoperacion: ";
    rosidl_generator_traits::value_to_yaml(msg.fechaoperacion, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operacion & msg, bool use_flow_style = false)
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
  const my_mas::msg::Operacion & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::Operacion & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::Operacion>()
{
  return "my_mas::msg::Operacion";
}

template<>
inline const char * name<my_mas::msg::Operacion>()
{
  return "my_mas/msg/Operacion";
}

template<>
struct has_fixed_size<my_mas::msg::Operacion>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::Operacion>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::Operacion>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__OPERACION__TRAITS_HPP_
