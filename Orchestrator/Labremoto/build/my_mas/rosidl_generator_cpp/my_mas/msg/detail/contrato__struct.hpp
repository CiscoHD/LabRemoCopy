// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/Contrato.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CONTRATO__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__CONTRATO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__Contrato __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__Contrato __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Contrato_
{
  using Type = Contrato_<ContainerAllocator>;

  explicit Contrato_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idcontrato = 0ll;
      this->nombrecontrato = "";
      this->tipocontrato = "";
      this->desccontrato = "";
      this->especificacioncontrato = "";
    }
  }

  explicit Contrato_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nombrecontrato(_alloc),
    tipocontrato(_alloc),
    desccontrato(_alloc),
    especificacioncontrato(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idcontrato = 0ll;
      this->nombrecontrato = "";
      this->tipocontrato = "";
      this->desccontrato = "";
      this->especificacioncontrato = "";
    }
  }

  // field types and members
  using _idcontrato_type =
    int64_t;
  _idcontrato_type idcontrato;
  using _nombrecontrato_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _nombrecontrato_type nombrecontrato;
  using _tipocontrato_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tipocontrato_type tipocontrato;
  using _desccontrato_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _desccontrato_type desccontrato;
  using _especificacioncontrato_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _especificacioncontrato_type especificacioncontrato;

  // setters for named parameter idiom
  Type & set__idcontrato(
    const int64_t & _arg)
  {
    this->idcontrato = _arg;
    return *this;
  }
  Type & set__nombrecontrato(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nombrecontrato = _arg;
    return *this;
  }
  Type & set__tipocontrato(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tipocontrato = _arg;
    return *this;
  }
  Type & set__desccontrato(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->desccontrato = _arg;
    return *this;
  }
  Type & set__especificacioncontrato(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->especificacioncontrato = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::Contrato_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::Contrato_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::Contrato_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::Contrato_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::Contrato_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::Contrato_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::Contrato_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::Contrato_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::Contrato_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::Contrato_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__Contrato
    std::shared_ptr<my_mas::msg::Contrato_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__Contrato
    std::shared_ptr<my_mas::msg::Contrato_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Contrato_ & other) const
  {
    if (this->idcontrato != other.idcontrato) {
      return false;
    }
    if (this->nombrecontrato != other.nombrecontrato) {
      return false;
    }
    if (this->tipocontrato != other.tipocontrato) {
      return false;
    }
    if (this->desccontrato != other.desccontrato) {
      return false;
    }
    if (this->especificacioncontrato != other.especificacioncontrato) {
      return false;
    }
    return true;
  }
  bool operator!=(const Contrato_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Contrato_

// alias to use template instance with default allocator
using Contrato =
  my_mas::msg::Contrato_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__CONTRATO__STRUCT_HPP_
