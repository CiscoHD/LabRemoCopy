// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:srv/LoadFiledb.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILEDB__BUILDER_HPP_
#define MY_MAS__SRV__DETAIL__LOAD_FILEDB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/srv/detail/load_filedb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace srv
{

namespace builder
{

class Init_LoadFiledb_Request_log_process
{
public:
  explicit Init_LoadFiledb_Request_log_process(::my_mas::srv::LoadFiledb_Request & msg)
  : msg_(msg)
  {}
  ::my_mas::srv::LoadFiledb_Request log_process(::my_mas::srv::LoadFiledb_Request::_log_process_type arg)
  {
    msg_.log_process = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Request msg_;
};

class Init_LoadFiledb_Request_id_user
{
public:
  explicit Init_LoadFiledb_Request_id_user(::my_mas::srv::LoadFiledb_Request & msg)
  : msg_(msg)
  {}
  Init_LoadFiledb_Request_log_process id_user(::my_mas::srv::LoadFiledb_Request::_id_user_type arg)
  {
    msg_.id_user = std::move(arg);
    return Init_LoadFiledb_Request_log_process(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Request msg_;
};

class Init_LoadFiledb_Request_date_process
{
public:
  explicit Init_LoadFiledb_Request_date_process(::my_mas::srv::LoadFiledb_Request & msg)
  : msg_(msg)
  {}
  Init_LoadFiledb_Request_id_user date_process(::my_mas::srv::LoadFiledb_Request::_date_process_type arg)
  {
    msg_.date_process = std::move(arg);
    return Init_LoadFiledb_Request_id_user(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Request msg_;
};

class Init_LoadFiledb_Request_type_transaction
{
public:
  explicit Init_LoadFiledb_Request_type_transaction(::my_mas::srv::LoadFiledb_Request & msg)
  : msg_(msg)
  {}
  Init_LoadFiledb_Request_date_process type_transaction(::my_mas::srv::LoadFiledb_Request::_type_transaction_type arg)
  {
    msg_.type_transaction = std::move(arg);
    return Init_LoadFiledb_Request_date_process(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Request msg_;
};

class Init_LoadFiledb_Request_name_node
{
public:
  explicit Init_LoadFiledb_Request_name_node(::my_mas::srv::LoadFiledb_Request & msg)
  : msg_(msg)
  {}
  Init_LoadFiledb_Request_type_transaction name_node(::my_mas::srv::LoadFiledb_Request::_name_node_type arg)
  {
    msg_.name_node = std::move(arg);
    return Init_LoadFiledb_Request_type_transaction(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Request msg_;
};

class Init_LoadFiledb_Request_id_node
{
public:
  Init_LoadFiledb_Request_id_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadFiledb_Request_name_node id_node(::my_mas::srv::LoadFiledb_Request::_id_node_type arg)
  {
    msg_.id_node = std::move(arg);
    return Init_LoadFiledb_Request_name_node(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::srv::LoadFiledb_Request>()
{
  return my_mas::srv::builder::Init_LoadFiledb_Request_id_node();
}

}  // namespace my_mas


namespace my_mas
{

namespace srv
{

namespace builder
{

class Init_LoadFiledb_Response_status
{
public:
  Init_LoadFiledb_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_mas::srv::LoadFiledb_Response status(::my_mas::srv::LoadFiledb_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::srv::LoadFiledb_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::srv::LoadFiledb_Response>()
{
  return my_mas::srv::builder::Init_LoadFiledb_Response_status();
}

}  // namespace my_mas

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILEDB__BUILDER_HPP_
