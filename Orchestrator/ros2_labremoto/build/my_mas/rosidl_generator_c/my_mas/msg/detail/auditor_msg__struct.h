// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/AuditorMsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__AUDITOR_MSG__STRUCT_H_
#define MY_MAS__MSG__DETAIL__AUDITOR_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id_node'
// Member 'name_node'
// Member 'type_transaction'
// Member 'date_process'
// Member 'id_user'
// Member 'log_process'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AuditorMsg in the package my_mas.
typedef struct my_mas__msg__AuditorMsg
{
  rosidl_runtime_c__String id_node;
  rosidl_runtime_c__String name_node;
  rosidl_runtime_c__String type_transaction;
  rosidl_runtime_c__String date_process;
  rosidl_runtime_c__String id_user;
  rosidl_runtime_c__String log_process;
} my_mas__msg__AuditorMsg;

// Struct for a sequence of my_mas__msg__AuditorMsg.
typedef struct my_mas__msg__AuditorMsg__Sequence
{
  my_mas__msg__AuditorMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__AuditorMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__AUDITOR_MSG__STRUCT_H_
