// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_msgs:msg/ProjectedMapInfo.idl
// generated code does not contain a copyright notice

#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__TRAITS_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_msgs/msg/detail/projected_map_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace map_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProjectedMapInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
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
  const ProjectedMapInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
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

inline std::string to_yaml(const ProjectedMapInfo & msg, bool use_flow_style = false)
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
  const map_msgs::msg::ProjectedMapInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_msgs::msg::ProjectedMapInfo & msg)
{
  return map_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_msgs::msg::ProjectedMapInfo>()
{
  return "map_msgs::msg::ProjectedMapInfo";
}

template<>
inline const char * name<map_msgs::msg::ProjectedMapInfo>()
{
  return "map_msgs/msg/ProjectedMapInfo";
}

template<>
struct has_fixed_size<map_msgs::msg::ProjectedMapInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<map_msgs::msg::ProjectedMapInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<map_msgs::msg::ProjectedMapInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__TRAITS_HPP_
