// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/BitLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__BIT_LOAD__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__BIT_LOAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__BitLoad __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__BitLoad __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BitLoad_
{
  using Type = BitLoad_<ContainerAllocator>;

  explicit BitLoad_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path_bit = "";
    }
  }

  explicit BitLoad_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_bit(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path_bit = "";
    }
  }

  // field types and members
  using _path_bit_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_bit_type path_bit;

  // setters for named parameter idiom
  Type & set__path_bit(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path_bit = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::BitLoad_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::BitLoad_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::BitLoad_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::BitLoad_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::BitLoad_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::BitLoad_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::BitLoad_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::BitLoad_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::BitLoad_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::BitLoad_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__BitLoad
    std::shared_ptr<my_mas::msg::BitLoad_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__BitLoad
    std::shared_ptr<my_mas::msg::BitLoad_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BitLoad_ & other) const
  {
    if (this->path_bit != other.path_bit) {
      return false;
    }
    return true;
  }
  bool operator!=(const BitLoad_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BitLoad_

// alias to use template instance with default allocator
using BitLoad =
  my_mas::msg::BitLoad_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__BIT_LOAD__STRUCT_HPP_
