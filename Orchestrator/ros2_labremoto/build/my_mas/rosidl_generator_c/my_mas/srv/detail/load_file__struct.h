// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:srv/LoadFile.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILE__STRUCT_H_
#define MY_MAS__SRV__DETAIL__LOAD_FILE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/LoadFile in the package my_mas.
typedef struct my_mas__srv__LoadFile_Request
{
  int64_t a;
  int64_t b;
} my_mas__srv__LoadFile_Request;

// Struct for a sequence of my_mas__srv__LoadFile_Request.
typedef struct my_mas__srv__LoadFile_Request__Sequence
{
  my_mas__srv__LoadFile_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__srv__LoadFile_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/LoadFile in the package my_mas.
typedef struct my_mas__srv__LoadFile_Response
{
  int64_t sum;
} my_mas__srv__LoadFile_Response;

// Struct for a sequence of my_mas__srv__LoadFile_Response.
typedef struct my_mas__srv__LoadFile_Response__Sequence
{
  my_mas__srv__LoadFile_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__srv__LoadFile_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILE__STRUCT_H_
