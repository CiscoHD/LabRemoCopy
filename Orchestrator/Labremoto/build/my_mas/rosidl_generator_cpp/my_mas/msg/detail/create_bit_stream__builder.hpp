// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/CreateBitStream.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/create_bit_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_CreateBitStream_path_savefolder
{
public:
  explicit Init_CreateBitStream_path_savefolder(::my_mas::msg::CreateBitStream & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::CreateBitStream path_savefolder(::my_mas::msg::CreateBitStream::_path_savefolder_type arg)
  {
    msg_.path_savefolder = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::CreateBitStream msg_;
};

class Init_CreateBitStream_path_constrains
{
public:
  explicit Init_CreateBitStream_path_constrains(::my_mas::msg::CreateBitStream & msg)
  : msg_(msg)
  {}
  Init_CreateBitStream_path_savefolder path_constrains(::my_mas::msg::CreateBitStream::_path_constrains_type arg)
  {
    msg_.path_constrains = std::move(arg);
    return Init_CreateBitStream_path_savefolder(msg_);
  }

private:
  ::my_mas::msg::CreateBitStream msg_;
};

class Init_CreateBitStream_path_vhdl
{
public:
  Init_CreateBitStream_path_vhdl()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CreateBitStream_path_constrains path_vhdl(::my_mas::msg::CreateBitStream::_path_vhdl_type arg)
  {
    msg_.path_vhdl = std::move(arg);
    return Init_CreateBitStream_path_constrains(msg_);
  }

private:
  ::my_mas::msg::CreateBitStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::CreateBitStream>()
{
  return my_mas::msg::builder::Init_CreateBitStream_path_vhdl();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__BUILDER_HPP_
