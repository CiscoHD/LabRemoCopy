// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/Auditor.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__AUDITOR__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__AUDITOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/auditor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_Auditor_logproceso
{
public:
  explicit Init_Auditor_logproceso(::my_mas::msg::Auditor & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::Auditor logproceso(::my_mas::msg::Auditor::_logproceso_type arg)
  {
    msg_.logproceso = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::Auditor msg_;
};

class Init_Auditor_iduser
{
public:
  explicit Init_Auditor_iduser(::my_mas::msg::Auditor & msg)
  : msg_(msg)
  {}
  Init_Auditor_logproceso iduser(::my_mas::msg::Auditor::_iduser_type arg)
  {
    msg_.iduser = std::move(arg);
    return Init_Auditor_logproceso(msg_);
  }

private:
  ::my_mas::msg::Auditor msg_;
};

class Init_Auditor_fechatransaccion
{
public:
  explicit Init_Auditor_fechatransaccion(::my_mas::msg::Auditor & msg)
  : msg_(msg)
  {}
  Init_Auditor_iduser fechatransaccion(::my_mas::msg::Auditor::_fechatransaccion_type arg)
  {
    msg_.fechatransaccion = std::move(arg);
    return Init_Auditor_iduser(msg_);
  }

private:
  ::my_mas::msg::Auditor msg_;
};

class Init_Auditor_tipotransaccion
{
public:
  explicit Init_Auditor_tipotransaccion(::my_mas::msg::Auditor & msg)
  : msg_(msg)
  {}
  Init_Auditor_fechatransaccion tipotransaccion(::my_mas::msg::Auditor::_tipotransaccion_type arg)
  {
    msg_.tipotransaccion = std::move(arg);
    return Init_Auditor_fechatransaccion(msg_);
  }

private:
  ::my_mas::msg::Auditor msg_;
};

class Init_Auditor_namenode
{
public:
  explicit Init_Auditor_namenode(::my_mas::msg::Auditor & msg)
  : msg_(msg)
  {}
  Init_Auditor_tipotransaccion namenode(::my_mas::msg::Auditor::_namenode_type arg)
  {
    msg_.namenode = std::move(arg);
    return Init_Auditor_tipotransaccion(msg_);
  }

private:
  ::my_mas::msg::Auditor msg_;
};

class Init_Auditor_idnode
{
public:
  Init_Auditor_idnode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Auditor_namenode idnode(::my_mas::msg::Auditor::_idnode_type arg)
  {
    msg_.idnode = std::move(arg);
    return Init_Auditor_namenode(msg_);
  }

private:
  ::my_mas::msg::Auditor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::Auditor>()
{
  return my_mas::msg::builder::Init_Auditor_idnode();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__AUDITOR__BUILDER_HPP_
