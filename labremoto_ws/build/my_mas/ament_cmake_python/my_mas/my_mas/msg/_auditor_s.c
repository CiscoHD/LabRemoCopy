// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_mas:msg/Auditor.idl
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
#include "my_mas/msg/detail/auditor__struct.h"
#include "my_mas/msg/detail/auditor__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_mas__msg__auditor__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[28];
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
    assert(strncmp("my_mas.msg._auditor.Auditor", full_classname_dest, 27) == 0);
  }
  my_mas__msg__Auditor * ros_message = _ros_message;
  {  // idnode
    PyObject * field = PyObject_GetAttrString(_pymsg, "idnode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->idnode = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // namenode
    PyObject * field = PyObject_GetAttrString(_pymsg, "namenode");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->namenode, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // tipotransaccion
    PyObject * field = PyObject_GetAttrString(_pymsg, "tipotransaccion");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->tipotransaccion, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // fechatransaccion
    PyObject * field = PyObject_GetAttrString(_pymsg, "fechatransaccion");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->fechatransaccion, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // iduser
    PyObject * field = PyObject_GetAttrString(_pymsg, "iduser");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->iduser, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // logproceso
    PyObject * field = PyObject_GetAttrString(_pymsg, "logproceso");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->logproceso, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_mas__msg__auditor__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Auditor */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_mas.msg._auditor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Auditor");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_mas__msg__Auditor * ros_message = (my_mas__msg__Auditor *)raw_ros_message;
  {  // idnode
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->idnode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "idnode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // namenode
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->namenode.data,
      strlen(ros_message->namenode.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "namenode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tipotransaccion
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->tipotransaccion.data,
      strlen(ros_message->tipotransaccion.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tipotransaccion", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fechatransaccion
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->fechatransaccion.data,
      strlen(ros_message->fechatransaccion.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "fechatransaccion", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // iduser
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->iduser.data,
      strlen(ros_message->iduser.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "iduser", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // logproceso
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->logproceso.data,
      strlen(ros_message->logproceso.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "logproceso", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
