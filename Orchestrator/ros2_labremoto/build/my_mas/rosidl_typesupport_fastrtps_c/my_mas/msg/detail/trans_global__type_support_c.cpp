// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_mas:msg/TransGlobal.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/trans_global__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_mas/msg/detail/trans_global__struct.h"
#include "my_mas/msg/detail/trans_global__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // fecha, folio, name_node, resultado, status
#include "rosidl_runtime_c/string_functions.h"  // fecha, folio, name_node, resultado, status

// forward declare type support functions


using _TransGlobal__ros_msg_type = my_mas__msg__TransGlobal;

static bool _TransGlobal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TransGlobal__ros_msg_type * ros_message = static_cast<const _TransGlobal__ros_msg_type *>(untyped_ros_message);
  // Field name: resultado
  {
    const rosidl_runtime_c__String * str = &ros_message->resultado;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: status
  {
    const rosidl_runtime_c__String * str = &ros_message->status;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: name_node
  {
    const rosidl_runtime_c__String * str = &ros_message->name_node;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: fecha
  {
    const rosidl_runtime_c__String * str = &ros_message->fecha;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: folio
  {
    const rosidl_runtime_c__String * str = &ros_message->folio;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _TransGlobal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TransGlobal__ros_msg_type * ros_message = static_cast<_TransGlobal__ros_msg_type *>(untyped_ros_message);
  // Field name: resultado
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->resultado.data) {
      rosidl_runtime_c__String__init(&ros_message->resultado);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->resultado,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'resultado'\n");
      return false;
    }
  }

  // Field name: status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->status.data) {
      rosidl_runtime_c__String__init(&ros_message->status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'status'\n");
      return false;
    }
  }

  // Field name: name_node
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name_node.data) {
      rosidl_runtime_c__String__init(&ros_message->name_node);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name_node,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name_node'\n");
      return false;
    }
  }

  // Field name: fecha
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->fecha.data) {
      rosidl_runtime_c__String__init(&ros_message->fecha);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->fecha,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'fecha'\n");
      return false;
    }
  }

  // Field name: folio
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->folio.data) {
      rosidl_runtime_c__String__init(&ros_message->folio);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->folio,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'folio'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t get_serialized_size_my_mas__msg__TransGlobal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TransGlobal__ros_msg_type * ros_message = static_cast<const _TransGlobal__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name resultado
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->resultado.size + 1);
  // field.name status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status.size + 1);
  // field.name name_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name_node.size + 1);
  // field.name fecha
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->fecha.size + 1);
  // field.name folio
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->folio.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TransGlobal__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_mas__msg__TransGlobal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t max_serialized_size_my_mas__msg__TransGlobal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: resultado
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
  // member: status
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
  // member: name_node
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
  // member: fecha
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
  // member: folio
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

  return current_alignment - initial_alignment;
}

static size_t _TransGlobal__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_mas__msg__TransGlobal(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TransGlobal = {
  "my_mas::msg",
  "TransGlobal",
  _TransGlobal__cdr_serialize,
  _TransGlobal__cdr_deserialize,
  _TransGlobal__get_serialized_size,
  _TransGlobal__max_serialized_size
};

static rosidl_message_type_support_t _TransGlobal__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TransGlobal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, msg, TransGlobal)() {
  return &_TransGlobal__type_support;
}

#if defined(__cplusplus)
}
#endif
