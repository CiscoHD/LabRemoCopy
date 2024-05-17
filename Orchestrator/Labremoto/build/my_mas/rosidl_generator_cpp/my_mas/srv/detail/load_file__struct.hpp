// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:srv/LoadFile.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILE__STRUCT_HPP_
#define MY_MAS__SRV__DETAIL__LOAD_FILE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__srv__LoadFile_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__srv__LoadFile_Request __declspec(deprecated)
#endif

namespace my_mas
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadFile_Request_
{
  using Type = LoadFile_Request_<ContainerAllocator>;

  explicit LoadFile_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0ll;
      this->b = 0ll;
    }
  }

  explicit LoadFile_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0ll;
      this->b = 0ll;
    }
  }

  // field types and members
  using _a_type =
    int64_t;
  _a_type a;
  using _b_type =
    int64_t;
  _b_type b;

  // setters for named parameter idiom
  Type & set__a(
    const int64_t & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const int64_t & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::srv::LoadFile_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::srv::LoadFile_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFile_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFile_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__srv__LoadFile_Request
    std::shared_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__srv__LoadFile_Request
    std::shared_ptr<my_mas::srv::LoadFile_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadFile_Request_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadFile_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadFile_Request_

// alias to use template instance with default allocator
using LoadFile_Request =
  my_mas::srv::LoadFile_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_mas


#ifndef _WIN32
# define DEPRECATED__my_mas__srv__LoadFile_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__srv__LoadFile_Response __declspec(deprecated)
#endif

namespace my_mas
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadFile_Response_
{
  using Type = LoadFile_Response_<ContainerAllocator>;

  explicit LoadFile_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit LoadFile_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::srv::LoadFile_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::srv::LoadFile_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFile_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::srv::LoadFile_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__srv__LoadFile_Response
    std::shared_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__srv__LoadFile_Response
    std::shared_ptr<my_mas::srv::LoadFile_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadFile_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadFile_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadFile_Response_

// alias to use template instance with default allocator
using LoadFile_Response =
  my_mas::srv::LoadFile_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_mas

namespace my_mas
{

namespace srv
{

struct LoadFile
{
  using Request = my_mas::srv::LoadFile_Request;
  using Response = my_mas::srv::LoadFile_Response;
};

}  // namespace srv

}  // namespace my_mas

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILE__STRUCT_HPP_
