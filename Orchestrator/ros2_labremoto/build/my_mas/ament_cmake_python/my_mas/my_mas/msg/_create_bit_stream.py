# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_mas:msg/CreateBitStream.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CreateBitStream(type):
    """Metaclass of message 'CreateBitStream'."""

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
                'my_mas.msg.CreateBitStream')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__create_bit_stream
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__create_bit_stream
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__create_bit_stream
            cls._TYPE_SUPPORT = module.type_support_msg__msg__create_bit_stream
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__create_bit_stream

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CreateBitStream(metaclass=Metaclass_CreateBitStream):
    """Message class 'CreateBitStream'."""

    __slots__ = [
        '_path_vhdl',
        '_path_constrains',
        '_path_savefolder',
    ]

    _fields_and_field_types = {
        'path_vhdl': 'string',
        'path_constrains': 'string',
        'path_savefolder': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.path_vhdl = kwargs.get('path_vhdl', str())
        self.path_constrains = kwargs.get('path_constrains', str())
        self.path_savefolder = kwargs.get('path_savefolder', str())

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
        if self.path_vhdl != other.path_vhdl:
            return False
        if self.path_constrains != other.path_constrains:
            return False
        if self.path_savefolder != other.path_savefolder:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def path_vhdl(self):
        """Message field 'path_vhdl'."""
        return self._path_vhdl

    @path_vhdl.setter
    def path_vhdl(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'path_vhdl' field must be of type 'str'"
        self._path_vhdl = value

    @builtins.property
    def path_constrains(self):
        """Message field 'path_constrains'."""
        return self._path_constrains

    @path_constrains.setter
    def path_constrains(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'path_constrains' field must be of type 'str'"
        self._path_constrains = value

    @builtins.property
    def path_savefolder(self):
        """Message field 'path_savefolder'."""
        return self._path_savefolder

    @path_savefolder.setter
    def path_savefolder(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'path_savefolder' field must be of type 'str'"
        self._path_savefolder = value
