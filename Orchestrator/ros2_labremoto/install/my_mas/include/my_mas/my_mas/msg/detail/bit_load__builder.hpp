// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/BitLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__BIT_LOAD__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__BIT_LOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/bit_load__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_BitLoad_path_bit
{
public:
  Init_BitLoad_path_bit()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_mas::msg::BitLoad path_bit(::my_mas::msg::BitLoad::_path_bit_type arg)
  {
    msg_.path_bit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::BitLoad msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::BitLoad>()
{
  return my_mas::msg::builder::Init_BitLoad_path_bit();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__BIT_LOAD__BUILDER_HPP_
