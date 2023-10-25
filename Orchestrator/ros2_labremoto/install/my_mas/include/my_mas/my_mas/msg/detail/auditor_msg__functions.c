// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_mas:msg/AuditorMsg.idl
// generated code does not contain a copyright notice
#include "my_mas/msg/detail/auditor_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `id_node`
// Member `name_node`
// Member `type_transaction`
// Member `date_process`
// Member `id_user`
// Member `log_process`
#include "rosidl_runtime_c/string_functions.h"

bool
my_mas__msg__AuditorMsg__init(my_mas__msg__AuditorMsg * msg)
{
  if (!msg) {
    return false;
  }
  // id_node
  if (!rosidl_runtime_c__String__init(&msg->id_node)) {
    my_mas__msg__AuditorMsg__fini(msg);
    return false;
  }
  // name_node
  if (!rosidl_runtime_c__String__init(&msg->name_node)) {
    my_mas__msg__AuditorMsg__fini(msg);
    return false;
  }
  // type_transaction
  if (!rosidl_runtime_c__String__init(&msg->type_transaction)) {
    my_mas__msg__AuditorMsg__fini(msg);
    return false;
  }
  // date_process
  if (!rosidl_runtime_c__String__init(&msg->date_process)) {
    my_mas__msg__AuditorMsg__fini(msg);
    return false;
  }
  // id_user
  if (!rosidl_runtime_c__String__init(&msg->id_user)) {
    my_mas__msg__AuditorMsg__fini(msg);
    return false;
  }
  // log_process
  if (!rosidl_runtime_c__String__init(&msg->log_process)) {
    my_mas__msg__AuditorMsg__fini(msg);
    return false;
  }
  return true;
}

void
my_mas__msg__AuditorMsg__fini(my_mas__msg__AuditorMsg * msg)
{
  if (!msg) {
    return;
  }
  // id_node
  rosidl_runtime_c__String__fini(&msg->id_node);
  // name_node
  rosidl_runtime_c__String__fini(&msg->name_node);
  // type_transaction
  rosidl_runtime_c__String__fini(&msg->type_transaction);
  // date_process
  rosidl_runtime_c__String__fini(&msg->date_process);
  // id_user
  rosidl_runtime_c__String__fini(&msg->id_user);
  // log_process
  rosidl_runtime_c__String__fini(&msg->log_process);
}

bool
my_mas__msg__AuditorMsg__are_equal(const my_mas__msg__AuditorMsg * lhs, const my_mas__msg__AuditorMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id_node), &(rhs->id_node)))
  {
    return false;
  }
  // name_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name_node), &(rhs->name_node)))
  {
    return false;
  }
  // type_transaction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type_transaction), &(rhs->type_transaction)))
  {
    return false;
  }
  // date_process
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->date_process), &(rhs->date_process)))
  {
    return false;
  }
  // id_user
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id_user), &(rhs->id_user)))
  {
    return false;
  }
  // log_process
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->log_process), &(rhs->log_process)))
  {
    return false;
  }
  return true;
}

bool
my_mas__msg__AuditorMsg__copy(
  const my_mas__msg__AuditorMsg * input,
  my_mas__msg__AuditorMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // id_node
  if (!rosidl_runtime_c__String__copy(
      &(input->id_node), &(output->id_node)))
  {
    return false;
  }
  // name_node
  if (!rosidl_runtime_c__String__copy(
      &(input->name_node), &(output->name_node)))
  {
    return false;
  }
  // type_transaction
  if (!rosidl_runtime_c__String__copy(
      &(input->type_transaction), &(output->type_transaction)))
  {
    return false;
  }
  // date_process
  if (!rosidl_runtime_c__String__copy(
      &(input->date_process), &(output->date_process)))
  {
    return false;
  }
  // id_user
  if (!rosidl_runtime_c__String__copy(
      &(input->id_user), &(output->id_user)))
  {
    return false;
  }
  // log_process
  if (!rosidl_runtime_c__String__copy(
      &(input->log_process), &(output->log_process)))
  {
    return false;
  }
  return true;
}

my_mas__msg__AuditorMsg *
my_mas__msg__AuditorMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__AuditorMsg * msg = (my_mas__msg__AuditorMsg *)allocator.allocate(sizeof(my_mas__msg__AuditorMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_mas__msg__AuditorMsg));
  bool success = my_mas__msg__AuditorMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_mas__msg__AuditorMsg__destroy(my_mas__msg__AuditorMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_mas__msg__AuditorMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_mas__msg__AuditorMsg__Sequence__init(my_mas__msg__AuditorMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__AuditorMsg * data = NULL;

  if (size) {
    data = (my_mas__msg__AuditorMsg *)allocator.zero_allocate(size, sizeof(my_mas__msg__AuditorMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_mas__msg__AuditorMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_mas__msg__AuditorMsg__fini(&data[i - 1]);
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
my_mas__msg__AuditorMsg__Sequence__fini(my_mas__msg__AuditorMsg__Sequence * array)
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
      my_mas__msg__AuditorMsg__fini(&array->data[i]);
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

my_mas__msg__AuditorMsg__Sequence *
my_mas__msg__AuditorMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_mas__msg__AuditorMsg__Sequence * array = (my_mas__msg__AuditorMsg__Sequence *)allocator.allocate(sizeof(my_mas__msg__AuditorMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_mas__msg__AuditorMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_mas__msg__AuditorMsg__Sequence__destroy(my_mas__msg__AuditorMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_mas__msg__AuditorMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_mas__msg__AuditorMsg__Sequence__are_equal(const my_mas__msg__AuditorMsg__Sequence * lhs, const my_mas__msg__AuditorMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_mas__msg__AuditorMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_mas__msg__AuditorMsg__Sequence__copy(
  const my_mas__msg__AuditorMsg__Sequence * input,
  my_mas__msg__AuditorMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_mas__msg__AuditorMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_mas__msg__AuditorMsg * data =
      (my_mas__msg__AuditorMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_mas__msg__AuditorMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_mas__msg__AuditorMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_mas__msg__AuditorMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
