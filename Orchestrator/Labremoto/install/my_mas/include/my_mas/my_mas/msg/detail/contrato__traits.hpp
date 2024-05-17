// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/Contrato.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CONTRATO__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__CONTRATO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/contrato__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const Contrato & msg,
  std::ostream & out)
{
  out << "{";
  // member: idcontrato
  {
    out << "idcontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.idcontrato, out);
    out << ", ";
  }

  // member: nombrecontrato
  {
    out << "nombrecontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.nombrecontrato, out);
    out << ", ";
  }

  // member: tipocontrato
  {
    out << "tipocontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.tipocontrato, out);
    out << ", ";
  }

  // member: desccontrato
  {
    out << "desccontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.desccontrato, out);
    out << ", ";
  }

  // member: especificacioncontrato
  {
    out << "especificacioncontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.especificacioncontrato, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Contrato & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: idcontrato
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "idcontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.idcontrato, out);
    out << "\n";
  }

  // member: nombrecontrato
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nombrecontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.nombrecontrato, out);
    out << "\n";
  }

  // member: tipocontrato
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tipocontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.tipocontrato, out);
    out << "\n";
  }

  // member: desccontrato
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desccontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.desccontrato, out);
    out << "\n";
  }

  // member: especificacioncontrato
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "especificacioncontrato: ";
    rosidl_generator_traits::value_to_yaml(msg.especificacioncontrato, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Contrato & msg, bool use_flow_style = false)
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
  const my_mas::msg::Contrato & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::Contrato & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::Contrato>()
{
  return "my_mas::msg::Contrato";
}

template<>
inline const char * name<my_mas::msg::Contrato>()
{
  return "my_mas/msg/Contrato";
}

template<>
struct has_fixed_size<my_mas::msg::Contrato>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::Contrato>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::Contrato>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__CONTRATO__TRAITS_HPP_
