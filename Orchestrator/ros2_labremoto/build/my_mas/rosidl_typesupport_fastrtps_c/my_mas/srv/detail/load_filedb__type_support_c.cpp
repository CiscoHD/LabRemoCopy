// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_mas:srv/LoadFiledb.idl
// generated code does not contain a copyright notice
#include "my_mas/srv/detail/load_filedb__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_mas/srv/detail/load_filedb__struct.h"
#include "my_mas/srv/detail/load_filedb__functions.h"
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

#include "rosidl_runtime_c/string.h"  // date_process, log_process, name_node, type_transaction
#include "rosidl_runtime_c/string_functions.h"  // date_process, log_process, name_node, type_transaction

// forward declare type support functions


using _LoadFiledb_Request__ros_msg_type = my_mas__srv__LoadFiledb_Request;

static bool _LoadFiledb_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LoadFiledb_Request__ros_msg_type * ros_message = static_cast<const _LoadFiledb_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id_node
  {
    cdr << ros_message->id_node;
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

  // Field name: type_transaction
  {
    const rosidl_runtime_c__String * str = &ros_message->type_transaction;
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

  // Field name: date_process
  {
    const rosidl_runtime_c__String * str = &ros_message->date_process;
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

  // Field name: id_user
  {
    cdr << ros_message->id_user;
  }

  // Field name: log_process
  {
    const rosidl_runtime_c__String * str = &ros_message->log_process;
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

static bool _LoadFiledb_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LoadFiledb_Request__ros_msg_type * ros_message = static_cast<_LoadFiledb_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id_node
  {
    cdr >> ros_message->id_node;
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

  // Field name: type_transaction
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->type_transaction.data) {
      rosidl_runtime_c__String__init(&ros_message->type_transaction);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->type_transaction,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'type_transaction'\n");
      return false;
    }
  }

  // Field name: date_process
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->date_process.data) {
      rosidl_runtime_c__String__init(&ros_message->date_process);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->date_process,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'date_process'\n");
      return false;
    }
  }

  // Field name: id_user
  {
    cdr >> ros_message->id_user;
  }

  // Field name: log_process
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->log_process.data) {
      rosidl_runtime_c__String__init(&ros_message->log_process);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->log_process,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'log_process'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t get_serialized_size_my_mas__srv__LoadFiledb_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LoadFiledb_Request__ros_msg_type * ros_message = static_cast<const _LoadFiledb_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name id_node
  {
    size_t item_size = sizeof(ros_message->id_node);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name_node.size + 1);
  // field.name type_transaction
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->type_transaction.size + 1);
  // field.name date_process
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->date_process.size + 1);
  // field.name id_user
  {
    size_t item_size = sizeof(ros_message->id_user);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name log_process
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->log_process.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _LoadFiledb_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_mas__srv__LoadFiledb_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t max_serialized_size_my_mas__srv__LoadFiledb_Request(
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

  // member: id_node
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
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
  // member: type_transaction
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
  // member: date_process
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
  // member: id_user
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: log_process
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

static size_t _LoadFiledb_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_mas__srv__LoadFiledb_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LoadFiledb_Request = {
  "my_mas::srv",
  "LoadFiledb_Request",
  _LoadFiledb_Request__cdr_serialize,
  _LoadFiledb_Request__cdr_deserialize,
  _LoadFiledb_Request__get_serialized_size,
  _LoadFiledb_Request__max_serialized_size
};

static rosidl_message_type_support_t _LoadFiledb_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LoadFiledb_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, srv, LoadFiledb_Request)() {
  return &_LoadFiledb_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "my_mas/srv/detail/load_filedb__struct.h"
// already included above
// #include "my_mas/srv/detail/load_filedb__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // status
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // status

// forward declare type support functions


using _LoadFiledb_Response__ros_msg_type = my_mas__srv__LoadFiledb_Response;

static bool _LoadFiledb_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LoadFiledb_Response__ros_msg_type * ros_message = static_cast<const _LoadFiledb_Response__ros_msg_type *>(untyped_ros_message);
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

  return true;
}

static bool _LoadFiledb_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LoadFiledb_Response__ros_msg_type * ros_message = static_cast<_LoadFiledb_Response__ros_msg_type *>(untyped_ros_message);
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

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t get_serialized_size_my_mas__srv__LoadFiledb_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LoadFiledb_Response__ros_msg_type * ros_message = static_cast<const _LoadFiledb_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _LoadFiledb_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_mas__srv__LoadFiledb_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_mas
size_t max_serialized_size_my_mas__srv__LoadFiledb_Response(
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

  return current_alignment - initial_alignment;
}

static size_t _LoadFiledb_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_mas__srv__LoadFiledb_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LoadFiledb_Response = {
  "my_mas::srv",
  "LoadFiledb_Response",
  _LoadFiledb_Response__cdr_serialize,
  _LoadFiledb_Response__cdr_deserialize,
  _LoadFiledb_Response__get_serialized_size,
  _LoadFiledb_Response__max_serialized_size
};

static rosidl_message_type_support_t _LoadFiledb_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LoadFiledb_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, srv, LoadFiledb_Response)() {
  return &_LoadFiledb_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "my_mas/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_mas/srv/load_filedb.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t LoadFiledb__callbacks = {
  "my_mas::srv",
  "LoadFiledb",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, srv, LoadFiledb_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, srv, LoadFiledb_Response)(),
};

static rosidl_service_type_support_t LoadFiledb__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &LoadFiledb__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_mas, srv, LoadFiledb)() {
  return &LoadFiledb__handle;
}

#if defined(__cplusplus)
}
#endif
