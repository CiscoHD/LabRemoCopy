// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/Operacion.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__OPERACION__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__OPERACION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/operacion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_Operacion_fechaoperacion
{
public:
  explicit Init_Operacion_fechaoperacion(::my_mas::msg::Operacion & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::Operacion fechaoperacion(::my_mas::msg::Operacion::_fechaoperacion_type arg)
  {
    msg_.fechaoperacion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::Operacion msg_;
};

class Init_Operacion_estatusoperacion
{
public:
  explicit Init_Operacion_estatusoperacion(::my_mas::msg::Operacion & msg)
  : msg_(msg)
  {}
  Init_Operacion_fechaoperacion estatusoperacion(::my_mas::msg::Operacion::_estatusoperacion_type arg)
  {
    msg_.estatusoperacion = std::move(arg);
    return Init_Operacion_fechaoperacion(msg_);
  }

private:
  ::my_mas::msg::Operacion msg_;
};

class Init_Operacion_descoperacion
{
public:
  explicit Init_Operacion_descoperacion(::my_mas::msg::Operacion & msg)
  : msg_(msg)
  {}
  Init_Operacion_estatusoperacion descoperacion(::my_mas::msg::Operacion::_descoperacion_type arg)
  {
    msg_.descoperacion = std::move(arg);
    return Init_Operacion_estatusoperacion(msg_);
  }

private:
  ::my_mas::msg::Operacion msg_;
};

class Init_Operacion_nameoperacion
{
public:
  Init_Operacion_nameoperacion()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Operacion_descoperacion nameoperacion(::my_mas::msg::Operacion::_nameoperacion_type arg)
  {
    msg_.nameoperacion = std::move(arg);
    return Init_Operacion_descoperacion(msg_);
  }

private:
  ::my_mas::msg::Operacion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::Operacion>()
{
  return my_mas::msg::builder::Init_Operacion_nameoperacion();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__OPERACION__BUILDER_HPP_
