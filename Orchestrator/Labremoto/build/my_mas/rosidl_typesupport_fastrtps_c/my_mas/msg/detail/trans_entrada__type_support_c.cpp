// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_mas:msg/TransEntrada.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/trans_entrada__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_mas/msg/detail/trans_entrada__struct.h"
#include "my_mas/msg/detail/trans_entrada__functions.h"
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

#include "rosidl_runtime_c/string.h"  // descripcion, idestudiante, idsesion, status, tipotransaccion
#include "rosidl_runtime_c/string_functions.h"  // descripcion, idestudiante, idsesion, status, tipotransaccion

// forward declare type support functions


using _TransEntrada__ros_msg_type = my_mas__msg__TransEntrada;

static bool _TransEntrada__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TransEntrada__ros_msg_type * ros_message = static_cast<const _TransEntrada__ros_msg_type *>(untyped_ros_message);
  // Field name: tipotransaccion
  {
    const rosidl_runtime_c__String * str = &ros_message->tipotransaccion;
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

  // Field name: idestudiante
  {
    const rosidl_runtime_c__String * str = &ros_message->idestudiante;
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

  // Field name: idsesion
  {
    const rosidl_runtime_c__String * str = &ros_message->idsesion;
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

  // Field name: descripcion
  {
    const rosidl_runtime_c__String * str = &ros_message->descripcion;
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

static bool _TransEntrada__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TransEntrada__ros_msg_type * ros_message = static_cast<_TransEntrada__ros_msg_type *>(untyped_ros_message);
  // Field name: tipotransaccion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->tipotransaccion.data) {
      rosidl_runtime_c__String__init(&ros_message->tipotransaccion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->tipotransaccion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'tipotransaccion'\n");
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

  // Field name: idestudiante
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->idestudiante.data) {
      rosidl_runtime_c__String__init(&ros_message->idestudiante);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->idestudiante,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'idestudiante'\n");
      return false;
    }
  }

  // Field name: idsesion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->idsesion.data) {
      rosidl_runtime_c__String__init(&ros_message->idsesion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->idsesion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'idsesion'\n");
      return false;
    }
  }

  // Field name: descripcion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->descripcion.data) {
      rosidl_runtime_c__String__init(&ros_message->descripcion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->descripcion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'descripcion'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t get_serialized_size_my_mas__msg__TransEntrada(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TransEntrada__ros_msg_type * ros_message = static_cast<const _TransEntrada__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name tipotransaccion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->tipotransaccion.size + 1);
  // field.name status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status.size + 1);
  // field.name idestudiante
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->idestudiante.size + 1);
  // field.name idsesion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->idsesion.size + 1);
  // field.name descripcion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->descripcion.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TransEntrada__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_mas__msg__TransEntrada(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t max_serialized_size_my_mas__msg__TransEntrada(
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

  // member: tipotransaccion
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
  // member: idestudiante
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
  // member: idsesion
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
  // member: descripcion
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
    using DataType = my_mas__msg__TransEntrada;
    is_plain =
      (
      offsetof(DataType, descripcion) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TransEntrada__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_mas__msg__TransEntrada(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TransEntrada = {
  "my_mas::msg",
  "TransEntrada",
  _TransEntrada__cdr_serialize,
  _TransEntrada__cdr_deserialize,
  _TransEntrada__get_serialized_size,
  _TransEntrada__max_serialized_size
};

static rosidl_message_type_support_t _TransEntrada__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TransEntrada,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, msg, TransEntrada)() {
  return &_TransEntrada__type_support;
}

#if defined(__cplusplus)
}
#endif
