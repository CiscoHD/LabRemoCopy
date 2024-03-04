// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/FileHexLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__STRUCT_H_
#define MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_hex'
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FileHexLoad in the package my_mas.
typedef struct my_mas__msg__FileHexLoad
{
  rosidl_runtime_c__String path_hex;
  rosidl_runtime_c__String status;
} my_mas__msg__FileHexLoad;

// Struct for a sequence of my_mas__msg__FileHexLoad.
typedef struct my_mas__msg__FileHexLoad__Sequence
{
  my_mas__msg__FileHexLoad * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__FileHexLoad__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__FILE_HEX_LOAD__STRUCT_H_
