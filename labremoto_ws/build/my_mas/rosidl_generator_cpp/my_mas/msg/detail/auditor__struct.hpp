// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/Auditor.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__AUDITOR__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__AUDITOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__Auditor __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__Auditor __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Auditor_
{
  using Type = Auditor_<ContainerAllocator>;

  explicit Auditor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idnode = 0ll;
      this->namenode = "";
      this->tipotransaccion = "";
      this->fechatransaccion = "";
      this->iduser = "";
      this->logproceso = "";
    }
  }

  explicit Auditor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : namenode(_alloc),
    tipotransaccion(_alloc),
    fechatransaccion(_alloc),
    iduser(_alloc),
    logproceso(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idnode = 0ll;
      this->namenode = "";
      this->tipotransaccion = "";
      this->fechatransaccion = "";
      this->iduser = "";
      this->logproceso = "";
    }
  }

  // field types and members
  using _idnode_type =
    int64_t;
  _idnode_type idnode;
  using _namenode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _namenode_type namenode;
  using _tipotransaccion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tipotransaccion_type tipotransaccion;
  using _fechatransaccion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fechatransaccion_type fechatransaccion;
  using _iduser_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _iduser_type iduser;
  using _logproceso_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _logproceso_type logproceso;

  // setters for named parameter idiom
  Type & set__idnode(
    const int64_t & _arg)
  {
    this->idnode = _arg;
    return *this;
  }
  Type & set__namenode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->namenode = _arg;
    return *this;
  }
  Type & set__tipotransaccion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tipotransaccion = _arg;
    return *this;
  }
  Type & set__fechatransaccion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fechatransaccion = _arg;
    return *this;
  }
  Type & set__iduser(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->iduser = _arg;
    return *this;
  }
  Type & set__logproceso(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->logproceso = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::Auditor_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::Auditor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::Auditor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::Auditor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::Auditor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::Auditor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::Auditor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::Auditor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::Auditor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::Auditor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__Auditor
    std::shared_ptr<my_mas::msg::Auditor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__Auditor
    std::shared_ptr<my_mas::msg::Auditor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Auditor_ & other) const
  {
    if (this->idnode != other.idnode) {
      return false;
    }
    if (this->namenode != other.namenode) {
      return false;
    }
    if (this->tipotransaccion != other.tipotransaccion) {
      return false;
    }
    if (this->fechatransaccion != other.fechatransaccion) {
      return false;
    }
    if (this->iduser != other.iduser) {
      return false;
    }
    if (this->logproceso != other.logproceso) {
      return false;
    }
    return true;
  }
  bool operator!=(const Auditor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Auditor_

// alias to use template instance with default allocator
using Auditor =
  my_mas::msg::Auditor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__AUDITOR__STRUCT_HPP_
