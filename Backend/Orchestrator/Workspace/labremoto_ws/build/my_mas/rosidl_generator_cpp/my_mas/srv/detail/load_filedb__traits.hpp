// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_mas:srv/LoadFiledb.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILEDB__TRAITS_HPP_
#define MY_MAS__SRV__DETAIL__LOAD_FILEDB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_mas/srv/detail/load_filedb__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_mas
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadFiledb_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id_node
  {
    out << "id_node: ";
    rosidl_generator_traits::value_to_yaml(msg.id_node, out);
    out << ", ";
  }

  // member: name_node
  {
    out << "name_node: ";
    rosidl_generator_traits::value_to_yaml(msg.name_node, out);
    out << ", ";
  }

  // member: type_transaction
  {
    out << "type_transaction: ";
    rosidl_generator_traits::value_to_yaml(msg.type_transaction, out);
    out << ", ";
  }

  // member: date_process
  {
    out << "date_process: ";
    rosidl_generator_traits::value_to_yaml(msg.date_process, out);
    out << ", ";
  }

  // member: id_user
  {
    out << "id_user: ";
    rosidl_generator_traits::value_to_yaml(msg.id_user, out);
    out << ", ";
  }

  // member: log_process
  {
    out << "log_process: ";
    rosidl_generator_traits::value_to_yaml(msg.log_process, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LoadFiledb_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id_node: ";
    rosidl_generator_traits::value_to_yaml(msg.id_node, out);
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

  // member: type_transaction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_transaction: ";
    rosidl_generator_traits::value_to_yaml(msg.type_transaction, out);
    out << "\n";
  }

  // member: date_process
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "date_process: ";
    rosidl_generator_traits::value_to_yaml(msg.date_process, out);
    out << "\n";
  }

  // member: id_user
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id_user: ";
    rosidl_generator_traits::value_to_yaml(msg.id_user, out);
    out << "\n";
  }

  // member: log_process
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "log_process: ";
    rosidl_generator_traits::value_to_yaml(msg.log_process, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LoadFiledb_Request & msg, bool use_flow_style = false)
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

}  // namespace my_mas

namespace rosidl_generator_traits
{

[[deprecated("use my_mas::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_mas::srv::LoadFiledb_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::srv::LoadFiledb_Request & msg)
{
  return my_mas::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::srv::LoadFiledb_Request>()
{
  return "my_mas::srv::LoadFiledb_Request";
}

template<>
inline const char * name<my_mas::srv::LoadFiledb_Request>()
{
  return "my_mas/srv/LoadFiledb_Request";
}

template<>
struct has_fixed_size<my_mas::srv::LoadFiledb_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::srv::LoadFiledb_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::srv::LoadFiledb_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_mas
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadFiledb_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LoadFiledb_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const LoadFiledb_Response & msg, bool use_flow_style = false)
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

}  // namespace my_mas

namespace rosidl_generator_traits
{

[[deprecated("use my_mas::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_mas::srv::LoadFiledb_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_mas::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_mas::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_mas::srv::LoadFiledb_Response & msg)
{
  return my_mas::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_mas::srv::LoadFiledb_Response>()
{
  return "my_mas::srv::LoadFiledb_Response";
}

template<>
inline const char * name<my_mas::srv::LoadFiledb_Response>()
{
  return "my_mas/srv/LoadFiledb_Response";
}

template<>
struct has_fixed_size<my_mas::srv::LoadFiledb_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_mas::srv::LoadFiledb_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_mas::srv::LoadFiledb_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_mas::srv::LoadFiledb>()
{
  return "my_mas::srv::LoadFiledb";
}

template<>
inline const char * name<my_mas::srv::LoadFiledb>()
{
  return "my_mas/srv/LoadFiledb";
}

template<>
struct has_fixed_size<my_mas::srv::LoadFiledb>
  : std::integral_constant<
    bool,
    has_fixed_size<my_mas::srv::LoadFiledb_Request>::value &&
    has_fixed_size<my_mas::srv::LoadFiledb_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_mas::srv::LoadFiledb>
  : std::integral_constant<
    bool,
    has_bounded_size<my_mas::srv::LoadFiledb_Request>::value &&
    has_bounded_size<my_mas::srv::LoadFiledb_Response>::value
  >
{
};

template<>
struct is_service<my_mas::srv::LoadFiledb>
  : std::true_type
{
};

template<>
struct is_service_request<my_mas::srv::LoadFiledb_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_mas::srv::LoadFiledb_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILEDB__TRAITS_HPP_
