// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_mas:msg/Contrato.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "my_mas/msg/detail/contrato__struct.h"
#include "my_mas/msg/detail/contrato__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_mas__msg__contrato__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[30];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("my_mas.msg._contrato.Contrato", full_classname_dest, 29) == 0);
  }
  my_mas__msg__Contrato * ros_message = _ros_message;
  {  // idcontrato
    PyObject * field = PyObject_GetAttrString(_pymsg, "idcontrato");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->idcontrato = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // nombrecontrato
    PyObject * field = PyObject_GetAttrString(_pymsg, "nombrecontrato");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->nombrecontrato, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // tipocontrato
    PyObject * field = PyObject_GetAttrString(_pymsg, "tipocontrato");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->tipocontrato, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // desccontrato
    PyObject * field = PyObject_GetAttrString(_pymsg, "desccontrato");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->desccontrato, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // especificacioncontrato
    PyObject * field = PyObject_GetAttrString(_pymsg, "especificacioncontrato");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->especificacioncontrato, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_mas__msg__contrato__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Contrato */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_mas.msg._contrato");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Contrato");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_mas__msg__Contrato * ros_message = (my_mas__msg__Contrato *)raw_ros_message;
  {  // idcontrato
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->idcontrato);
    {
      int rc = PyObject_SetAttrString(_pymessage, "idcontrato", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nombrecontrato
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->nombrecontrato.data,
      strlen(ros_message->nombrecontrato.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "nombrecontrato", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tipocontrato
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->tipocontrato.data,
      strlen(ros_message->tipocontrato.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tipocontrato", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // desccontrato
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->desccontrato.data,
      strlen(ros_message->desccontrato.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "desccontrato", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // especificacioncontrato
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->especificacioncontrato.data,
      strlen(ros_message->especificacioncontrato.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "especificacioncontrato", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
