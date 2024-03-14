// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/Operacion.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__OPERACION__STRUCT_H_
#define MY_MAS__MSG__DETAIL__OPERACION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'nameoperacion'
// Member 'descoperacion'
// Member 'estatusoperacion'
// Member 'fechaoperacion'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Operacion in the package my_mas.
typedef struct my_mas__msg__Operacion
{
  rosidl_runtime_c__String nameoperacion;
  rosidl_runtime_c__String descoperacion;
  rosidl_runtime_c__String estatusoperacion;
  rosidl_runtime_c__String fechaoperacion;
} my_mas__msg__Operacion;

// Struct for a sequence of my_mas__msg__Operacion.
typedef struct my_mas__msg__Operacion__Sequence
{
  my_mas__msg__Operacion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__Operacion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__OPERACION__STRUCT_H_
