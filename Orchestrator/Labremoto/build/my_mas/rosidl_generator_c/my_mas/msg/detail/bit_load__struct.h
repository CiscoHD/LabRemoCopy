// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/BitLoad.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__BIT_LOAD__STRUCT_H_
#define MY_MAS__MSG__DETAIL__BIT_LOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_bit'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BitLoad in the package my_mas.
typedef struct my_mas__msg__BitLoad
{
  rosidl_runtime_c__String path_bit;
} my_mas__msg__BitLoad;

// Struct for a sequence of my_mas__msg__BitLoad.
typedef struct my_mas__msg__BitLoad__Sequence
{
  my_mas__msg__BitLoad * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__BitLoad__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__BIT_LOAD__STRUCT_H_
