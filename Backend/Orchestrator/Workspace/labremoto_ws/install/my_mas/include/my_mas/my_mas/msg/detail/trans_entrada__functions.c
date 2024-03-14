// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_mas:msg/TransEntrada.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/trans_entrada__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `tipotransaccion`
// Member `status`
// Member `idestudiante`
// Member `idsesion`
// Member `descripcion`
#include "rosidl_runtime_c/string_functions.h"

bool
my_mas__msg__TransEntrada__init(my_mas__msg__TransEntrada * msg)
{
  if (!msg) {
    return false;
  }
  // tipotransaccion
  if (!rosidl_runtime_c__String__init(&msg->tipotransaccion)) {
    my_mas__msg__TransEntrada__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    my_mas__msg__TransEntrada__fini(msg);
    return false;
  }
  // idestudiante
  if (!rosidl_runtime_c__String__init(&msg->idestudiante)) {
    my_mas__msg__TransEntrada__fini(msg);
    return false;
  }
  // idsesion
  if (!rosidl_runtime_c__String__init(&msg->idsesion)) {
    my_mas__msg__TransEntrada__fini(msg);
    return false;
  }
  // descripcion
  if (!rosidl_runtime_c__String__init(&msg->descripcion)) {
    my_mas__msg__TransEntrada__fini(msg);
    return false;
  }
  return true;
}

void
my_mas__msg__TransEntrada__fini(my_mas__msg__TransEntrada * msg)
{
  if (!msg) {
    return;
  }
  // tipotransaccion
  rosidl_runtime_c__String__fini(&msg->tipotransaccion);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // idestudiante
  rosidl_runtime_c__String__fini(&msg->idestudiante);
  // idsesion
  rosidl_runtime_c__String__fini(&msg->idsesion);
  // descripcion
  rosidl_runtime_c__String__fini(&msg->descripcion);
}

bool
my_mas__msg__TransEntrada__are_equal(const my_mas__msg__TransEntrada * lhs, const my_mas__msg__TransEntrada * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tipotransaccion
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tipotransaccion), &(rhs->tipotransaccion)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // idestudiante
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->idestudiante), &(rhs->idestudiante)))
  {
    return false;
  }
  // idsesion
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->idsesion), &(rhs->idsesion)))
  {
    return false;
  }
  // descripcion
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->descripcion), &(rhs->descripcion)))
  {
    return false;
  }
  return true;
}

bool
my_mas__msg__TransEntrada__copy(
  const my_mas__msg__TransEntrada * input,
  my_mas__msg__TransEntrada * output)
{
  if (!input || !output) {
    return false;
  }
  // tipotransaccion
  if (!rosidl_runtime_c__String__copy(
      &(input->tipotransaccion), &(output->tipotransaccion)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // idestudiante
  if (!rosidl_runtime_c__String__copy(
      &(input->idestudiante), &(output->idestudiante)))
  {
    return false;
  }
  // idsesion
  if (!rosidl_runtime_c__String__copy(
      &(input->idsesion), &(output->idsesion)))
  {
    return false;
  }
  // descripcion
  if (!rosidl_runtime_c__String__copy(
      &(input->descripcion), &(output->descripcion)))
  {
    return false;
  }
  return true;
}

my_mas__msg__TransEntrada *
my_mas__msg__TransEntrada__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__TransEntrada * msg = (my_mas__msg__TransEntrada *)allocator.allocate(sizeof(my_mas__msg__TransEntrada), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_mas__msg__TransEntrada));
  bool success = my_mas__msg__TransEntrada__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_mas__msg__TransEntrada__destroy(my_mas__msg__TransEntrada * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_mas__msg__TransEntrada__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_mas__msg__TransEntrada__Sequence__init(my_mas__msg__TransEntrada__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__TransEntrada * data = NULL;

  if (size) {
    data = (my_mas__msg__TransEntrada *)allocator.zero_allocate(size, sizeof(my_mas__msg__TransEntrada), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_mas__msg__TransEntrada__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_mas__msg__TransEntrada__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_mas__msg__TransEntrada__Sequence__fini(my_mas__msg__TransEntrada__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_mas__msg__TransEntrada__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_mas__msg__TransEntrada__Sequence *
my_mas__msg__TransEntrada__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__TransEntrada__Sequence * array = (my_mas__msg__TransEntrada__Sequence *)allocator.allocate(sizeof(my_mas__msg__TransEntrada__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_mas__msg__TransEntrada__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_mas__msg__TransEntrada__Sequence__destroy(my_mas__msg__TransEntrada__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_mas__msg__TransEntrada__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_mas__msg__TransEntrada__Sequence__are_equal(const my_mas__msg__TransEntrada__Sequence * lhs, const my_mas__msg__TransEntrada__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_mas__msg__TransEntrada__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_mas__msg__TransEntrada__Sequence__copy(
  const my_mas__msg__TransEntrada__Sequence * input,
  my_mas__msg__TransEntrada__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_mas__msg__TransEntrada);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_mas__msg__TransEntrada * data =
      (my_mas__msg__TransEntrada *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_mas__msg__TransEntrada__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_mas__msg__TransEntrada__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_mas__msg__TransEntrada__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
