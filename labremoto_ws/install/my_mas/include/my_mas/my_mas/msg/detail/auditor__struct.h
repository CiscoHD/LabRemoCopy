// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/Auditor.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__AUDITOR__STRUCT_H_
#define MY_MAS__MSG__DETAIL__AUDITOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'namenode'
// Member 'tipotransaccion'
// Member 'fechatransaccion'
// Member 'iduser'
// Member 'logproceso'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Auditor in the package my_mas.
typedef struct my_mas__msg__Auditor
{
  int64_t idnode;
  rosidl_runtime_c__String namenode;
  rosidl_runtime_c__String tipotransaccion;
  rosidl_runtime_c__String fechatransaccion;
  rosidl_runtime_c__String iduser;
  rosidl_runtime_c__String logproceso;
} my_mas__msg__Auditor;

// Struct for a sequence of my_mas__msg__Auditor.
typedef struct my_mas__msg__Auditor__Sequence
{
  my_mas__msg__Auditor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__Auditor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__AUDITOR__STRUCT_H_
