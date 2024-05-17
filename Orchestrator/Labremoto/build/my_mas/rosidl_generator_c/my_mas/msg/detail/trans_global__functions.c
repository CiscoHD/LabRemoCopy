// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_mas:msg/TransGlobal.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/trans_global__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `resultado`
// Member `status`
// Member `name_node`
// Member `fecha`
// Member `folio`
#include "rosidl_runtime_c/string_functions.h"

bool
my_mas__msg__TransGlobal__init(my_mas__msg__TransGlobal * msg)
{
  if (!msg) {
    return false;
  }
  // resultado
  if (!rosidl_runtime_c__String__init(&msg->resultado)) {
    my_mas__msg__TransGlobal__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    my_mas__msg__TransGlobal__fini(msg);
    return false;
  }
  // name_node
  if (!rosidl_runtime_c__String__init(&msg->name_node)) {
    my_mas__msg__TransGlobal__fini(msg);
    return false;
  }
  // fecha
  if (!rosidl_runtime_c__String__init(&msg->fecha)) {
    my_mas__msg__TransGlobal__fini(msg);
    return false;
  }
  // folio
  if (!rosidl_runtime_c__String__init(&msg->folio)) {
    my_mas__msg__TransGlobal__fini(msg);
    return false;
  }
  return true;
}

void
my_mas__msg__TransGlobal__fini(my_mas__msg__TransGlobal * msg)
{
  if (!msg) {
    return;
  }
  // resultado
  rosidl_runtime_c__String__fini(&msg->resultado);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // name_node
  rosidl_runtime_c__String__fini(&msg->name_node);
  // fecha
  rosidl_runtime_c__String__fini(&msg->fecha);
  // folio
  rosidl_runtime_c__String__fini(&msg->folio);
}

bool
my_mas__msg__TransGlobal__are_equal(const my_mas__msg__TransGlobal * lhs, const my_mas__msg__TransGlobal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // resultado
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->resultado), &(rhs->resultado)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // name_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name_node), &(rhs->name_node)))
  {
    return false;
  }
  // fecha
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fecha), &(rhs->fecha)))
  {
    return false;
  }
  // folio
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->folio), &(rhs->folio)))
  {
    return false;
  }
  return true;
}

bool
my_mas__msg__TransGlobal__copy(
  const my_mas__msg__TransGlobal * input,
  my_mas__msg__TransGlobal * output)
{
  if (!input || !output) {
    return false;
  }
  // resultado
  if (!rosidl_runtime_c__String__copy(
      &(input->resultado), &(output->resultado)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // name_node
  if (!rosidl_runtime_c__String__copy(
      &(input->name_node), &(output->name_node)))
  {
    return false;
  }
  // fecha
  if (!rosidl_runtime_c__String__copy(
      &(input->fecha), &(output->fecha)))
  {
    return false;
  }
  // folio
  if (!rosidl_runtime_c__String__copy(
      &(input->folio), &(output->folio)))
  {
    return false;
  }
  return true;
}

my_mas__msg__TransGlobal *
my_mas__msg__TransGlobal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__TransGlobal * msg = (my_mas__msg__TransGlobal *)allocator.allocate(sizeof(my_mas__msg__TransGlobal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_mas__msg__TransGlobal));
  bool success = my_mas__msg__TransGlobal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_mas__msg__TransGlobal__destroy(my_mas__msg__TransGlobal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_mas__msg__TransGlobal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_mas__msg__TransGlobal__Sequence__init(my_mas__msg__TransGlobal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__TransGlobal * data = NULL;

  if (size) {
    data = (my_mas__msg__TransGlobal *)allocator.zero_allocate(size, sizeof(my_mas__msg__TransGlobal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_mas__msg__TransGlobal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_mas__msg__TransGlobal__fini(&data[i - 1]);
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
my_mas__msg__TransGlobal__Sequence__fini(my_mas__msg__TransGlobal__Sequence * array)
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
      my_mas__msg__TransGlobal__fini(&array->data[i]);
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

my_mas__msg__TransGlobal__Sequence *
my_mas__msg__TransGlobal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__TransGlobal__Sequence * array = (my_mas__msg__TransGlobal__Sequence *)allocator.allocate(sizeof(my_mas__msg__TransGlobal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_mas__msg__TransGlobal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_mas__msg__TransGlobal__Sequence__destroy(my_mas__msg__TransGlobal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_mas__msg__TransGlobal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_mas__msg__TransGlobal__Sequence__are_equal(const my_mas__msg__TransGlobal__Sequence * lhs, const my_mas__msg__TransGlobal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_mas__msg__TransGlobal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_mas__msg__TransGlobal__Sequence__copy(
  const my_mas__msg__TransGlobal__Sequence * input,
  my_mas__msg__TransGlobal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_mas__msg__TransGlobal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_mas__msg__TransGlobal * data =
      (my_mas__msg__TransGlobal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_mas__msg__TransGlobal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_mas__msg__TransGlobal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_mas__msg__TransGlobal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
