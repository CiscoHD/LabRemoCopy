// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:srv/LoadFiledb.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILEDB__STRUCT_HPP_
#define MY_MAS__SRV__DETAIL__LOAD_FILEDB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__srv__LoadFiledb_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__srv__LoadFiledb_Request __declspec(deprecated)
#endif

namespace my_mas
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadFiledb_Request_
{
  using Type = LoadFiledb_Request_<ContainerAllocator>;

  explicit LoadFiledb_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id_node = 0l;
      this->name_node = "";
      this->type_transaction = "";
      this->date_process = "";
      this->id_user = 0l;
      this->log_process = "";
    }
  }

  explicit LoadFiledb_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name_node(_alloc),
    type_transaction(_alloc),
    date_process(_alloc),
    log_process(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id_node = 0l;
      this->name_node = "";
      this->type_transaction = "";
      this->date_process = "";
      this->id_user = 0l;
      this->log_process = "";
    }
  }

  // field types and members
  using _id_node_type =
    int32_t;
  _id_node_type id_node;
  using _name_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_node_type name_node;
  using _type_transaction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_transaction_type type_transaction;
  using _date_process_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _date_process_type date_process;
  using _id_user_type =
    int32_t;
  _id_user_type id_user;
  using _log_process_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _log_process_type log_process;

  // setters for named parameter idiom
  Type & set__id_node(
    const int32_t & _arg)
  {
    this->id_node = _arg;
    return *this;
  }
  Type & set__name_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name_node = _arg;
    return *this;
  }
  Type & set__type_transaction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type_transaction = _arg;
    return *this;
  }
  Type & set__date_process(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->date_process = _arg;
    return *this;
  }
  Type & set__id_user(
    const int32_t & _arg)
  {
    this->id_user = _arg;
    return *this;
  }
  Type & set__log_process(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->log_process = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::srv::LoadFiledb_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::srv::LoadFiledb_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFiledb_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFiledb_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__srv__LoadFiledb_Request
    std::shared_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__srv__LoadFiledb_Request
    std::shared_ptr<my_mas::srv::LoadFiledb_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadFiledb_Request_ & other) const
  {
    if (this->id_node != other.id_node) {
      return false;
    }
    if (this->name_node != other.name_node) {
      return false;
    }
    if (this->type_transaction != other.type_transaction) {
      return false;
    }
    if (this->date_process != other.date_process) {
      return false;
    }
    if (this->id_user != other.id_user) {
      return false;
    }
    if (this->log_process != other.log_process) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadFiledb_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadFiledb_Request_

// alias to use template instance with default allocator
using LoadFiledb_Request =
  my_mas::srv::LoadFiledb_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_mas


#ifndef _WIN32
# define DEPRECATED__my_mas__srv__LoadFiledb_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__srv__LoadFiledb_Response __declspec(deprecated)
#endif

namespace my_mas
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadFiledb_Response_
{
  using Type = LoadFiledb_Response_<ContainerAllocator>;

  explicit LoadFiledb_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit LoadFiledb_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::srv::LoadFiledb_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::srv::LoadFiledb_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFiledb_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFiledb_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__srv__LoadFiledb_Response
    std::shared_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__srv__LoadFiledb_Response
    std::shared_ptr<my_mas::srv::LoadFiledb_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadFiledb_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadFiledb_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadFiledb_Response_

// alias to use template instance with default allocator
using LoadFiledb_Response =
  my_mas::srv::LoadFiledb_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_mas

namespace my_mas
{

namespace srv
{

struct LoadFiledb
{
  using Request = my_mas::srv::LoadFiledb_Request;
  using Response = my_mas::srv::LoadFiledb_Response;
};

}  // namespace srv

}  // namespace my_mas

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILEDB__STRUCT_HPP_
