# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_mas:msg/Operacion.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Operacion(type):
    """Metaclass of message 'Operacion'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_mas')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_mas.msg.Operacion')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__operacion
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__operacion
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__operacion
            cls._TYPE_SUPPORT = module.type_support_msg__msg__operacion
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__operacion

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Operacion(metaclass=Metaclass_Operacion):
    """Message class 'Operacion'."""

    __slots__ = [
        '_nameoperacion',
        '_descoperacion',
        '_estatusoperacion',
        '_fechaoperacion',
    ]

    _fields_and_field_types = {
        'nameoperacion': 'string',
        'descoperacion': 'string',
        'estatusoperacion': 'string',
        'fechaoperacion': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nameoperacion = kwargs.get('nameoperacion', str())
        self.descoperacion = kwargs.get('descoperacion', str())
        self.estatusoperacion = kwargs.get('estatusoperacion', str())
        self.fechaoperacion = kwargs.get('fechaoperacion', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.nameoperacion != other.nameoperacion:
            return False
        if self.descoperacion != other.descoperacion:
            return False
        if self.estatusoperacion != other.estatusoperacion:
            return False
        if self.fechaoperacion != other.fechaoperacion:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nameoperacion(self):
        """Message field 'nameoperacion'."""
        return self._nameoperacion

    @nameoperacion.setter
    def nameoperacion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'nameoperacion' field must be of type 'str'"
        self._nameoperacion = value

    @builtins.property
    def descoperacion(self):
        """Message field 'descoperacion'."""
        return self._descoperacion

    @descoperacion.setter
    def descoperacion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'descoperacion' field must be of type 'str'"
        self._descoperacion = value

    @builtins.property
    def estatusoperacion(self):
        """Message field 'estatusoperacion'."""
        return self._estatusoperacion

    @estatusoperacion.setter
    def estatusoperacion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'estatusoperacion' field must be of type 'str'"
        self._estatusoperacion = value

    @builtins.property
    def fechaoperacion(self):
        """Message field 'fechaoperacion'."""
        return self._fechaoperacion

    @fechaoperacion.setter
    def fechaoperacion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fechaoperacion' field must be of type 'str'"
        self._fechaoperacion = value
