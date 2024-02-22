// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/LogSalida.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__LOG_SALIDA__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__LOG_SALIDA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/log_salida__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_LogSalida_logsalida
{
public:
  Init_LogSalida_logsalida()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_mas::msg::LogSalida logsalida(::my_mas::msg::LogSalida::_logsalida_type arg)
  {
    msg_.logsalida = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::LogSalida msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::LogSalida>()
{
  return my_mas::msg::builder::Init_LogSalida_logsalida();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__LOG_SALIDA__BUILDER_HPP_
