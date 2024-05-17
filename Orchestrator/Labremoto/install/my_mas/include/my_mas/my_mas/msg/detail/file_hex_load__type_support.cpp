// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_mas:msg/FileHexLoad.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_mas/msg/detail/file_hex_load__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_mas
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FileHexLoad_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_mas::msg::FileHexLoad(_init);
}

void FileHexLoad_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_mas::msg::FileHexLoad *>(message_memory);
  typed_message->~FileHexLoad();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FileHexLoad_message_member_array[2] = {
  {
    "path_hex",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_mas::msg::FileHexLoad, path_hex),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_mas::msg::FileHexLoad, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FileHexLoad_message_members = {
  "my_mas::msg",  // message namespace
  "FileHexLoad",  // message name
  2,  // number of fields
  sizeof(my_mas::msg::FileHexLoad),
  FileHexLoad_message_member_array,  // message members
  FileHexLoad_init_function,  // function to initialize message memory (memory has to be allocated)
  FileHexLoad_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FileHexLoad_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FileHexLoad_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_mas


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_mas::msg::FileHexLoad>()
{
  return &::my_mas::msg::rosidl_typesupport_introspection_cpp::FileHexLoad_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_mas, msg, FileHexLoad)() {
  return &::my_mas::msg::rosidl_typesupport_introspection_cpp::FileHexLoad_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
