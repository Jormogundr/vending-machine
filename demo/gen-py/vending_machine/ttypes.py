#
# Autogenerated by Thrift Compiler (0.14.1)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py
#

from thrift.Thrift import TType, TMessageType, TFrozenDict, TException, TApplicationException
from thrift.protocol.TProtocol import TProtocolException
from thrift.TRecursive import fix_spec

import sys

from thrift.transport import TTransport
all_structs = []


class ErrorCode(object):
    SE_CONNPOOL_TIMEOUT = 0
    SE_THRIFT_CONN_ERROR = 1
    SE_UNAUTHORIZED = 2
    SE_MEMCACHED_ERROR = 3
    SE_MONGODB_ERROR = 4
    SE_REDIS_ERROR = 5
    SE_THRIFT_HANDLER_ERROR = 6
    SE_RABBITMQ_CONN_ERROR = 7

    _VALUES_TO_NAMES = {
        0: "SE_CONNPOOL_TIMEOUT",
        1: "SE_THRIFT_CONN_ERROR",
        2: "SE_UNAUTHORIZED",
        3: "SE_MEMCACHED_ERROR",
        4: "SE_MONGODB_ERROR",
        5: "SE_REDIS_ERROR",
        6: "SE_THRIFT_HANDLER_ERROR",
        7: "SE_RABBITMQ_CONN_ERROR",
    }

    _NAMES_TO_VALUES = {
        "SE_CONNPOOL_TIMEOUT": 0,
        "SE_THRIFT_CONN_ERROR": 1,
        "SE_UNAUTHORIZED": 2,
        "SE_MEMCACHED_ERROR": 3,
        "SE_MONGODB_ERROR": 4,
        "SE_REDIS_ERROR": 5,
        "SE_THRIFT_HANDLER_ERROR": 6,
        "SE_RABBITMQ_CONN_ERROR": 7,
    }


class WeatherType(object):
    WARM = 0
    COLD = 1

    _VALUES_TO_NAMES = {
        0: "WARM",
        1: "COLD",
    }

    _NAMES_TO_VALUES = {
        "WARM": 0,
        "COLD": 1,
    }


class BeverageType(object):
    HOT = 0
    COLD = 1

    _VALUES_TO_NAMES = {
        0: "HOT",
        1: "COLD",
    }

    _NAMES_TO_VALUES = {
        "HOT": 0,
        "COLD": 1,
    }


class ServiceException(TException):
    """
    Attributes:
     - errorCode
     - message

    """


    def __init__(self, errorCode=None, message=None,):
        super(ServiceException, self).__setattr__('errorCode', errorCode)
        super(ServiceException, self).__setattr__('message', message)

    def __setattr__(self, *args):
        raise TypeError("can't modify immutable instance")

    def __delattr__(self, *args):
        raise TypeError("can't modify immutable instance")

    def __hash__(self):
        return hash(self.__class__) ^ hash((self.errorCode, self.message, ))

    @classmethod
    def read(cls, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and cls.thrift_spec is not None:
            return iprot._fast_decode(None, iprot, [cls, cls.thrift_spec])
        iprot.readStructBegin()
        errorCode = None
        message = None
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.I32:
                    errorCode = iprot.readI32()
                else:
                    iprot.skip(ftype)
            elif fid == 2:
                if ftype == TType.STRING:
                    message = iprot.readString().decode('utf-8', errors='replace') if sys.version_info[0] == 2 else iprot.readString()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()
        return cls(
            errorCode=errorCode,
            message=message,
        )

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('ServiceException')
        if self.errorCode is not None:
            oprot.writeFieldBegin('errorCode', TType.I32, 1)
            oprot.writeI32(self.errorCode)
            oprot.writeFieldEnd()
        if self.message is not None:
            oprot.writeFieldBegin('message', TType.STRING, 2)
            oprot.writeString(self.message.encode('utf-8') if sys.version_info[0] == 2 else self.message)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __str__(self):
        return repr(self)

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)


class location(object):
    """
    Attributes:
     - location_id
     - city

    """


    def __init__(self, location_id=None, city=None,):
        self.location_id = location_id
        self.city = city

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.I64:
                    self.location_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 2:
                if ftype == TType.I64:
                    self.city = iprot.readI64()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('location')
        if self.location_id is not None:
            oprot.writeFieldBegin('location_id', TType.I64, 1)
            oprot.writeI64(self.location_id)
            oprot.writeFieldEnd()
        if self.city is not None:
            oprot.writeFieldBegin('city', TType.I64, 2)
            oprot.writeI64(self.city)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)
all_structs.append(ServiceException)
ServiceException.thrift_spec = (
    None,  # 0
    (1, TType.I32, 'errorCode', None, None, ),  # 1
    (2, TType.STRING, 'message', 'UTF8', None, ),  # 2
)
all_structs.append(location)
location.thrift_spec = (
    None,  # 0
    (1, TType.I64, 'location_id', None, None, ),  # 1
    (2, TType.I64, 'city', None, None, ),  # 2
)
fix_spec(all_structs)
del all_structs
