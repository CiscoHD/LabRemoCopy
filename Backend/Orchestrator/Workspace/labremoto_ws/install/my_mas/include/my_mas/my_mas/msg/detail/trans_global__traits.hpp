// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/TransGlobal.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_GLOBAL__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__TRANS_GLOBAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/trans_global__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const TransGlobal & msg,
  std::ostream & out)
{
  out << "{";
  // member: resultado
  {
    out << "resultado: ";
    rosidl_generator_traits::value_to_yaml(msg.resultado, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: name_node
  {
    out << "name_node: ";
    rosidl_generator_traits::value_to_yaml(msg.name_node, out);
    out << ", ";
  }

  // member: fecha
  {
    out << "fecha: ";
    rosidl_generator_traits::value_to_yaml(msg.fecha, out);
    out << ", ";
  }

  // member: folio
  {
    out << "folio: ";
    rosidl_generator_traits::value_to_yaml(msg.folio, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TransGlobal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: resultado
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resultado: ";
    rosidl_generator_traits::value_to_yaml(msg.resultado, out);
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

  // member: name_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name_node: ";
    rosidl_generator_traits::value_to_yaml(msg.name_node, out);
    out << "\n";
  }

  // member: fecha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fecha: ";
    rosidl_generator_traits::value_to_yaml(msg.fecha, out);
    out << "\n";
  }

  // member: folio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "folio: ";
    rosidl_generator_traits::value_to_yaml(msg.folio, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TransGlobal & msg, bool use_flow_style = false)
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
  const my_mas::msg::TransGlobal & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::TransGlobal & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::TransGlobal>()
{
  return "my_mas::msg::TransGlobal";
}

template<>
inline const char * name<my_mas::msg::TransGlobal>()
{
  return "my_mas/msg/TransGlobal";
}

template<>
struct has_fixed_size<my_mas::msg::TransGlobal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::TransGlobal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::TransGlobal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__TRANS_GLOBAL__TRAITS_HPP_
