# generated from rosidl_generator_py/resource/_idl.py.em
# with input from motor_interfaces:msg/MotorCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'target_q'
# Member 'target_dq'
# Member 'target_tau'
# Member 'target_kp'
# Member 'target_kd'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorCmd(type):
    """Metaclass of message 'MotorCmd'."""

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
            module = import_type_support('motor_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'motor_interfaces.msg.MotorCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MotorCmd(metaclass=Metaclass_MotorCmd):
    """Message class 'MotorCmd'."""

    __slots__ = [
        '_target_q',
        '_target_dq',
        '_target_tau',
        '_target_kp',
        '_target_kd',
    ]

    _fields_and_field_types = {
        'target_q': 'sequence<float>',
        'target_dq': 'sequence<float>',
        'target_tau': 'sequence<float>',
        'target_kp': 'sequence<float>',
        'target_kd': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_q = array.array('f', kwargs.get('target_q', []))
        self.target_dq = array.array('f', kwargs.get('target_dq', []))
        self.target_tau = array.array('f', kwargs.get('target_tau', []))
        self.target_kp = array.array('f', kwargs.get('target_kp', []))
        self.target_kd = array.array('f', kwargs.get('target_kd', []))

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
        if self.target_q != other.target_q:
            return False
        if self.target_dq != other.target_dq:
            return False
        if self.target_tau != other.target_tau:
            return False
        if self.target_kp != other.target_kp:
            return False
        if self.target_kd != other.target_kd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_q(self):
        """Message field 'target_q'."""
        return self._target_q

    @target_q.setter
    def target_q(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'target_q' array.array() must have the type code of 'f'"
            self._target_q = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'target_q' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._target_q = array.array('f', value)

    @builtins.property
    def target_dq(self):
        """Message field 'target_dq'."""
        return self._target_dq

    @target_dq.setter
    def target_dq(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'target_dq' array.array() must have the type code of 'f'"
            self._target_dq = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'target_dq' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._target_dq = array.array('f', value)

    @builtins.property
    def target_tau(self):
        """Message field 'target_tau'."""
        return self._target_tau

    @target_tau.setter
    def target_tau(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'target_tau' array.array() must have the type code of 'f'"
            self._target_tau = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'target_tau' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._target_tau = array.array('f', value)

    @builtins.property
    def target_kp(self):
        """Message field 'target_kp'."""
        return self._target_kp

    @target_kp.setter
    def target_kp(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'target_kp' array.array() must have the type code of 'f'"
            self._target_kp = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'target_kp' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._target_kp = array.array('f', value)

    @builtins.property
    def target_kd(self):
        """Message field 'target_kd'."""
        return self._target_kd

    @target_kd.setter
    def target_kd(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'target_kd' array.array() must have the type code of 'f'"
            self._target_kd = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'target_kd' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._target_kd = array.array('f', value)
