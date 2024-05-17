// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_mas:srv/LoadFile.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__SRV__DETAIL__LOAD_FILE__FUNCTIONS_H_
#define MY_MAS__SRV__DETAIL__LOAD_FILE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "my_mas/msg/rosidl_generator_c__visibility_control.h"

#include "my_mas/srv/detail/load_file__struct.h"

/// Initialize srv/LoadFile message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_mas__srv__LoadFile_Request
 * )) before or use
 * my_mas__srv__LoadFile_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Request__init(my_mas__srv__LoadFile_Request * msg);

/// Finalize srv/LoadFile message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Request__fini(my_mas__srv__LoadFile_Request * msg);

/// Create srv/LoadFile message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_mas__srv__LoadFile_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
my_mas__srv__LoadFile_Request *
my_mas__srv__LoadFile_Request__create();

/// Destroy srv/LoadFile message.
/**
 * It calls
 * my_mas__srv__LoadFile_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Request__destroy(my_mas__srv__LoadFile_Request * msg);

/// Check for srv/LoadFile message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Request__are_equal(const my_mas__srv__LoadFile_Request * lhs, const my_mas__srv__LoadFile_Request * rhs);

/// Copy a srv/LoadFile message.
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
my_mas__srv__LoadFile_Request__copy(
  const my_mas__srv__LoadFile_Request * input,
  my_mas__srv__LoadFile_Request * output);

/// Initialize array of srv/LoadFile messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_mas__srv__LoadFile_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Request__Sequence__init(my_mas__srv__LoadFile_Request__Sequence * array, size_t size);

/// Finalize array of srv/LoadFile messages.
/**
 * It calls
 * my_mas__srv__LoadFile_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Request__Sequence__fini(my_mas__srv__LoadFile_Request__Sequence * array);

/// Create array of srv/LoadFile messages.
/**
 * It allocates the memory for the array and calls
 * my_mas__srv__LoadFile_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
my_mas__srv__LoadFile_Request__Sequence *
my_mas__srv__LoadFile_Request__Sequence__create(size_t size);

/// Destroy array of srv/LoadFile messages.
/**
 * It calls
 * my_mas__srv__LoadFile_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Request__Sequence__destroy(my_mas__srv__LoadFile_Request__Sequence * array);

/// Check for srv/LoadFile message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Request__Sequence__are_equal(const my_mas__srv__LoadFile_Request__Sequence * lhs, const my_mas__srv__LoadFile_Request__Sequence * rhs);

/// Copy an array of srv/LoadFile messages.
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
my_mas__srv__LoadFile_Request__Sequence__copy(
  const my_mas__srv__LoadFile_Request__Sequence * input,
  my_mas__srv__LoadFile_Request__Sequence * output);

/// Initialize srv/LoadFile message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_mas__srv__LoadFile_Response
 * )) before or use
 * my_mas__srv__LoadFile_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Response__init(my_mas__srv__LoadFile_Response * msg);

/// Finalize srv/LoadFile message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Response__fini(my_mas__srv__LoadFile_Response * msg);

/// Create srv/LoadFile message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_mas__srv__LoadFile_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
my_mas__srv__LoadFile_Response *
my_mas__srv__LoadFile_Response__create();

/// Destroy srv/LoadFile message.
/**
 * It calls
 * my_mas__srv__LoadFile_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Response__destroy(my_mas__srv__LoadFile_Response * msg);

/// Check for srv/LoadFile message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Response__are_equal(const my_mas__srv__LoadFile_Response * lhs, const my_mas__srv__LoadFile_Response * rhs);

/// Copy a srv/LoadFile message.
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
my_mas__srv__LoadFile_Response__copy(
  const my_mas__srv__LoadFile_Response * input,
  my_mas__srv__LoadFile_Response * output);

/// Initialize array of srv/LoadFile messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_mas__srv__LoadFile_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Response__Sequence__init(my_mas__srv__LoadFile_Response__Sequence * array, size_t size);

/// Finalize array of srv/LoadFile messages.
/**
 * It calls
 * my_mas__srv__LoadFile_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Response__Sequence__fini(my_mas__srv__LoadFile_Response__Sequence * array);

/// Create array of srv/LoadFile messages.
/**
 * It allocates the memory for the array and calls
 * my_mas__srv__LoadFile_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
my_mas__srv__LoadFile_Response__Sequence *
my_mas__srv__LoadFile_Response__Sequence__create(size_t size);

/// Destroy array of srv/LoadFile messages.
/**
 * It calls
 * my_mas__srv__LoadFile_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
void
my_mas__srv__LoadFile_Response__Sequence__destroy(my_mas__srv__LoadFile_Response__Sequence * array);

/// Check for srv/LoadFile message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_mas
bool
my_mas__srv__LoadFile_Response__Sequence__are_equal(const my_mas__srv__LoadFile_Response__Sequence * lhs, const my_mas__srv__LoadFile_Response__Sequence * rhs);

/// Copy an array of srv/LoadFile messages.
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
my_mas__srv__LoadFile_Response__Sequence__copy(
  const my_mas__srv__LoadFile_Response__Sequence * input,
  my_mas__srv__LoadFile_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__SRV__DETAIL__LOAD_FILE__FUNCTIONS_H_
