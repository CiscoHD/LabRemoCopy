// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/TransGlobal.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_GLOBAL__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__TRANS_GLOBAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/trans_global__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_TransGlobal_folio
{
public:
  explicit Init_TransGlobal_folio(::my_mas::msg::TransGlobal & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::TransGlobal folio(::my_mas::msg::TransGlobal::_folio_type arg)
  {
    msg_.folio = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::TransGlobal msg_;
};

class Init_TransGlobal_fecha
{
public:
  explicit Init_TransGlobal_fecha(::my_mas::msg::TransGlobal & msg)
  : msg_(msg)
  {}
  Init_TransGlobal_folio fecha(::my_mas::msg::TransGlobal::_fecha_type arg)
  {
    msg_.fecha = std::move(arg);
    return Init_TransGlobal_folio(msg_);
  }

private:
  ::my_mas::msg::TransGlobal msg_;
};

class Init_TransGlobal_name_node
{
public:
  explicit Init_TransGlobal_name_node(::my_mas::msg::TransGlobal & msg)
  : msg_(msg)
  {}
  Init_TransGlobal_fecha name_node(::my_mas::msg::TransGlobal::_name_node_type arg)
  {
    msg_.name_node = std::move(arg);
    return Init_TransGlobal_fecha(msg_);
  }

private:
  ::my_mas::msg::TransGlobal msg_;
};

class Init_TransGlobal_status
{
public:
  explicit Init_TransGlobal_status(::my_mas::msg::TransGlobal & msg)
  : msg_(msg)
  {}
  Init_TransGlobal_name_node status(::my_mas::msg::TransGlobal::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TransGlobal_name_node(msg_);
  }

private:
  ::my_mas::msg::TransGlobal msg_;
};

class Init_TransGlobal_resultado
{
public:
  Init_TransGlobal_resultado()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TransGlobal_status resultado(::my_mas::msg::TransGlobal::_resultado_type arg)
  {
    msg_.resultado = std::move(arg);
    return Init_TransGlobal_status(msg_);
  }

private:
  ::my_mas::msg::TransGlobal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::TransGlobal>()
{
  return my_mas::msg::builder::Init_TransGlobal_resultado();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__TRANS_GLOBAL__BUILDER_HPP_
