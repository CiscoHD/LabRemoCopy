# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_mas:msg/TransEntrada.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TransEntrada(type):
    """Metaclass of message 'TransEntrada'."""

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
                'my_mas.msg.TransEntrada')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__trans_entrada
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__trans_entrada
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__trans_entrada
            cls._TYPE_SUPPORT = module.type_support_msg__msg__trans_entrada
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__trans_entrada

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TransEntrada(metaclass=Metaclass_TransEntrada):
    """Message class 'TransEntrada'."""

    __slots__ = [
        '_tipotransaccion',
        '_status',
        '_idestudiante',
        '_idsesion',
        '_descripcion',
    ]

    _fields_and_field_types = {
        'tipotransaccion': 'string',
        'status': 'string',
        'idestudiante': 'string',
        'idsesion': 'string',
        'descripcion': 'string',
    }

    SLOT_TYPES = (
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
        self.tipotransaccion = kwargs.get('tipotransaccion', str())
        self.status = kwargs.get('status', str())
        self.idestudiante = kwargs.get('idestudiante', str())
        self.idsesion = kwargs.get('idsesion', str())
        self.descripcion = kwargs.get('descripcion', str())

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
        if self.tipotransaccion != other.tipotransaccion:
            return False
        if self.status != other.status:
            return False
        if self.idestudiante != other.idestudiante:
            return False
        if self.idsesion != other.idsesion:
            return False
        if self.descripcion != other.descripcion:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value

    @builtins.property
    def idestudiante(self):
        """Message field 'idestudiante'."""
        return self._idestudiante

    @idestudiante.setter
    def idestudiante(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'idestudiante' field must be of type 'str'"
        self._idestudiante = value

    @builtins.property
    def idsesion(self):
        """Message field 'idsesion'."""
        return self._idsesion

    @idsesion.setter
    def idsesion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'idsesion' field must be of type 'str'"
        self._idsesion = value

    @builtins.property
    def descripcion(self):
        """Message field 'descripcion'."""
        return self._descripcion

    @descripcion.setter
    def descripcion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'descripcion' field must be of type 'str'"
        self._descripcion = value
