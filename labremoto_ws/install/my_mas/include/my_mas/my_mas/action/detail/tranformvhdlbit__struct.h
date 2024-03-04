// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_mas:action/Tranformvhdlbit.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__ACTION__DETAIL__TRANFORMVHDLBIT__STRUCT_H_
#define MY_MAS__ACTION__DETAIL__TRANFORMVHDLBIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_vhdl'
// Member 'path_constrains'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_Goal
{
  rosidl_runtime_c__String path_vhdl;
  rosidl_runtime_c__String path_constrains;
} my_mas__action__Tranformvhdlbit_Goal;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_Goal.
typedef struct my_mas__action__Tranformvhdlbit_Goal__Sequence
{
  my_mas__action__Tranformvhdlbit_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status_final'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_Result
{
  rosidl_runtime_c__String status_final;
} my_mas__action__Tranformvhdlbit_Result;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_Result.
typedef struct my_mas__action__Tranformvhdlbit_Result__Sequence
{
  my_mas__action__Tranformvhdlbit_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_Feedback
{
  rosidl_runtime_c__String status;
} my_mas__action__Tranformvhdlbit_Feedback;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_Feedback.
typedef struct my_mas__action__Tranformvhdlbit_Feedback__Sequence
{
  my_mas__action__Tranformvhdlbit_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "my_mas/action/detail/tranformvhdlbit__struct.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_mas__action__Tranformvhdlbit_Goal goal;
} my_mas__action__Tranformvhdlbit_SendGoal_Request;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_SendGoal_Request.
typedef struct my_mas__action__Tranformvhdlbit_SendGoal_Request__Sequence
{
  my_mas__action__Tranformvhdlbit_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} my_mas__action__Tranformvhdlbit_SendGoal_Response;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_SendGoal_Response.
typedef struct my_mas__action__Tranformvhdlbit_SendGoal_Response__Sequence
{
  my_mas__action__Tranformvhdlbit_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} my_mas__action__Tranformvhdlbit_GetResult_Request;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_GetResult_Request.
typedef struct my_mas__action__Tranformvhdlbit_GetResult_Request__Sequence
{
  my_mas__action__Tranformvhdlbit_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "my_mas/action/detail/tranformvhdlbit__struct.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_GetResult_Response
{
  int8_t status;
  my_mas__action__Tranformvhdlbit_Result result;
} my_mas__action__Tranformvhdlbit_GetResult_Response;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_GetResult_Response.
typedef struct my_mas__action__Tranformvhdlbit_GetResult_Response__Sequence
{
  my_mas__action__Tranformvhdlbit_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "my_mas/action/detail/tranformvhdlbit__struct.h"

/// Struct defined in action/Tranformvhdlbit in the package my_mas.
typedef struct my_mas__action__Tranformvhdlbit_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_mas__action__Tranformvhdlbit_Feedback feedback;
} my_mas__action__Tranformvhdlbit_FeedbackMessage;

// Struct for a sequence of my_mas__action__Tranformvhdlbit_FeedbackMessage.
typedef struct my_mas__action__Tranformvhdlbit_FeedbackMessage__Sequence
{
  my_mas__action__Tranformvhdlbit_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_mas__action__Tranformvhdlbit_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MAS__ACTION__DETAIL__TRANFORMVHDLBIT__STRUCT_H_
