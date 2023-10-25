// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:msg/SensorMeasurment.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__STRUCT_H_
#define MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SensorMeasurment in the package my_mas.
typedef struct my_mas__msg__SensorMeasurment
{
  float temperature;
  rosidl_runtime_c__String name;
} my_mas__msg__SensorMeasurment;

// Struct for a sequence of my_mas__msg__SensorMeasurment.
typedef struct my_mas__msg__SensorMeasurment__Sequence
{
  my_mas__msg__SensorMeasurment * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__msg__SensorMeasurment__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__STRUCT_H_
