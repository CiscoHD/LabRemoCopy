// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_mas:msg/Auditor.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/auditor__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_mas/msg/detail/auditor__struct.h"
#include "my_mas/msg/detail/auditor__functions.h"
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

#include "rosidl_runtime_c/string.h"  // fechatransaccion, iduser, logproceso, namenode, tipotransaccion
#include "rosidl_runtime_c/string_functions.h"  // fechatransaccion, iduser, logproceso, namenode, tipotransaccion

// forward declare type support functions


using _Auditor__ros_msg_type = my_mas__msg__Auditor;

static bool _Auditor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Auditor__ros_msg_type * ros_message = static_cast<const _Auditor__ros_msg_type *>(untyped_ros_message);
  // Field name: idnode
  {
    cdr << ros_message->idnode;
  }

  // Field name: namenode
  {
    const rosidl_runtime_c__String * str = &ros_message->namenode;
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

  // Field name: fechatransaccion
  {
    const rosidl_runtime_c__String * str = &ros_message->fechatransaccion;
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

  // Field name: iduser
  {
    const rosidl_runtime_c__String * str = &ros_message->iduser;
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

  // Field name: logproceso
  {
    const rosidl_runtime_c__String * str = &ros_message->logproceso;
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

static bool _Auditor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Auditor__ros_msg_type * ros_message = static_cast<_Auditor__ros_msg_type *>(untyped_ros_message);
  // Field name: idnode
  {
    cdr >> ros_message->idnode;
  }

  // Field name: namenode
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->namenode.data) {
      rosidl_runtime_c__String__init(&ros_message->namenode);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->namenode,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'namenode'\n");
      return false;
    }
  }

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

  // Field name: fechatransaccion
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->fechatransaccion.data) {
      rosidl_runtime_c__String__init(&ros_message->fechatransaccion);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->fechatransaccion,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'fechatransaccion'\n");
      return false;
    }
  }

  // Field name: iduser
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->iduser.data) {
      rosidl_runtime_c__String__init(&ros_message->iduser);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->iduser,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'iduser'\n");
      return false;
    }
  }

  // Field name: logproceso
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->logproceso.data) {
      rosidl_runtime_c__String__init(&ros_message->logproceso);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->logproceso,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'logproceso'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t get_serialized_size_my_mas__msg__Auditor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Auditor__ros_msg_type * ros_message = static_cast<const _Auditor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name idnode
  {
    size_t item_size = sizeof(ros_message->idnode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name namenode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->namenode.size + 1);
  // field.name tipotransaccion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->tipotransaccion.size + 1);
  // field.name fechatransaccion
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->fechatransaccion.size + 1);
  // field.name iduser
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->iduser.size + 1);
  // field.name logproceso
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->logproceso.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Auditor__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_mas__msg__Auditor(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t max_serialized_size_my_mas__msg__Auditor(
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

  // member: idnode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: namenode
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
  // member: fechatransaccion
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
  // member: iduser
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
  // member: logproceso
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
    using DataType = my_mas__msg__Auditor;
    is_plain =
      (
      offsetof(DataType, logproceso) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Auditor__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_mas__msg__Auditor(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Auditor = {
  "my_mas::msg",
  "Auditor",
  _Auditor__cdr_serialize,
  _Auditor__cdr_deserialize,
  _Auditor__get_serialized_size,
  _Auditor__max_serialized_size
};

static rosidl_message_type_support_t _Auditor__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Auditor,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, msg, Auditor)() {
  return &_Auditor__type_support;
}

#if defined(__cplusplus)
}
#endif
