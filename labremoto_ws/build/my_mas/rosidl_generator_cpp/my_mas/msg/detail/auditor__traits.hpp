// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:msg/Auditor.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__AUDITOR__TRAITS_HPP_
#define MY_MAS__MSG__DETAIL__AUDITOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/msg/detail/auditor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace msg
{

inline void to_flow_style_yaml(
  const Auditor & msg,
  std::ostream & out)
{
  out << "{";
  // member: idnode
  {
    out << "idnode: ";
    rosidl_generator_traits::value_to_yaml(msg.idnode, out);
    out << ", ";
  }

  // member: namenode
  {
    out << "namenode: ";
    rosidl_generator_traits::value_to_yaml(msg.namenode, out);
    out << ", ";
  }

  // member: tipotransaccion
  {
    out << "tipotransaccion: ";
    rosidl_generator_traits::value_to_yaml(msg.tipotransaccion, out);
    out << ", ";
  }

  // member: fechatransaccion
  {
    out << "fechatransaccion: ";
    rosidl_generator_traits::value_to_yaml(msg.fechatransaccion, out);
    out << ", ";
  }

  // member: iduser
  {
    out << "iduser: ";
    rosidl_generator_traits::value_to_yaml(msg.iduser, out);
    out << ", ";
  }

  // member: logproceso
  {
    out << "logproceso: ";
    rosidl_generator_traits::value_to_yaml(msg.logproceso, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Auditor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: idnode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "idnode: ";
    rosidl_generator_traits::value_to_yaml(msg.idnode, out);
    out << "\n";
  }

  // member: namenode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "namenode: ";
    rosidl_generator_traits::value_to_yaml(msg.namenode, out);
    out << "\n";
  }

  // member: tipotransaccion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tipotransaccion: ";
    rosidl_generator_traits::value_to_yaml(msg.tipotransaccion, out);
    out << "\n";
  }

  // member: fechatransaccion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fechatransaccion: ";
    rosidl_generator_traits::value_to_yaml(msg.fechatransaccion, out);
    out << "\n";
  }

  // member: iduser
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "iduser: ";
    rosidl_generator_traits::value_to_yaml(msg.iduser, out);
    out << "\n";
  }

  // member: logproceso
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "logproceso: ";
    rosidl_generator_traits::value_to_yaml(msg.logproceso, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Auditor & msg, bool use_flow_style = false)
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
  const my_mas::msg::Auditor & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::msg::Auditor & msg)
{
  return my_mas::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::msg::Auditor>()
{
  return "my_mas::msg::Auditor";
}

template<>
inline const char * name<my_mas::msg::Auditor>()
{
  return "my_mas/msg/Auditor";
}

template<>
struct has_fixed_size<my_mas::msg::Auditor>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::msg::Auditor>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::msg::Auditor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__MSG__DETAIL__AUDITOR__TRAITS_HPP_
