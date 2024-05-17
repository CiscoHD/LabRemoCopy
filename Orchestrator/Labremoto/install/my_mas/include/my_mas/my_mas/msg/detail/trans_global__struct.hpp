// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/TransGlobal.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_GLOBAL__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__TRANS_GLOBAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__TransGlobal __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__TransGlobal __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TransGlobal_
{
  using Type = TransGlobal_<ContainerAllocator>;

  explicit TransGlobal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resultado = "";
      this->status = "";
      this->name_node = "";
      this->fecha = "";
      this->folio = "";
    }
  }

  explicit TransGlobal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : resultado(_alloc),
    status(_alloc),
    name_node(_alloc),
    fecha(_alloc),
    folio(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resultado = "";
      this->status = "";
      this->name_node = "";
      this->fecha = "";
      this->folio = "";
    }
  }

  // field types and members
  using _resultado_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _resultado_type resultado;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _name_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_node_type name_node;
  using _fecha_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fecha_type fecha;
  using _folio_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _folio_type folio;

  // setters for named parameter idiom
  Type & set__resultado(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->resultado = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__name_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name_node = _arg;
    return *this;
  }
  Type & set__fecha(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fecha = _arg;
    return *this;
  }
  Type & set__folio(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->folio = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::TransGlobal_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::TransGlobal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::TransGlobal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::TransGlobal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::TransGlobal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::TransGlobal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::TransGlobal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::TransGlobal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::TransGlobal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::TransGlobal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__TransGlobal
    std::shared_ptr<my_mas::msg::TransGlobal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__TransGlobal
    std::shared_ptr<my_mas::msg::TransGlobal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TransGlobal_ & other) const
  {
    if (this->resultado != other.resultado) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->name_node != other.name_node) {
      return false;
    }
    if (this->fecha != other.fecha) {
      return false;
    }
    if (this->folio != other.folio) {
      return false;
    }
    return true;
  }
  bool operator!=(const TransGlobal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TransGlobal_

// alias to use template instance with default allocator
using TransGlobal =
  my_mas::msg::TransGlobal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__TRANS_GLOBAL__STRUCT_HPP_
