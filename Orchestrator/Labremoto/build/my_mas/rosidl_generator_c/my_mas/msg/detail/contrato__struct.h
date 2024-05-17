// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/Contrato.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CONTRATO__STRUCT_H_
#define MY_MAS__MSG__DETAIL__CONTRATO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'nombrecontrato'
// Member 'tipocontrato'
// Member 'desccontrato'
// Member 'especificacioncontrato'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Contrato in the package my_mas.
typedef struct my_mas__msg__Contrato
{
  int64_t idcontrato;
  rosidl_runtime_c__String nombrecontrato;
  rosidl_runtime_c__String tipocontrato;
  rosidl_runtime_c__String desccontrato;
  rosidl_runtime_c__String especificacioncontrato;
} my_mas__msg__Contrato;

// Struct for a sequence of my_mas__msg__Contrato.
typedef struct my_mas__msg__Contrato__Sequence
{
  my_mas__msg__Contrato * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__Contrato__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__CONTRATO__STRUCT_H_
