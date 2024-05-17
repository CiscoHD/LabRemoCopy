// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_mas:msg/Operacion.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/operacion__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_mas/msg/detail/operacion__struct.h"
#include "my_mas/msg/detail/operacion__functions.h"
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

#include "rosidl_runtime_c/string.h"  // descoperacion, estatusoperacion, fechaoperacion, nameoperacion
#include "rosidl_runtime_c/string_functions.h"  // descoperacion, estatusoperacion, fechaoperacion, nameoperacion

// forward declare type support functions


using _Operacion__ros_msg_type = my_mas__msg__Operacion;

static bool _Operacion__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Operacion__ros_msg_type * ros_message = static_cast<const _Operacion__ros_msg_type *>(untyped_ros_message);
  // Field name: nameoperacion
  {
    const rosidl_runtime_c__String * str = &ros_message->nameoperacion;
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

  // Field name: descoperacion
  {
    const rosidl_runtime_c__String * str = &ros_message->descoperacion;
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

  // Field name: estatusoperacion
  {
    const rosidl_runtime_c__String * str = &ros_message->estatusoperacion;
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

  // Field name: fechaoperacion
  {
    const rosidl_runtime_c__String * str = &ros_message->fechaoperacion;
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

static bool _Operacion__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Operacion__ros_msg_type * ros_message = static_cast<_Operacion__ros_msg_type *>(untyped_ros_message);
  // Field name: nameoperacion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->nameoperacion.data) {
      rosidl_runtime_c__String__init(&ros_message->nameoperacion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->nameoperacion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'nameoperacion'\n");
      return false;
    }
  }

  // Field name: descoperacion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->descoperacion.data) {
      rosidl_runtime_c__String__init(&ros_message->descoperacion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->descoperacion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'descoperacion'\n");
      return false;
    }
  }

  // Field name: estatusoperacion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->estatusoperacion.data) {
      rosidl_runtime_c__String__init(&ros_message->estatusoperacion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->estatusoperacion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'estatusoperacion'\n");
      return false;
    }
  }

  // Field name: fechaoperacion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->fechaoperacion.data) {
      rosidl_runtime_c__String__init(&ros_message->fechaoperacion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->fechaoperacion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'fechaoperacion'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t get_serialized_size_my_mas__msg__Operacion(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Operacion__ros_msg_type * ros_message = static_cast<const _Operacion__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name nameoperacion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->nameoperacion.size + 1);
  // field.name descoperacion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->descoperacion.size + 1);
  // field.name estatusoperacion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->estatusoperacion.size + 1);
  // field.name fechaoperacion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->fechaoperacion.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Operacion__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_mas__msg__Operacion(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t max_serialized_size_my_mas__msg__Operacion(
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

  // member: nameoperacion
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
  // member: descoperacion
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
  // member: estatusoperacion
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
  // member: fechaoperacion
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
    using DataType = my_mas__msg__Operacion;
    is_plain =
      (
      offsetof(DataType, fechaoperacion) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Operacion__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_mas__msg__Operacion(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Operacion = {
  "my_mas::msg",
  "Operacion",
  _Operacion__cdr_serialize,
  _Operacion__cdr_deserialize,
  _Operacion__get_serialized_size,
  _Operacion__max_serialized_size
};

static rosidl_message_type_support_t _Operacion__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Operacion,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, msg, Operacion)() {
  return &_Operacion__type_support;
}

#if defined(__cplusplus)
}
#endif
