// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/CreateBitStream.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__CreateBitStream __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__CreateBitStream __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CreateBitStream_
{
  using Type = CreateBitStream_<ContainerAllocator>;

  explicit CreateBitStream_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path_vhdl = "";
      this->path_constrains = "";
      this->path_savefolder = "";
    }
  }

  explicit CreateBitStream_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_vhdl(_alloc),
    path_constrains(_alloc),
    path_savefolder(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path_vhdl = "";
      this->path_constrains = "";
      this->path_savefolder = "";
    }
  }

  // field types and members
  using _path_vhdl_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_vhdl_type path_vhdl;
  using _path_constrains_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_constrains_type path_constrains;
  using _path_savefolder_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_savefolder_type path_savefolder;

  // setters for named parameter idiom
  Type & set__path_vhdl(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path_vhdl = _arg;
    return *this;
  }
  Type & set__path_constrains(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path_constrains = _arg;
    return *this;
  }
  Type & set__path_savefolder(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path_savefolder = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::CreateBitStream_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::CreateBitStream_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::CreateBitStream_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::CreateBitStream_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__CreateBitStream
    std::shared_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__CreateBitStream
    std::shared_ptr<my_mas::msg::CreateBitStream_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CreateBitStream_ & other) const
  {
    if (this->path_vhdl != other.path_vhdl) {
      return false;
    }
    if (this->path_constrains != other.path_constrains) {
      return false;
    }
    if (this->path_savefolder != other.path_savefolder) {
      return false;
    }
    return true;
  }
  bool operator!=(const CreateBitStream_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CreateBitStream_

// alias to use template instance with default allocator
using CreateBitStream =
  my_mas::msg::CreateBitStream_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__STRUCT_HPP_
