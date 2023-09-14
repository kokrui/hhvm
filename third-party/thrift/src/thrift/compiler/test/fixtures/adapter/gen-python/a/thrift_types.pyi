#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations


import typing as _typing

import folly.iobuf as _fbthrift_iobuf
import thrift.python.types as _fbthrift_python_types
import thrift.python.exceptions as _fbthrift_python_exceptions

import b.thrift_types

import c.thrift_types
import typeshed_two
import typeshed_three
import typeshed_one


class _fbthrift_compatible_with_MyStruct:
    pass


class MyStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_MyStruct):
    a: _typing.Final[typeshed_one.AdapterOneType[b.thrift_types.B]] = ...
    b: _typing.Final[typeshed_three.AdapterThreeType[c.thrift_types.C1]] = ...
    c: _typing.Final[typeshed_two.AdapterTwoType[c.thrift_types.C2]] = ...
    def __init__(
        self, *,
        a: _typing.Optional[typeshed_one.AdapterOneType[b.thrift_types.B]]=...,
        b: _typing.Optional[typeshed_three.AdapterThreeType[c.thrift_types.C1]]=...,
        c: _typing.Optional[typeshed_two.AdapterTwoType[c.thrift_types.C2]]=...
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Optional[typeshed_one.AdapterOneType[b.thrift_types.B]]=...,
        b: _typing.Optional[typeshed_three.AdapterThreeType[c.thrift_types.C1]]=...,
        c: _typing.Optional[typeshed_two.AdapterTwoType[c.thrift_types.C2]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[typeshed_one.AdapterOneType[b.thrift_types.B], typeshed_three.AdapterThreeType[c.thrift_types.C1], typeshed_two.AdapterTwoType[c.thrift_types.C2]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "a.types.MyStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "a.ttypes.MyStruct": ...  # type: ignore
