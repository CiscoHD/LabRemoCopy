// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/TransGlobal.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_GLOBAL__STRUCT_H_
#define MY_MAS__MSG__DETAIL__TRANS_GLOBAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'resultado'
// Member 'status'
// Member 'name_node'
// Member 'fecha'
// Member 'folio'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TransGlobal in the package my_mas.
typedef struct my_mas__msg__TransGlobal
{
  rosidl_runtime_c__String resultado;
  rosidl_runtime_c__String status;
  rosidl_runtime_c__String name_node;
  rosidl_runtime_c__String fecha;
  rosidl_runtime_c__String folio;
} my_mas__msg__TransGlobal;

// Struct for a sequence of my_mas__msg__TransGlobal.
typedef struct my_mas__msg__TransGlobal__Sequence
{
  my_mas__msg__TransGlobal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__TransGlobal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__TRANS_GLOBAL__STRUCT_H_
