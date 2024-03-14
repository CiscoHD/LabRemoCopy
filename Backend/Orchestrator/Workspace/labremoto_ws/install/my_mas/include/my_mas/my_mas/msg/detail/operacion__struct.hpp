// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/Operacion.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__OPERACION__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__OPERACION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__Operacion __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__Operacion __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Operacion_
{
  using Type = Operacion_<ContainerAllocator>;

  explicit Operacion_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nameoperacion = "";
      this->descoperacion = "";
      this->estatusoperacion = "";
      this->fechaoperacion = "";
    }
  }

  explicit Operacion_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nameoperacion(_alloc),
    descoperacion(_alloc),
    estatusoperacion(_alloc),
    fechaoperacion(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nameoperacion = "";
      this->descoperacion = "";
      this->estatusoperacion = "";
      this->fechaoperacion = "";
    }
  }

  // field types and members
  using _nameoperacion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _nameoperacion_type nameoperacion;
  using _descoperacion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _descoperacion_type descoperacion;
  using _estatusoperacion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _estatusoperacion_type estatusoperacion;
  using _fechaoperacion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fechaoperacion_type fechaoperacion;

  // setters for named parameter idiom
  Type & set__nameoperacion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nameoperacion = _arg;
    return *this;
  }
  Type & set__descoperacion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->descoperacion = _arg;
    return *this;
  }
  Type & set__estatusoperacion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->estatusoperacion = _arg;
    return *this;
  }
  Type & set__fechaoperacion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fechaoperacion = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::Operacion_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::Operacion_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::Operacion_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::Operacion_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::Operacion_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::Operacion_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::Operacion_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::Operacion_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::Operacion_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::Operacion_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__Operacion
    std::shared_ptr<my_mas::msg::Operacion_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__Operacion
    std::shared_ptr<my_mas::msg::Operacion_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Operacion_ & other) const
  {
    if (this->nameoperacion != other.nameoperacion) {
      return false;
    }
    if (this->descoperacion != other.descoperacion) {
      return false;
    }
    if (this->estatusoperacion != other.estatusoperacion) {
      return false;
    }
    if (this->fechaoperacion != other.fechaoperacion) {
      return false;
    }
    return true;
  }
  bool operator!=(const Operacion_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Operacion_

// alias to use template instance with default allocator
using Operacion =
  my_mas::msg::Operacion_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__OPERACION__STRUCT_HPP_
