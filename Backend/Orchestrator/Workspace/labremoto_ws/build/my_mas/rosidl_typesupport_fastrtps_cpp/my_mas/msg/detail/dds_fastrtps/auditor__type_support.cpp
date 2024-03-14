// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from my_mas:msg/Auditor.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/auditor__rosidl_typesupport_fastrtps_cpp.hpp"
#include "my_mas/msg/detail/auditor__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace my_mas
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_mas
cdr_serialize(
  const my_mas::msg::Auditor & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: idnode
  cdr << ros_message.idnode;
  // Member: namenode
  cdr << ros_message.namenode;
  // Member: tipotransaccion
  cdr << ros_message.tipotransaccion;
  // Member: fechatransaccion
  cdr << ros_message.fechatransaccion;
  // Member: iduser
  cdr << ros_message.iduser;
  // Member: logproceso
  cdr << ros_message.logproceso;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_mas
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_mas::msg::Auditor & ros_message)
{
  // Member: idnode
  cdr >> ros_message.idnode;

  // Member: namenode
  cdr >> ros_message.namenode;

  // Member: tipotransaccion
  cdr >> ros_message.tipotransaccion;

  // Member: fechatransaccion
  cdr >> ros_message.fechatransaccion;

  // Member: iduser
  cdr >> ros_message.iduser;

  // Member: logproceso
  cdr >> ros_message.logproceso;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_mas
get_serialized_size(
  const my_mas::msg::Auditor & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: idnode
  {
    size_t item_size = sizeof(ros_message.idnode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: namenode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.namenode.size() + 1);
  // Member: tipotransaccion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.tipotransaccion.size() + 1);
  // Member: fechatransaccion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.fechatransaccion.size() + 1);
  // Member: iduser
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.iduser.size() + 1);
  // Member: logproceso
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.logproceso.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_mas
max_serialized_size_Auditor(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: idnode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: namenode
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: tipotransaccion
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: fechatransaccion
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: iduser
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: logproceso
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_mas::msg::Auditor;
    is_plain =
      (
      offsetof(DataType, logproceso) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Auditor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const my_mas::msg::Auditor *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Auditor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<my_mas::msg::Auditor *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Auditor__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const my_mas::msg::Auditor *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Auditor__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Auditor(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Auditor__callbacks = {
  "my_mas::msg",
  "Auditor",
  _Auditor__cdr_serialize,
  _Auditor__cdr_deserialize,
  _Auditor__get_serialized_size,
  _Auditor__max_serialized_size
};

static rosidl_message_type_support_t _Auditor__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Auditor__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_mas

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_my_mas
const rosidl_message_type_support_t *
get_message_type_support_handle<my_mas::msg::Auditor>()
{
  return &my_mas::msg::typesupport_fastrtps_cpp::_Auditor__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_mas, msg, Auditor)() {
  return &my_mas::msg::typesupport_fastrtps_cpp::_Auditor__handle;
}

#ifdef __cplusplus
}
#endif
