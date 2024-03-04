// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/TransEntrada.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_ENTRADA__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__TRANS_ENTRADA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/trans_entrada__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_TransEntrada_descripcion
{
public:
  explicit Init_TransEntrada_descripcion(::my_mas::msg::TransEntrada & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::TransEntrada descripcion(::my_mas::msg::TransEntrada::_descripcion_type arg)
  {
    msg_.descripcion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::TransEntrada msg_;
};

class Init_TransEntrada_idsesion
{
public:
  explicit Init_TransEntrada_idsesion(::my_mas::msg::TransEntrada & msg)
  : msg_(msg)
  {}
  Init_TransEntrada_descripcion idsesion(::my_mas::msg::TransEntrada::_idsesion_type arg)
  {
    msg_.idsesion = std::move(arg);
    return Init_TransEntrada_descripcion(msg_);
  }

private:
  ::my_mas::msg::TransEntrada msg_;
};

class Init_TransEntrada_idestudiante
{
public:
  explicit Init_TransEntrada_idestudiante(::my_mas::msg::TransEntrada & msg)
  : msg_(msg)
  {}
  Init_TransEntrada_idsesion idestudiante(::my_mas::msg::TransEntrada::_idestudiante_type arg)
  {
    msg_.idestudiante = std::move(arg);
    return Init_TransEntrada_idsesion(msg_);
  }

private:
  ::my_mas::msg::TransEntrada msg_;
};

class Init_TransEntrada_status
{
public:
  explicit Init_TransEntrada_status(::my_mas::msg::TransEntrada & msg)
  : msg_(msg)
  {}
  Init_TransEntrada_idestudiante status(::my_mas::msg::TransEntrada::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TransEntrada_idestudiante(msg_);
  }

private:
  ::my_mas::msg::TransEntrada msg_;
};

class Init_TransEntrada_tipotransaccion
{
public:
  Init_TransEntrada_tipotransaccion()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TransEntrada_status tipotransaccion(::my_mas::msg::TransEntrada::_tipotransaccion_type arg)
  {
    msg_.tipotransaccion = std::move(arg);
    return Init_TransEntrada_status(msg_);
  }

private:
  ::my_mas::msg::TransEntrada msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::TransEntrada>()
{
  return my_mas::msg::builder::Init_TransEntrada_tipotransaccion();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__TRANS_ENTRADA__BUILDER_HPP_
