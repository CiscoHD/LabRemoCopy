// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_mas:msg/Contrato.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__CONTRATO__FUNCTIONS_H_
#define MY_MAS__MSG__DETAIL__CONTRATO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "my_mas/msg/rosidl_generator_c__visibility_control.h"

#include "my_mas/msg/detail/contrato__struct.h"

/// Initialize msg/Contrato message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_mas__msg__Contrato
 * )) before or use
 * my_mas__msg__Contrato__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__msg__Contrato__init(my_mas__msg__Contrato * msg);

/// Finalize msg/Contrato message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__msg__Contrato__fini(my_mas__msg__Contrato * msg);

/// Create msg/Contrato message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_mas__msg__Contrato__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
my_mas__msg__Contrato *
my_mas__msg__Contrato__create();

/// Destroy msg/Contrato message.
/**
 * It calls
 * my_mas__msg__Contrato__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__msg__Contrato__destroy(my_mas__msg__Contrato * msg);

/// Check for msg/Contrato message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__msg__Contrato__are_equal(const my_mas__msg__Contrato * lhs, const my_mas__msg__Contrato * rhs);

/// Copy a msg/Contrato message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__msg__Contrato__copy(
  const my_mas__msg__Contrato * input,
  my_mas__msg__Contrato * output);

/// Initialize array of msg/Contrato messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_mas__msg__Contrato__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__msg__Contrato__Sequence__init(my_mas__msg__Contrato__Sequence * array, size_t size);

/// Finalize array of msg/Contrato messages.
/**
 * It calls
 * my_mas__msg__Contrato__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__msg__Contrato__Sequence__fini(my_mas__msg__Contrato__Sequence * array);

/// Create array of msg/Contrato messages.
/**
 * It allocates the memory for the array and calls
 * my_mas__msg__Contrato__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
my_mas__msg__Contrato__Sequence *
my_mas__msg__Contrato__Sequence__create(size_t size);

/// Destroy array of msg/Contrato messages.
/**
 * It calls
 * my_mas__msg__Contrato__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__msg__Contrato__Sequence__destroy(my_mas__msg__Contrato__Sequence * array);

/// Check for msg/Contrato message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__msg__Contrato__Sequence__are_equal(const my_mas__msg__Contrato__Sequence * lhs, const my_mas__msg__Contrato__Sequence * rhs);

/// Copy an array of msg/Contrato messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__msg__Contrato__Sequence__copy(
  const my_mas__msg__Contrato__Sequence * input,
  my_mas__msg__Contrato__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__MSG__DETAIL__CONTRATO__FUNCTIONS_H_
