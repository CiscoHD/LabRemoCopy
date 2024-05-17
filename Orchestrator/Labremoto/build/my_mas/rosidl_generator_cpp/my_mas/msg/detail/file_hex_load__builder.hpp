// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/FileHexLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/file_hex_load__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_FileHexLoad_status
{
public:
  explicit Init_FileHexLoad_status(::my_mas::msg::FileHexLoad & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::FileHexLoad status(::my_mas::msg::FileHexLoad::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::FileHexLoad msg_;
};

class Init_FileHexLoad_path_hex
{
public:
  Init_FileHexLoad_path_hex()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FileHexLoad_status path_hex(::my_mas::msg::FileHexLoad::_path_hex_type arg)
  {
    msg_.path_hex = std::move(arg);
    return Init_FileHexLoad_status(msg_);
  }

private:
  ::my_mas::msg::FileHexLoad msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::FileHexLoad>()
{
  return my_mas::msg::builder::Init_FileHexLoad_path_hex();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__BUILDER_HPP_
