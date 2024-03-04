# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_mas:msg/Auditor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Auditor(type):
    """Metaclass of message 'Auditor'."""

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
                'my_mas.msg.Auditor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__auditor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__auditor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__auditor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__auditor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__auditor

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Auditor(metaclass=Metaclass_Auditor):
    """Message class 'Auditor'."""

    __slots__ = [
        '_idnode',
        '_namenode',
        '_tipotransaccion',
        '_fechatransaccion',
        '_iduser',
        '_logproceso',
    ]

    _fields_and_field_types = {
        'idnode': 'int64',
        'namenode': 'string',
        'tipotransaccion': 'string',
        'fechatransaccion': 'string',
        'iduser': 'string',
        'logproceso': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.idnode = kwargs.get('idnode', int())
        self.namenode = kwargs.get('namenode', str())
        self.tipotransaccion = kwargs.get('tipotransaccion', str())
        self.fechatransaccion = kwargs.get('fechatransaccion', str())
        self.iduser = kwargs.get('iduser', str())
        self.logproceso = kwargs.get('logproceso', str())

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
        if self.idnode != other.idnode:
            return False
        if self.namenode != other.namenode:
            return False
        if self.tipotransaccion != other.tipotransaccion:
            return False
        if self.fechatransaccion != other.fechatransaccion:
            return False
        if self.iduser != other.iduser:
            return False
        if self.logproceso != other.logproceso:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def idnode(self):
        """Message field 'idnode'."""
        return self._idnode

    @idnode.setter
    def idnode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'idnode' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'idnode' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._idnode = value

    @builtins.property
    def namenode(self):
        """Message field 'namenode'."""
        return self._namenode

    @namenode.setter
    def namenode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'namenode' field must be of type 'str'"
        self._namenode = value

    @builtins.property
    def tipotransaccion(self):
        """Message field 'tipotransaccion'."""
        return self._tipotransaccion

    @tipotransaccion.setter
    def tipotransaccion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'tipotransaccion' field must be of type 'str'"
        self._tipotransaccion = value

    @builtins.property
    def fechatransaccion(self):
        """Message field 'fechatransaccion'."""
        return self._fechatransaccion

    @fechatransaccion.setter
    def fechatransaccion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fechatransaccion' field must be of type 'str'"
        self._fechatransaccion = value

    @builtins.property
    def iduser(self):
        """Message field 'iduser'."""
        return self._iduser

    @iduser.setter
    def iduser(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'iduser' field must be of type 'str'"
        self._iduser = value

    @builtins.property
    def logproceso(self):
        """Message field 'logproceso'."""
        return self._logproceso

    @logproceso.setter
    def logproceso(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'logproceso' field must be of type 'str'"
        self._logproceso = value
