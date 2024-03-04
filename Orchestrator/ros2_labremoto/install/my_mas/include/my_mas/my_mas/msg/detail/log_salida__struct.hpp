// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/LogSalida.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__LOG_SALIDA__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__LOG_SALIDA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__LogSalida __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__LogSalida __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LogSalida_
{
  using Type = LogSalida_<ContainerAllocator>;

  explicit LogSalida_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->logsalida = "";
      this->status = "";
    }
  }

  explicit LogSalida_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : logsalida(_alloc),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->logsalida = "";
      this->status = "";
    }
  }

  // field types and members
  using _logsalida_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _logsalida_type logsalida;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__logsalida(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->logsalida = _arg;
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
    my_mas::msg::LogSalida_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::LogSalida_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::LogSalida_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::LogSalida_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::LogSalida_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::LogSalida_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::LogSalida_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::LogSalida_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::LogSalida_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::LogSalida_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__LogSalida
    std::shared_ptr<my_mas::msg::LogSalida_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__LogSalida
    std::shared_ptr<my_mas::msg::LogSalida_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LogSalida_ & other) const
  {
    if (this->logsalida != other.logsalida) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const LogSalida_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LogSalida_

// alias to use template instance with default allocator
using LogSalida =
  my_mas::msg::LogSalida_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__LOG_SALIDA__STRUCT_HPP_
