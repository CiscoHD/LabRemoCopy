// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/CreateBitStream.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__STRUCT_H_
#define MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_vhdl'
// Member 'path_constrains'
// Member 'path_savefolder'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CreateBitStream in the package my_mas.
typedef struct my_mas__msg__CreateBitStream
{
  rosidl_runtime_c__String path_vhdl;
  rosidl_runtime_c__String path_constrains;
  rosidl_runtime_c__String path_savefolder;
} my_mas__msg__CreateBitStream;

// Struct for a sequence of my_mas__msg__CreateBitStream.
typedef struct my_mas__msg__CreateBitStream__Sequence
{
  my_mas__msg__CreateBitStream * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__CreateBitStream__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__CREATE_BIT_STREAM__STRUCT_H_
