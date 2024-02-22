// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/LogSalida.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__LOG_SALIDA__STRUCT_H_
#define MY_MAS__MSG__DETAIL__LOG_SALIDA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'logsalida'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LogSalida in the package my_mas.
typedef struct my_mas__msg__LogSalida
{
  rosidl_runtime_c__String logsalida;
} my_mas__msg__LogSalida;

// Struct for a sequence of my_mas__msg__LogSalida.
typedef struct my_mas__msg__LogSalida__Sequence
{
  my_mas__msg__LogSalida * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__LogSalida__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__LOG_SALIDA__STRUCT_H_
