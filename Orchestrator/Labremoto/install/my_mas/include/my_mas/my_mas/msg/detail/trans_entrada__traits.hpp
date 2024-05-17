// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/TransEntrada.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_ENTRADA__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__TRANS_ENTRADA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/trans_entrada__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const TransEntrada & msg,
  std::ostream & out)
{
  out << "{";
  // member: tipotransaccion
  {
    out << "tipotransaccion: ";
    rosidl_generator_traits::value_to_yaml(msg.tipotransaccion, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: idestudiante
  {
    out << "idestudiante: ";
    rosidl_generator_traits::value_to_yaml(msg.idestudiante, out);
    out << ", ";
  }

  // member: idsesion
  {
    out << "idsesion: ";
    rosidl_generator_traits::value_to_yaml(msg.idsesion, out);
    out << ", ";
  }

  // member: descripcion
  {
    out << "descripcion: ";
    rosidl_generator_traits::value_to_yaml(msg.descripcion, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TransEntrada & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tipotransaccion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tipotransaccion: ";
    rosidl_generator_traits::value_to_yaml(msg.tipotransaccion, out);
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

  // member: idestudiante
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "idestudiante: ";
    rosidl_generator_traits::value_to_yaml(msg.idestudiante, out);
    out << "\n";
  }

  // member: idsesion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "idsesion: ";
    rosidl_generator_traits::value_to_yaml(msg.idsesion, out);
    out << "\n";
  }

  // member: descripcion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "descripcion: ";
    rosidl_generator_traits::value_to_yaml(msg.descripcion, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TransEntrada & msg, bool use_flow_style = false)
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
  const my_mas::msg::TransEntrada & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::TransEntrada & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::TransEntrada>()
{
  return "my_mas::msg::TransEntrada";
}

template<>
inline const char * name<my_mas::msg::TransEntrada>()
{
  return "my_mas/msg/TransEntrada";
}

template<>
struct has_fixed_size<my_mas::msg::TransEntrada>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::TransEntrada>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::TransEntrada>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__TRANS_ENTRADA__TRAITS_HPP_
