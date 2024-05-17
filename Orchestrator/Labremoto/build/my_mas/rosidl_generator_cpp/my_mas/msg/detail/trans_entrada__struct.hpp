// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/TransEntrada.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_ENTRADA__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__TRANS_ENTRADA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__TransEntrada __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__TransEntrada __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TransEntrada_
{
  using Type = TransEntrada_<ContainerAllocator>;

  explicit TransEntrada_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tipotransaccion = "";
      this->status = "";
      this->idestudiante = "";
      this->idsesion = "";
      this->descripcion = "";
    }
  }

  explicit TransEntrada_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tipotransaccion(_alloc),
    status(_alloc),
    idestudiante(_alloc),
    idsesion(_alloc),
    descripcion(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tipotransaccion = "";
      this->status = "";
      this->idestudiante = "";
      this->idsesion = "";
      this->descripcion = "";
    }
  }

  // field types and members
  using _tipotransaccion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tipotransaccion_type tipotransaccion;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _idestudiante_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _idestudiante_type idestudiante;
  using _idsesion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _idsesion_type idsesion;
  using _descripcion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _descripcion_type descripcion;

  // setters for named parameter idiom
  Type & set__tipotransaccion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tipotransaccion = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__idestudiante(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->idestudiante = _arg;
    return *this;
  }
  Type & set__idsesion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->idsesion = _arg;
    return *this;
  }
  Type & set__descripcion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->descripcion = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::TransEntrada_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::TransEntrada_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::TransEntrada_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::TransEntrada_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::TransEntrada_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::TransEntrada_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::TransEntrada_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::TransEntrada_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::TransEntrada_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::TransEntrada_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__TransEntrada
    std::shared_ptr<my_mas::msg::TransEntrada_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__TransEntrada
    std::shared_ptr<my_mas::msg::TransEntrada_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TransEntrada_ & other) const
  {
    if (this->tipotransaccion != other.tipotransaccion) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->idestudiante != other.idestudiante) {
      return false;
    }
    if (this->idsesion != other.idsesion) {
      return false;
    }
    if (this->descripcion != other.descripcion) {
      return false;
    }
    return true;
  }
  bool operator!=(const TransEntrada_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TransEntrada_

// alias to use template instance with default allocator
using TransEntrada =
  my_mas::msg::TransEntrada_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__TRANS_ENTRADA__STRUCT_HPP_
