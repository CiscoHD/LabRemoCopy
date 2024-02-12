// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_msgs:srv/GetPointMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_MSGS__SRV__DETAIL__GET_POINT_MAP__TRAITS_HPP_
#define MAP_MSGS__SRV__DETAIL__GET_POINT_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_msgs/srv/detail/get_point_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPointMap_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPointMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPointMap_Request & msg, bool use_flow_style = false)
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

}  // namespace map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const map_msgs::srv::GetPointMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const map_msgs::srv::GetPointMap_Request & msg)
{
  return map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<map_msgs::srv::GetPointMap_Request>()
{
  return "map_msgs::srv::GetPointMap_Request";
}

template<>
inline const char * name<map_msgs::srv::GetPointMap_Request>()
{
  return "map_msgs/srv/GetPointMap_Request";
}

template<>
struct has_fixed_size<map_msgs::srv::GetPointMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<map_msgs::srv::GetPointMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<map_msgs::srv::GetPointMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'map'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"

namespace map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPointMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: map
  {
    out << "map: ";
    to_flow_style_yaml(msg.map, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPointMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map:\n";
    to_block_style_yaml(msg.map, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPointMap_Response & msg, bool use_flow_style = false)
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

}  // namespace map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const map_msgs::srv::GetPointMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const map_msgs::srv::GetPointMap_Response & msg)
{
  return map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<map_msgs::srv::GetPointMap_Response>()
{
  return "map_msgs::srv::GetPointMap_Response";
}

template<>
inline const char * name<map_msgs::srv::GetPointMap_Response>()
{
  return "map_msgs/srv/GetPointMap_Response";
}

template<>
struct has_fixed_size<map_msgs::srv::GetPointMap_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct has_bounded_size<map_msgs::srv::GetPointMap_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct is_message<map_msgs::srv::GetPointMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<map_msgs::srv::GetPointMap>()
{
  return "map_msgs::srv::GetPointMap";
}

template<>
inline const char * name<map_msgs::srv::GetPointMap>()
{
  return "map_msgs/srv/GetPointMap";
}

template<>
struct has_fixed_size<map_msgs::srv::GetPointMap>
  : std::integral_constant<
    bool,
    has_fixed_size<map_msgs::srv::GetPointMap_Request>::value &&
    has_fixed_size<map_msgs::srv::GetPointMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<map_msgs::srv::GetPointMap>
  : std::integral_constant<
    bool,
    has_bounded_size<map_msgs::srv::GetPointMap_Request>::value &&
    has_bounded_size<map_msgs::srv::GetPointMap_Response>::value
  >
{
};

template<>
struct is_service<map_msgs::srv::GetPointMap>
  : std::true_type
{
};

template<>
struct is_service_request<map_msgs::srv::GetPointMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<map_msgs::srv::GetPointMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MAP_MSGS__SRV__DETAIL__GET_POINT_MAP__TRAITS_HPP_
