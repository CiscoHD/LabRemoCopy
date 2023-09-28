// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:srv/LoadFile.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILE__BUILDER_HPP_
#define MY_MAS__SRV__DETAIL__LOAD_FILE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/srv/detail/load_file__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace srv
{

namespace builder
{

class Init_LoadFile_Request_b
{
public:
  explicit Init_LoadFile_Request_b(::my_mas::srv::LoadFile_Request & msg)
  : msg_(msg)
  {}
  ::my_mas::srv::LoadFile_Request b(::my_mas::srv::LoadFile_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::srv::LoadFile_Request msg_;
};

class Init_LoadFile_Request_a
{
public:
  Init_LoadFile_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadFile_Request_b a(::my_mas::srv::LoadFile_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_LoadFile_Request_b(msg_);
  }

private:
  ::my_mas::srv::LoadFile_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::srv::LoadFile_Request>()
{
  return my_mas::srv::builder::Init_LoadFile_Request_a();
}

}  // namespace my_mas


namespace my_mas
{

namespace srv
{

namespace builder
{

class Init_LoadFile_Response_sum
{
public:
  Init_LoadFile_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_mas::srv::LoadFile_Response sum(::my_mas::srv::LoadFile_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::srv::LoadFile_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::srv::LoadFile_Response>()
{
  return my_mas::srv::builder::Init_LoadFile_Response_sum();
}

}  // namespace my_mas

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILE__BUILDER_HPP_
