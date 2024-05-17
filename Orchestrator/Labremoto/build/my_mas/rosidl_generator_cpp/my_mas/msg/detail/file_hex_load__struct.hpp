// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/FileHexLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__FileHexLoad __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__FileHexLoad __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FileHexLoad_
{
  using Type = FileHexLoad_<ContainerAllocator>;

  explicit FileHexLoad_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path_hex = "";
      this->status = "";
    }
  }

  explicit FileHexLoad_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_hex(_alloc),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path_hex = "";
      this->status = "";
    }
  }

  // field types and members
  using _path_hex_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_hex_type path_hex;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__path_hex(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path_hex = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::FileHexLoad_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::FileHexLoad_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::FileHexLoad_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::FileHexLoad_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__FileHexLoad
    std::shared_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__FileHexLoad
    std::shared_ptr<my_mas::msg::FileHexLoad_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FileHexLoad_ & other) const
  {
    if (this->path_hex != other.path_hex) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const FileHexLoad_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FileHexLoad_

// alias to use template instance with default allocator
using FileHexLoad =
  my_mas::msg::FileHexLoad_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__STRUCT_HPP_
