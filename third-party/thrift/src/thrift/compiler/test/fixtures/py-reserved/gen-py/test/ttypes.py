#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from __future__ import absolute_import
import sys
from thrift.util.Recursive import fix_spec
from thrift.Thrift import TType, TMessageType, TPriority, TRequestContext, TProcessorEventHandler, TServerInterface, TProcessor, TException, TApplicationException, UnimplementedTypedef
from thrift.protocol.TProtocol import TProtocolException

from json import loads
import sys
if sys.version_info[0] >= 3:
  long = int


import pprint
import warnings
from thrift import Thrift
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.protocol import TCompactProtocol
from thrift.protocol import THeaderProtocol
from thrift.Thrift import expand_thrift_spec as __EXPAND_THRIFT_SPEC
fastproto = None
try:
  from thrift.protocol import fastproto
except ImportError:
  pass
all_structs = []
UTF8STRINGS = bool(0) or sys.version_info.major >= 3

__all__ = ['UTF8STRINGS', 'def_PY_RESERVED_KEYWORD']

class def_PY_RESERVED_KEYWORD:
  r"""
  Attributes:
   - from_PY_RESERVED_KEYWORD
   - in_PY_RESERVED_KEYWORD
   - as_PY_RESERVED_KEYWORD
   - if_PY_RESERVED_KEYWORD
   - else_PY_RESERVED_KEYWORD
   - try_PY_RESERVED_KEYWORD
   - while_PY_RESERVED_KEYWORD
   - yield_PY_RESERVED_KEYWORD
   - break_PY_RESERVED_KEYWORD
   - await_PY_RESERVED_KEYWORD
   - return_PY_RESERVED_KEYWORD
  """

  thrift_spec = None
  thrift_field_annotations = None
  thrift_struct_annotations = None
  __init__ = None
  @staticmethod
  def isUnion():
    return False

  def read(self, iprot):
    if (isinstance(iprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0)
      return
    if (isinstance(iprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2)
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.I64:
          self.from_PY_RESERVED_KEYWORD = iprot.readI64()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRING:
          self.in_PY_RESERVED_KEYWORD = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 3:
        if ftype == TType.I32:
          self.as_PY_RESERVED_KEYWORD = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 4:
        if ftype == TType.BOOL:
          self.if_PY_RESERVED_KEYWORD = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 5:
        if ftype == TType.LIST:
          self.else_PY_RESERVED_KEYWORD = []
          (_etype3, _size0) = iprot.readListBegin()
          if _size0 >= 0:
            for _i4 in range(_size0):
              _elem5 = iprot.readI32()
              self.else_PY_RESERVED_KEYWORD.append(_elem5)
          else: 
            while iprot.peekList():
              _elem6 = iprot.readI32()
              self.else_PY_RESERVED_KEYWORD.append(_elem6)
          iprot.readListEnd()
        else:
          iprot.skip(ftype)
      elif fid == 6:
        if ftype == TType.I32:
          self.try_PY_RESERVED_KEYWORD = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 7:
        if ftype == TType.I32:
          self.while_PY_RESERVED_KEYWORD = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 8:
        if ftype == TType.BOOL:
          self.yield_PY_RESERVED_KEYWORD = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 9:
        if ftype == TType.BOOL:
          self.break_PY_RESERVED_KEYWORD = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 10:
        if ftype == TType.BOOL:
          self.await_PY_RESERVED_KEYWORD = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 11:
        if ftype == TType.BOOL:
          self.return_PY_RESERVED_KEYWORD = iprot.readBool()
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if (isinstance(oprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0))
      return
    if (isinstance(oprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2))
      return
    oprot.writeStructBegin('def')
    if self.from_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('from', TType.I64, 1)
      oprot.writeI64(self.from_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.in_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('in', TType.STRING, 2)
      oprot.writeString(self.in_PY_RESERVED_KEYWORD.encode('utf-8')) if UTF8STRINGS and not isinstance(self.in_PY_RESERVED_KEYWORD, bytes) else oprot.writeString(self.in_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.as_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('as', TType.I32, 3)
      oprot.writeI32(self.as_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.if_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('if', TType.BOOL, 4)
      oprot.writeBool(self.if_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.else_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('else', TType.LIST, 5)
      oprot.writeListBegin(TType.I32, len(self.else_PY_RESERVED_KEYWORD))
      for iter7 in self.else_PY_RESERVED_KEYWORD:
        oprot.writeI32(iter7)
      oprot.writeListEnd()
      oprot.writeFieldEnd()
    if self.try_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('try', TType.I32, 6)
      oprot.writeI32(self.try_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.while_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('while', TType.I32, 7)
      oprot.writeI32(self.while_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.yield_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('yield', TType.BOOL, 8)
      oprot.writeBool(self.yield_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.break_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('break', TType.BOOL, 9)
      oprot.writeBool(self.break_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.await_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('await', TType.BOOL, 10)
      oprot.writeBool(self.await_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    if self.return_PY_RESERVED_KEYWORD != None:
      oprot.writeFieldBegin('return', TType.BOOL, 11)
      oprot.writeBool(self.return_PY_RESERVED_KEYWORD)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    relax_enum_validation = bool(kwargs.pop('relax_enum_validation', False))
    set_cls = kwargs.pop('custom_set_cls', set)
    dict_cls = kwargs.pop('custom_dict_cls', dict)
    if kwargs:
        extra_kwargs = ', '.join(kwargs.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'from' in json_obj and json_obj['from'] is not None:
      self.from_PY_RESERVED_KEYWORD = long(json_obj['from'])
    if 'in' in json_obj and json_obj['in'] is not None:
      self.in_PY_RESERVED_KEYWORD = json_obj['in']
    if 'as' in json_obj and json_obj['as'] is not None:
      self.as_PY_RESERVED_KEYWORD = json_obj['as']
      if self.as_PY_RESERVED_KEYWORD > 0x7fffffff or self.as_PY_RESERVED_KEYWORD < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'if' in json_obj and json_obj['if'] is not None:
      self.if_PY_RESERVED_KEYWORD = json_obj['if']
    if 'else' in json_obj and json_obj['else'] is not None:
      self.else_PY_RESERVED_KEYWORD = []
      for _tmp_e8 in json_obj['else']:
        if _tmp_e8 > 0x7fffffff or _tmp_e8 < -0x80000000:
          raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
        self.else_PY_RESERVED_KEYWORD.append(_tmp_e8)
    if 'try' in json_obj and json_obj['try'] is not None:
      self.try_PY_RESERVED_KEYWORD = json_obj['try']
      if self.try_PY_RESERVED_KEYWORD > 0x7fffffff or self.try_PY_RESERVED_KEYWORD < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'while' in json_obj and json_obj['while'] is not None:
      self.while_PY_RESERVED_KEYWORD = json_obj['while']
      if self.while_PY_RESERVED_KEYWORD > 0x7fffffff or self.while_PY_RESERVED_KEYWORD < -0x80000000:
        raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
    if 'yield' in json_obj and json_obj['yield'] is not None:
      self.yield_PY_RESERVED_KEYWORD = json_obj['yield']
    if 'break' in json_obj and json_obj['break'] is not None:
      self.break_PY_RESERVED_KEYWORD = json_obj['break']
    if 'await' in json_obj and json_obj['await'] is not None:
      self.await_PY_RESERVED_KEYWORD = json_obj['await']
    if 'return' in json_obj and json_obj['return'] is not None:
      self.return_PY_RESERVED_KEYWORD = json_obj['return']

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.from_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.from_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    from_PY_RESERVED_KEYWORD=%s' % (value))
    if self.in_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.in_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    in_PY_RESERVED_KEYWORD=%s' % (value))
    if self.as_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.as_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    as_PY_RESERVED_KEYWORD=%s' % (value))
    if self.if_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.if_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    if_PY_RESERVED_KEYWORD=%s' % (value))
    if self.else_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.else_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    else_PY_RESERVED_KEYWORD=%s' % (value))
    if self.try_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.try_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    try_PY_RESERVED_KEYWORD=%s' % (value))
    if self.while_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.while_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    while_PY_RESERVED_KEYWORD=%s' % (value))
    if self.yield_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.yield_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    yield_PY_RESERVED_KEYWORD=%s' % (value))
    if self.break_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.break_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    break_PY_RESERVED_KEYWORD=%s' % (value))
    if self.await_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.await_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    await_PY_RESERVED_KEYWORD=%s' % (value))
    if self.return_PY_RESERVED_KEYWORD is not None:
      value = pprint.pformat(self.return_PY_RESERVED_KEYWORD, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    return_PY_RESERVED_KEYWORD=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'from_PY_RESERVED_KEYWORD',
      'in_PY_RESERVED_KEYWORD',
      'as_PY_RESERVED_KEYWORD',
      'if_PY_RESERVED_KEYWORD',
      'else_PY_RESERVED_KEYWORD',
      'try_PY_RESERVED_KEYWORD',
      'while_PY_RESERVED_KEYWORD',
      'yield_PY_RESERVED_KEYWORD',
      'break_PY_RESERVED_KEYWORD',
      'await_PY_RESERVED_KEYWORD',
      'return_PY_RESERVED_KEYWORD',
    )

  __hash__ = object.__hash__

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("test.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.def_PY_RESERVED_KEYWORD, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("test.types")
    return thrift.py3.converter.to_py3_struct(py3_types.def_PY_RESERVED_KEYWORD, self)

  def _to_py_deprecated(self):
    return self

all_structs.append(def_PY_RESERVED_KEYWORD)
def_PY_RESERVED_KEYWORD.thrift_spec = tuple(__EXPAND_THRIFT_SPEC((
  (1, TType.I64, 'from_PY_RESERVED_KEYWORD', None, None, 2, ), # 1
  (2, TType.STRING, 'in_PY_RESERVED_KEYWORD', True, None, 2, ), # 2
  (3, TType.I32, 'as_PY_RESERVED_KEYWORD', None, None, 2, ), # 3
  (4, TType.BOOL, 'if_PY_RESERVED_KEYWORD', None, None, 2, ), # 4
  (5, TType.LIST, 'else_PY_RESERVED_KEYWORD', (TType.I32,None), None, 2, ), # 5
  (6, TType.I32, 'try_PY_RESERVED_KEYWORD', None, None, 2, ), # 6
  (7, TType.I32, 'while_PY_RESERVED_KEYWORD', None, None, 2, ), # 7
  (8, TType.BOOL, 'yield_PY_RESERVED_KEYWORD', None, None, 2, ), # 8
  (9, TType.BOOL, 'break_PY_RESERVED_KEYWORD', None, None, 2, ), # 9
  (10, TType.BOOL, 'await_PY_RESERVED_KEYWORD', None, None, 2, ), # 10
  (11, TType.BOOL, 'return_PY_RESERVED_KEYWORD', None, None, 2, ), # 11
)))

def_PY_RESERVED_KEYWORD.thrift_struct_annotations = {
}
def_PY_RESERVED_KEYWORD.thrift_field_annotations = {
}

def def_PY_RESERVED_KEYWORD__init__(self, from_PY_RESERVED_KEYWORD=None, in_PY_RESERVED_KEYWORD=None, as_PY_RESERVED_KEYWORD=None, if_PY_RESERVED_KEYWORD=None, else_PY_RESERVED_KEYWORD=None, try_PY_RESERVED_KEYWORD=None, while_PY_RESERVED_KEYWORD=None, yield_PY_RESERVED_KEYWORD=None, break_PY_RESERVED_KEYWORD=None, await_PY_RESERVED_KEYWORD=None, return_PY_RESERVED_KEYWORD=None,):
  self.from_PY_RESERVED_KEYWORD = from_PY_RESERVED_KEYWORD
  self.in_PY_RESERVED_KEYWORD = in_PY_RESERVED_KEYWORD
  self.as_PY_RESERVED_KEYWORD = as_PY_RESERVED_KEYWORD
  self.if_PY_RESERVED_KEYWORD = if_PY_RESERVED_KEYWORD
  self.else_PY_RESERVED_KEYWORD = else_PY_RESERVED_KEYWORD
  self.try_PY_RESERVED_KEYWORD = try_PY_RESERVED_KEYWORD
  self.while_PY_RESERVED_KEYWORD = while_PY_RESERVED_KEYWORD
  self.yield_PY_RESERVED_KEYWORD = yield_PY_RESERVED_KEYWORD
  self.break_PY_RESERVED_KEYWORD = break_PY_RESERVED_KEYWORD
  self.await_PY_RESERVED_KEYWORD = await_PY_RESERVED_KEYWORD
  self.return_PY_RESERVED_KEYWORD = return_PY_RESERVED_KEYWORD

def_PY_RESERVED_KEYWORD.__init__ = def_PY_RESERVED_KEYWORD__init__

def def_PY_RESERVED_KEYWORD__setstate__(self, state):
  state.setdefault('from_PY_RESERVED_KEYWORD', None)
  state.setdefault('in_PY_RESERVED_KEYWORD', None)
  state.setdefault('as_PY_RESERVED_KEYWORD', None)
  state.setdefault('if_PY_RESERVED_KEYWORD', None)
  state.setdefault('else_PY_RESERVED_KEYWORD', None)
  state.setdefault('try_PY_RESERVED_KEYWORD', None)
  state.setdefault('while_PY_RESERVED_KEYWORD', None)
  state.setdefault('yield_PY_RESERVED_KEYWORD', None)
  state.setdefault('break_PY_RESERVED_KEYWORD', None)
  state.setdefault('await_PY_RESERVED_KEYWORD', None)
  state.setdefault('return_PY_RESERVED_KEYWORD', None)
  self.__dict__ = state

def_PY_RESERVED_KEYWORD.__getstate__ = lambda self: self.__dict__.copy()
def_PY_RESERVED_KEYWORD.__setstate__ = def_PY_RESERVED_KEYWORD__setstate__

fix_spec(all_structs)
del all_structs
