// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/TransEntrada.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__TRANS_ENTRADA__STRUCT_H_
#define MY_MAS__MSG__DETAIL__TRANS_ENTRADA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tipotransaccion'
// Member 'status'
// Member 'idestudiante'
// Member 'idsesion'
// Member 'descripcion'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TransEntrada in the package my_mas.
typedef struct my_mas__msg__TransEntrada
{
  rosidl_runtime_c__String tipotransaccion;
  rosidl_runtime_c__String status;
  rosidl_runtime_c__String idestudiante;
  rosidl_runtime_c__String idsesion;
  rosidl_runtime_c__String descripcion;
} my_mas__msg__TransEntrada;

// Struct for a sequence of my_mas__msg__TransEntrada.
typedef struct my_mas__msg__TransEntrada__Sequence
{
  my_mas__msg__TransEntrada * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__TransEntrada__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__TRANS_ENTRADA__STRUCT_H_
