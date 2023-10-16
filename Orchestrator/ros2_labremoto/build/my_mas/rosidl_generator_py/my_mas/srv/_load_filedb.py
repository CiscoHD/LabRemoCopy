# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_mas:srv/LoadFiledb.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LoadFiledb_Request(type):
    """Metaclass of message 'LoadFiledb_Request'."""

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
                'my_mas.srv.LoadFiledb_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__load_filedb__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__load_filedb__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__load_filedb__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__load_filedb__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__load_filedb__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadFiledb_Request(metaclass=Metaclass_LoadFiledb_Request):
    """Message class 'LoadFiledb_Request'."""

    __slots__ = [
        '_id_node',
        '_name_node',
        '_type_transaction',
        '_date_process',
        '_id_user',
        '_log_process',
    ]

    _fields_and_field_types = {
        'id_node': 'int32',
        'name_node': 'string',
        'type_transaction': 'string',
        'date_process': 'string',
        'id_user': 'int32',
        'log_process': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id_node = kwargs.get('id_node', int())
        self.name_node = kwargs.get('name_node', str())
        self.type_transaction = kwargs.get('type_transaction', str())
        self.date_process = kwargs.get('date_process', str())
        self.id_user = kwargs.get('id_user', int())
        self.log_process = kwargs.get('log_process', str())

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
        if self.id_node != other.id_node:
            return False
        if self.name_node != other.name_node:
            return False
        if self.type_transaction != other.type_transaction:
            return False
        if self.date_process != other.date_process:
            return False
        if self.id_user != other.id_user:
            return False
        if self.log_process != other.log_process:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def id_node(self):
        """Message field 'id_node'."""
        return self._id_node

    @id_node.setter
    def id_node(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id_node' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id_node' field must be an integer in [-2147483648, 2147483647]"
        self._id_node = value

    @builtins.property
    def name_node(self):
        """Message field 'name_node'."""
        return self._name_node

    @name_node.setter
    def name_node(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name_node' field must be of type 'str'"
        self._name_node = value

    @builtins.property
    def type_transaction(self):
        """Message field 'type_transaction'."""
        return self._type_transaction

    @type_transaction.setter
    def type_transaction(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'type_transaction' field must be of type 'str'"
        self._type_transaction = value

    @builtins.property
    def date_process(self):
        """Message field 'date_process'."""
        return self._date_process

    @date_process.setter
    def date_process(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'date_process' field must be of type 'str'"
        self._date_process = value

    @builtins.property
    def id_user(self):
        """Message field 'id_user'."""
        return self._id_user

    @id_user.setter
    def id_user(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id_user' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id_user' field must be an integer in [-2147483648, 2147483647]"
        self._id_user = value

    @builtins.property
    def log_process(self):
        """Message field 'log_process'."""
        return self._log_process

    @log_process.setter
    def log_process(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'log_process' field must be of type 'str'"
        self._log_process = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadFiledb_Response(type):
    """Metaclass of message 'LoadFiledb_Response'."""

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
                'my_mas.srv.LoadFiledb_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__load_filedb__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__load_filedb__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__load_filedb__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__load_filedb__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__load_filedb__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadFiledb_Response(metaclass=Metaclass_LoadFiledb_Response):
    """Message class 'LoadFiledb_Response'."""

    __slots__ = [
        '_status',
    ]

    _fields_and_field_types = {
        'status': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', str())

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
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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


class Metaclass_LoadFiledb(type):
    """Metaclass of service 'LoadFiledb'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_mas')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_mas.srv.LoadFiledb')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__load_filedb

            from my_mas.srv import _load_filedb
            if _load_filedb.Metaclass_LoadFiledb_Request._TYPE_SUPPORT is None:
                _load_filedb.Metaclass_LoadFiledb_Request.__import_type_support__()
            if _load_filedb.Metaclass_LoadFiledb_Response._TYPE_SUPPORT is None:
                _load_filedb.Metaclass_LoadFiledb_Response.__import_type_support__()


class LoadFiledb(metaclass=Metaclass_LoadFiledb):
    from my_mas.srv._load_filedb import LoadFiledb_Request as Request
    from my_mas.srv._load_filedb import LoadFiledb_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
