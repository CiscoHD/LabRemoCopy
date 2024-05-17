// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_mas:msg/CreateBitStream.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/create_bit_stream__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `path_vhdl`
// Member `path_constrains`
// Member `path_savefolder`
#include "rosidl_runtime_c/string_functions.h"

bool
my_mas__msg__CreateBitStream__init(my_mas__msg__CreateBitStream * msg)
{
  if (!msg) {
    return false;
  }
  // path_vhdl
  if (!rosidl_runtime_c__String__init(&msg->path_vhdl)) {
    my_mas__msg__CreateBitStream__fini(msg);
    return false;
  }
  // path_constrains
  if (!rosidl_runtime_c__String__init(&msg->path_constrains)) {
    my_mas__msg__CreateBitStream__fini(msg);
    return false;
  }
  // path_savefolder
  if (!rosidl_runtime_c__String__init(&msg->path_savefolder)) {
    my_mas__msg__CreateBitStream__fini(msg);
    return false;
  }
  return true;
}

void
my_mas__msg__CreateBitStream__fini(my_mas__msg__CreateBitStream * msg)
{
  if (!msg) {
    return;
  }
  // path_vhdl
  rosidl_runtime_c__String__fini(&msg->path_vhdl);
  // path_constrains
  rosidl_runtime_c__String__fini(&msg->path_constrains);
  // path_savefolder
  rosidl_runtime_c__String__fini(&msg->path_savefolder);
}

bool
my_mas__msg__CreateBitStream__are_equal(const my_mas__msg__CreateBitStream * lhs, const my_mas__msg__CreateBitStream * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // path_vhdl
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->path_vhdl), &(rhs->path_vhdl)))
  {
    return false;
  }
  // path_constrains
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->path_constrains), &(rhs->path_constrains)))
  {
    return false;
  }
  // path_savefolder
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->path_savefolder), &(rhs->path_savefolder)))
  {
    return false;
  }
  return true;
}

bool
my_mas__msg__CreateBitStream__copy(
  const my_mas__msg__CreateBitStream * input,
  my_mas__msg__CreateBitStream * output)
{
  if (!input || !output) {
    return false;
  }
  // path_vhdl
  if (!rosidl_runtime_c__String__copy(
      &(input->path_vhdl), &(output->path_vhdl)))
  {
    return false;
  }
  // path_constrains
  if (!rosidl_runtime_c__String__copy(
      &(input->path_constrains), &(output->path_constrains)))
  {
    return false;
  }
  // path_savefolder
  if (!rosidl_runtime_c__String__copy(
      &(input->path_savefolder), &(output->path_savefolder)))
  {
    return false;
  }
  return true;
}

my_mas__msg__CreateBitStream *
my_mas__msg__CreateBitStream__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__CreateBitStream * msg = (my_mas__msg__CreateBitStream *)allocator.allocate(sizeof(my_mas__msg__CreateBitStream), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_mas__msg__CreateBitStream));
  bool success = my_mas__msg__CreateBitStream__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_mas__msg__CreateBitStream__destroy(my_mas__msg__CreateBitStream * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_mas__msg__CreateBitStream__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_mas__msg__CreateBitStream__Sequence__init(my_mas__msg__CreateBitStream__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__CreateBitStream * data = NULL;

  if (size) {
    data = (my_mas__msg__CreateBitStream *)allocator.zero_allocate(size, sizeof(my_mas__msg__CreateBitStream), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_mas__msg__CreateBitStream__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_mas__msg__CreateBitStream__fini(&data[i - 1]);
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
my_mas__msg__CreateBitStream__Sequence__fini(my_mas__msg__CreateBitStream__Sequence * array)
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
      my_mas__msg__CreateBitStream__fini(&array->data[i]);
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

my_mas__msg__CreateBitStream__Sequence *
my_mas__msg__CreateBitStream__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__CreateBitStream__Sequence * array = (my_mas__msg__CreateBitStream__Sequence *)allocator.allocate(sizeof(my_mas__msg__CreateBitStream__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_mas__msg__CreateBitStream__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_mas__msg__CreateBitStream__Sequence__destroy(my_mas__msg__CreateBitStream__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_mas__msg__CreateBitStream__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_mas__msg__CreateBitStream__Sequence__are_equal(const my_mas__msg__CreateBitStream__Sequence * lhs, const my_mas__msg__CreateBitStream__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_mas__msg__CreateBitStream__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_mas__msg__CreateBitStream__Sequence__copy(
  const my_mas__msg__CreateBitStream__Sequence * input,
  my_mas__msg__CreateBitStream__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_mas__msg__CreateBitStream);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_mas__msg__CreateBitStream * data =
      (my_mas__msg__CreateBitStream *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_mas__msg__CreateBitStream__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_mas__msg__CreateBitStream__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_mas__msg__CreateBitStream__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
