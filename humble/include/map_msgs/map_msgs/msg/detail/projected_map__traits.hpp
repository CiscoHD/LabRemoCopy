// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_msgs:msg/ProjectedMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__TRAITS_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_msgs/msg/detail/projected_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'map'
#include "nav_msgs/msg/detail/occupancy_grid__traits.hpp"

namespace map_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProjectedMap & msg,
  std::ostream & out)
{
  out << "{";
  // member: map
  {
    out << "map: ";
    to_flow_style_yaml(msg.map, out);
    out << ", ";
  }

  // member: min_z
  {
    out << "min_z: ";
    rosidl_generator_traits::value_to_yaml(msg.min_z, out);
    out << ", ";
  }

  // member: max_z
  {
    out << "max_z: ";
    rosidl_generator_traits::value_to_yaml(msg.max_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProjectedMap & msg,
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

  // member: min_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_z: ";
    rosidl_generator_traits::value_to_yaml(msg.min_z, out);
    out << "\n";
  }

  // member: max_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_z: ";
    rosidl_generator_traits::value_to_yaml(msg.max_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProjectedMap & msg, bool use_flow_style = false)
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

}  // namespace map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use map_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const map_msgs::msg::ProjectedMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_msgs::msg::ProjectedMap & msg)
{
  return map_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_msgs::msg::ProjectedMap>()
{
  return "map_msgs::msg::ProjectedMap";
}

template<>
inline const char * name<map_msgs::msg::ProjectedMap>()
{
  return "map_msgs/msg/ProjectedMap";
}

template<>
struct has_fixed_size<map_msgs::msg::ProjectedMap>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::OccupancyGrid>::value> {};

template<>
struct has_bounded_size<map_msgs::msg::ProjectedMap>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::OccupancyGrid>::value> {};

template<>
struct is_message<map_msgs::msg::ProjectedMap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__TRAITS_HPP_
