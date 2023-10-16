// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/AuditorMsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__AUDITOR_MSG__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__AUDITOR_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/auditor_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_AuditorMsg_log_process
{
public:
  explicit Init_AuditorMsg_log_process(::my_mas::msg::AuditorMsg & msg)
  : msg_(msg)
  {}
  ::my_mas::msg::AuditorMsg log_process(::my_mas::msg::AuditorMsg::_log_process_type arg)
  {
    msg_.log_process = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::AuditorMsg msg_;
};

class Init_AuditorMsg_id_user
{
public:
  explicit Init_AuditorMsg_id_user(::my_mas::msg::AuditorMsg & msg)
  : msg_(msg)
  {}
  Init_AuditorMsg_log_process id_user(::my_mas::msg::AuditorMsg::_id_user_type arg)
  {
    msg_.id_user = std::move(arg);
    return Init_AuditorMsg_log_process(msg_);
  }

private:
  ::my_mas::msg::AuditorMsg msg_;
};

class Init_AuditorMsg_date_process
{
public:
  explicit Init_AuditorMsg_date_process(::my_mas::msg::AuditorMsg & msg)
  : msg_(msg)
  {}
  Init_AuditorMsg_id_user date_process(::my_mas::msg::AuditorMsg::_date_process_type arg)
  {
    msg_.date_process = std::move(arg);
    return Init_AuditorMsg_id_user(msg_);
  }

private:
  ::my_mas::msg::AuditorMsg msg_;
};

class Init_AuditorMsg_type_transaction
{
public:
  explicit Init_AuditorMsg_type_transaction(::my_mas::msg::AuditorMsg & msg)
  : msg_(msg)
  {}
  Init_AuditorMsg_date_process type_transaction(::my_mas::msg::AuditorMsg::_type_transaction_type arg)
  {
    msg_.type_transaction = std::move(arg);
    return Init_AuditorMsg_date_process(msg_);
  }

private:
  ::my_mas::msg::AuditorMsg msg_;
};

class Init_AuditorMsg_name_node
{
public:
  explicit Init_AuditorMsg_name_node(::my_mas::msg::AuditorMsg & msg)
  : msg_(msg)
  {}
  Init_AuditorMsg_type_transaction name_node(::my_mas::msg::AuditorMsg::_name_node_type arg)
  {
    msg_.name_node = std::move(arg);
    return Init_AuditorMsg_type_transaction(msg_);
  }

private:
  ::my_mas::msg::AuditorMsg msg_;
};

class Init_AuditorMsg_id_node
{
public:
  Init_AuditorMsg_id_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AuditorMsg_name_node id_node(::my_mas::msg::AuditorMsg::_id_node_type arg)
  {
    msg_.id_node = std::move(arg);
    return Init_AuditorMsg_name_node(msg_);
  }

private:
  ::my_mas::msg::AuditorMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::AuditorMsg>()
{
  return my_mas::msg::builder::Init_AuditorMsg_id_node();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__AUDITOR_MSG__BUILDER_HPP_
