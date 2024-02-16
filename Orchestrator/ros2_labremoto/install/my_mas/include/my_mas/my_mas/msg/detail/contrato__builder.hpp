// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/Contrato.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CONTRATO__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__CONTRATO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/contrato__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_Contrato_especificacioncontrato
{
public:
  explicit Init_Contrato_especificacioncontrato(::my_mas::msg::Contrato & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::Contrato especificacioncontrato(::my_mas::msg::Contrato::_especificacioncontrato_type arg)
  {
    msg_.especificacioncontrato = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::Contrato msg_;
};

class Init_Contrato_desccontrato
{
public:
  explicit Init_Contrato_desccontrato(::my_mas::msg::Contrato & msg)
  : msg_(msg)
  {}
  Init_Contrato_especificacioncontrato desccontrato(::my_mas::msg::Contrato::_desccontrato_type arg)
  {
    msg_.desccontrato = std::move(arg);
    return Init_Contrato_especificacioncontrato(msg_);
  }

private:
  ::my_mas::msg::Contrato msg_;
};

class Init_Contrato_tipocontrato
{
public:
  explicit Init_Contrato_tipocontrato(::my_mas::msg::Contrato & msg)
  : msg_(msg)
  {}
  Init_Contrato_desccontrato tipocontrato(::my_mas::msg::Contrato::_tipocontrato_type arg)
  {
    msg_.tipocontrato = std::move(arg);
    return Init_Contrato_desccontrato(msg_);
  }

private:
  ::my_mas::msg::Contrato msg_;
};

class Init_Contrato_nombrecontrato
{
public:
  explicit Init_Contrato_nombrecontrato(::my_mas::msg::Contrato & msg)
  : msg_(msg)
  {}
  Init_Contrato_tipocontrato nombrecontrato(::my_mas::msg::Contrato::_nombrecontrato_type arg)
  {
    msg_.nombrecontrato = std::move(arg);
    return Init_Contrato_tipocontrato(msg_);
  }

private:
  ::my_mas::msg::Contrato msg_;
};

class Init_Contrato_idcontrato
{
public:
  Init_Contrato_idcontrato()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Contrato_nombrecontrato idcontrato(::my_mas::msg::Contrato::_idcontrato_type arg)
  {
    msg_.idcontrato = std::move(arg);
    return Init_Contrato_nombrecontrato(msg_);
  }

private:
  ::my_mas::msg::Contrato msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::Contrato>()
{
  return my_mas::msg::builder::Init_Contrato_idcontrato();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__CONTRATO__BUILDER_HPP_
