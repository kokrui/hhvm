// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package standard // [[[ program thrift source path ]]]

import (
  "fmt"

  thrift0 "thrift/annotation/thrift"
  java "thrift/annotation/java"
  "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

var _ = thrift0.GoUnusedProtection__
var _ = java.GoUnusedProtection__

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = thrift.ZERO


type ByteString = []byte

type ByteBuffer = []byte

type Uri = string

type Void int32

const (
    Void_Unused Void = 0
)

// Enum value maps for Void
var (
    VoidToName = map[Void]string {
        Void_Unused: "Unused",
    }

    VoidToValue = map[string]Void {
        "Unused": Void_Unused,
    }

    VoidNames = []string{
        "Unused",
    }

    VoidValues = []Void{
        0,
    }
)

func (x Void) String() string {
    if v, ok := VoidToName[x]; ok {
        return v
    }
    return "<UNSET>"
}

func (x Void) Ptr() *Void {
    return &x
}

// Deprecated: Use VoidToValue instead (e.g. `x, ok := VoidToValue["name"]`).
func VoidFromString(s string) (Void, error) {
    if v, ok := VoidToValue[s]; ok {
        return v, nil
    }
    return Void(0), fmt.Errorf("not a valid Void string")
}

// Deprecated: Use Void.Ptr() instead.
func VoidPtr(v Void) *Void {
    return &v
}


type StandardProtocol int32

const (
    StandardProtocol_Custom StandardProtocol = 0
    StandardProtocol_Binary StandardProtocol = 1
    StandardProtocol_Compact StandardProtocol = 2
    StandardProtocol_Json StandardProtocol = 3
    StandardProtocol_SimpleJson StandardProtocol = 4
)

// Enum value maps for StandardProtocol
var (
    StandardProtocolToName = map[StandardProtocol]string {
        StandardProtocol_Custom: "Custom",
        StandardProtocol_Binary: "Binary",
        StandardProtocol_Compact: "Compact",
        StandardProtocol_Json: "Json",
        StandardProtocol_SimpleJson: "SimpleJson",
    }

    StandardProtocolToValue = map[string]StandardProtocol {
        "Custom": StandardProtocol_Custom,
        "Binary": StandardProtocol_Binary,
        "Compact": StandardProtocol_Compact,
        "Json": StandardProtocol_Json,
        "SimpleJson": StandardProtocol_SimpleJson,
    }

    StandardProtocolNames = []string{
        "Custom",
        "Binary",
        "Compact",
        "Json",
        "SimpleJson",
    }

    StandardProtocolValues = []StandardProtocol{
        0,
        1,
        2,
        3,
        4,
    }
)

func (x StandardProtocol) String() string {
    if v, ok := StandardProtocolToName[x]; ok {
        return v
    }
    return "<UNSET>"
}

func (x StandardProtocol) Ptr() *StandardProtocol {
    return &x
}

// Deprecated: Use StandardProtocolToValue instead (e.g. `x, ok := StandardProtocolToValue["name"]`).
func StandardProtocolFromString(s string) (StandardProtocol, error) {
    if v, ok := StandardProtocolToValue[s]; ok {
        return v, nil
    }
    return StandardProtocol(0), fmt.Errorf("not a valid StandardProtocol string")
}

// Deprecated: Use StandardProtocol.Ptr() instead.
func StandardProtocolPtr(v StandardProtocol) *StandardProtocol {
    return &v
}


type TypeUri struct {
    Uri *Uri `thrift:"uri,1" json:"uri" db:"uri"`
    TypeHashPrefixSha2256 ByteString `thrift:"typeHashPrefixSha2_256,2" json:"typeHashPrefixSha2_256" db:"typeHashPrefixSha2_256"`
}
// Compile time interface enforcer
var _ thrift.Struct = &TypeUri{}

func NewTypeUri() *TypeUri {
    return (&TypeUri{})
}
func (x *TypeUri) GetUri() *Uri {
    return x.Uri
}

func (x *TypeUri) GetTypeHashPrefixSha2256() ByteString {
    return x.TypeHashPrefixSha2256
}

func (x *TypeUri) SetUri(value Uri) *TypeUri {
    x.Uri = &value
    return x
}

func (x *TypeUri) SetTypeHashPrefixSha2256(value ByteString) *TypeUri {
    x.TypeHashPrefixSha2256 = value
    return x
}

func (x *TypeUri) IsSetUri() bool {
    return x.Uri != nil
}

func (x *TypeUri) IsSetTypeHashPrefixSha2256() bool {
    return x.TypeHashPrefixSha2256 != nil
}

func (x *TypeUri) writeField1(p thrift.Protocol) error {  // Uri
    if !x.IsSetUri() {
        return nil
    }

    if err := p.WriteFieldBegin("uri", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetUri()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeUri) writeField2(p thrift.Protocol) error {  // TypeHashPrefixSha2256
    if !x.IsSetTypeHashPrefixSha2256() {
        return nil
    }

    if err := p.WriteFieldBegin("typeHashPrefixSha2_256", thrift.BINARY, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetTypeHashPrefixSha2256()
    if err := p.WriteBinary(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeUri) readField1(p thrift.Protocol) error {  // Uri
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetUri(result)
    return nil
}

func (x *TypeUri) readField2(p thrift.Protocol) error {  // TypeHashPrefixSha2256
    result, err := p.ReadBinary()
if err != nil {
    return err
}

    x.SetTypeHashPrefixSha2256(result)
    return nil
}



func (x *TypeUri) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("TypeUri"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *TypeUri) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, typ, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if typ == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // uri
            if err := x.readField1(p); err != nil {
                return err
            }
        case 2:  // typeHashPrefixSha2_256
            if err := x.readField2(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(typ); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

type TypeName struct {
    BoolType *Void `thrift:"boolType,1" json:"boolType" db:"boolType"`
    ByteType *Void `thrift:"byteType,2" json:"byteType" db:"byteType"`
    I16Type *Void `thrift:"i16Type,3" json:"i16Type" db:"i16Type"`
    I32Type *Void `thrift:"i32Type,4" json:"i32Type" db:"i32Type"`
    I64Type *Void `thrift:"i64Type,5" json:"i64Type" db:"i64Type"`
    FloatType *Void `thrift:"floatType,6" json:"floatType" db:"floatType"`
    DoubleType *Void `thrift:"doubleType,7" json:"doubleType" db:"doubleType"`
    StringType *Void `thrift:"stringType,8" json:"stringType" db:"stringType"`
    BinaryType *Void `thrift:"binaryType,9" json:"binaryType" db:"binaryType"`
    EnumType *TypeUri `thrift:"enumType,10" json:"enumType" db:"enumType"`
    TypedefType *TypeUri `thrift:"typedefType,17" json:"typedefType" db:"typedefType"`
    StructType *TypeUri `thrift:"structType,11" json:"structType" db:"structType"`
    UnionType *TypeUri `thrift:"unionType,12" json:"unionType" db:"unionType"`
    ExceptionType *TypeUri `thrift:"exceptionType,13" json:"exceptionType" db:"exceptionType"`
    ListType *Void `thrift:"listType,14" json:"listType" db:"listType"`
    SetType *Void `thrift:"setType,15" json:"setType" db:"setType"`
    MapType *Void `thrift:"mapType,16" json:"mapType" db:"mapType"`
}
// Compile time interface enforcer
var _ thrift.Struct = &TypeName{}

func NewTypeName() *TypeName {
    return (&TypeName{})
}
func (x *TypeName) GetBoolType() *Void {
    return x.BoolType
}

func (x *TypeName) GetByteType() *Void {
    return x.ByteType
}

func (x *TypeName) GetI16Type() *Void {
    return x.I16Type
}

func (x *TypeName) GetI32Type() *Void {
    return x.I32Type
}

func (x *TypeName) GetI64Type() *Void {
    return x.I64Type
}

func (x *TypeName) GetFloatType() *Void {
    return x.FloatType
}

func (x *TypeName) GetDoubleType() *Void {
    return x.DoubleType
}

func (x *TypeName) GetStringType() *Void {
    return x.StringType
}

func (x *TypeName) GetBinaryType() *Void {
    return x.BinaryType
}

func (x *TypeName) GetEnumType() *TypeUri {
    return x.EnumType
}

func (x *TypeName) GetTypedefType() *TypeUri {
    return x.TypedefType
}

func (x *TypeName) GetStructType() *TypeUri {
    return x.StructType
}

func (x *TypeName) GetUnionType() *TypeUri {
    return x.UnionType
}

func (x *TypeName) GetExceptionType() *TypeUri {
    return x.ExceptionType
}

func (x *TypeName) GetListType() *Void {
    return x.ListType
}

func (x *TypeName) GetSetType() *Void {
    return x.SetType
}

func (x *TypeName) GetMapType() *Void {
    return x.MapType
}

func (x *TypeName) SetBoolType(value Void) *TypeName {
    x.BoolType = &value
    return x
}

func (x *TypeName) SetByteType(value Void) *TypeName {
    x.ByteType = &value
    return x
}

func (x *TypeName) SetI16Type(value Void) *TypeName {
    x.I16Type = &value
    return x
}

func (x *TypeName) SetI32Type(value Void) *TypeName {
    x.I32Type = &value
    return x
}

func (x *TypeName) SetI64Type(value Void) *TypeName {
    x.I64Type = &value
    return x
}

func (x *TypeName) SetFloatType(value Void) *TypeName {
    x.FloatType = &value
    return x
}

func (x *TypeName) SetDoubleType(value Void) *TypeName {
    x.DoubleType = &value
    return x
}

func (x *TypeName) SetStringType(value Void) *TypeName {
    x.StringType = &value
    return x
}

func (x *TypeName) SetBinaryType(value Void) *TypeName {
    x.BinaryType = &value
    return x
}

func (x *TypeName) SetEnumType(value TypeUri) *TypeName {
    x.EnumType = &value
    return x
}

func (x *TypeName) SetTypedefType(value TypeUri) *TypeName {
    x.TypedefType = &value
    return x
}

func (x *TypeName) SetStructType(value TypeUri) *TypeName {
    x.StructType = &value
    return x
}

func (x *TypeName) SetUnionType(value TypeUri) *TypeName {
    x.UnionType = &value
    return x
}

func (x *TypeName) SetExceptionType(value TypeUri) *TypeName {
    x.ExceptionType = &value
    return x
}

func (x *TypeName) SetListType(value Void) *TypeName {
    x.ListType = &value
    return x
}

func (x *TypeName) SetSetType(value Void) *TypeName {
    x.SetType = &value
    return x
}

func (x *TypeName) SetMapType(value Void) *TypeName {
    x.MapType = &value
    return x
}

func (x *TypeName) IsSetBoolType() bool {
    return x.BoolType != nil
}

func (x *TypeName) IsSetByteType() bool {
    return x.ByteType != nil
}

func (x *TypeName) IsSetI16Type() bool {
    return x.I16Type != nil
}

func (x *TypeName) IsSetI32Type() bool {
    return x.I32Type != nil
}

func (x *TypeName) IsSetI64Type() bool {
    return x.I64Type != nil
}

func (x *TypeName) IsSetFloatType() bool {
    return x.FloatType != nil
}

func (x *TypeName) IsSetDoubleType() bool {
    return x.DoubleType != nil
}

func (x *TypeName) IsSetStringType() bool {
    return x.StringType != nil
}

func (x *TypeName) IsSetBinaryType() bool {
    return x.BinaryType != nil
}

func (x *TypeName) IsSetEnumType() bool {
    return x.EnumType != nil
}

func (x *TypeName) IsSetTypedefType() bool {
    return x.TypedefType != nil
}

func (x *TypeName) IsSetStructType() bool {
    return x.StructType != nil
}

func (x *TypeName) IsSetUnionType() bool {
    return x.UnionType != nil
}

func (x *TypeName) IsSetExceptionType() bool {
    return x.ExceptionType != nil
}

func (x *TypeName) IsSetListType() bool {
    return x.ListType != nil
}

func (x *TypeName) IsSetSetType() bool {
    return x.SetType != nil
}

func (x *TypeName) IsSetMapType() bool {
    return x.MapType != nil
}

func (x *TypeName) writeField1(p thrift.Protocol) error {  // BoolType
    if !x.IsSetBoolType() {
        return nil
    }

    if err := p.WriteFieldBegin("boolType", thrift.I32, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetBoolType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField2(p thrift.Protocol) error {  // ByteType
    if !x.IsSetByteType() {
        return nil
    }

    if err := p.WriteFieldBegin("byteType", thrift.I32, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetByteType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField3(p thrift.Protocol) error {  // I16Type
    if !x.IsSetI16Type() {
        return nil
    }

    if err := p.WriteFieldBegin("i16Type", thrift.I32, 3); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetI16Type()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField4(p thrift.Protocol) error {  // I32Type
    if !x.IsSetI32Type() {
        return nil
    }

    if err := p.WriteFieldBegin("i32Type", thrift.I32, 4); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetI32Type()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField5(p thrift.Protocol) error {  // I64Type
    if !x.IsSetI64Type() {
        return nil
    }

    if err := p.WriteFieldBegin("i64Type", thrift.I32, 5); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetI64Type()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField6(p thrift.Protocol) error {  // FloatType
    if !x.IsSetFloatType() {
        return nil
    }

    if err := p.WriteFieldBegin("floatType", thrift.I32, 6); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetFloatType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField7(p thrift.Protocol) error {  // DoubleType
    if !x.IsSetDoubleType() {
        return nil
    }

    if err := p.WriteFieldBegin("doubleType", thrift.I32, 7); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetDoubleType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField8(p thrift.Protocol) error {  // StringType
    if !x.IsSetStringType() {
        return nil
    }

    if err := p.WriteFieldBegin("stringType", thrift.I32, 8); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetStringType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField9(p thrift.Protocol) error {  // BinaryType
    if !x.IsSetBinaryType() {
        return nil
    }

    if err := p.WriteFieldBegin("binaryType", thrift.I32, 9); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetBinaryType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField10(p thrift.Protocol) error {  // EnumType
    if !x.IsSetEnumType() {
        return nil
    }

    if err := p.WriteFieldBegin("enumType", thrift.STRUCT, 10); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetEnumType()
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField17(p thrift.Protocol) error {  // TypedefType
    if !x.IsSetTypedefType() {
        return nil
    }

    if err := p.WriteFieldBegin("typedefType", thrift.STRUCT, 17); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetTypedefType()
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField11(p thrift.Protocol) error {  // StructType
    if !x.IsSetStructType() {
        return nil
    }

    if err := p.WriteFieldBegin("structType", thrift.STRUCT, 11); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetStructType()
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField12(p thrift.Protocol) error {  // UnionType
    if !x.IsSetUnionType() {
        return nil
    }

    if err := p.WriteFieldBegin("unionType", thrift.STRUCT, 12); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetUnionType()
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField13(p thrift.Protocol) error {  // ExceptionType
    if !x.IsSetExceptionType() {
        return nil
    }

    if err := p.WriteFieldBegin("exceptionType", thrift.STRUCT, 13); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetExceptionType()
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField14(p thrift.Protocol) error {  // ListType
    if !x.IsSetListType() {
        return nil
    }

    if err := p.WriteFieldBegin("listType", thrift.I32, 14); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetListType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField15(p thrift.Protocol) error {  // SetType
    if !x.IsSetSetType() {
        return nil
    }

    if err := p.WriteFieldBegin("setType", thrift.I32, 15); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetSetType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) writeField16(p thrift.Protocol) error {  // MapType
    if !x.IsSetMapType() {
        return nil
    }

    if err := p.WriteFieldBegin("mapType", thrift.I32, 16); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetMapType()
    if err := p.WriteI32(int32(item)); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *TypeName) readField1(p thrift.Protocol) error {  // BoolType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetBoolType(result)
    return nil
}

func (x *TypeName) readField2(p thrift.Protocol) error {  // ByteType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetByteType(result)
    return nil
}

func (x *TypeName) readField3(p thrift.Protocol) error {  // I16Type
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetI16Type(result)
    return nil
}

func (x *TypeName) readField4(p thrift.Protocol) error {  // I32Type
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetI32Type(result)
    return nil
}

func (x *TypeName) readField5(p thrift.Protocol) error {  // I64Type
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetI64Type(result)
    return nil
}

func (x *TypeName) readField6(p thrift.Protocol) error {  // FloatType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetFloatType(result)
    return nil
}

func (x *TypeName) readField7(p thrift.Protocol) error {  // DoubleType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetDoubleType(result)
    return nil
}

func (x *TypeName) readField8(p thrift.Protocol) error {  // StringType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetStringType(result)
    return nil
}

func (x *TypeName) readField9(p thrift.Protocol) error {  // BinaryType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetBinaryType(result)
    return nil
}

func (x *TypeName) readField10(p thrift.Protocol) error {  // EnumType
    result := *NewTypeUri()
err := result.Read(p)
if err != nil {
    return err
}

    x.SetEnumType(result)
    return nil
}

func (x *TypeName) readField17(p thrift.Protocol) error {  // TypedefType
    result := *NewTypeUri()
err := result.Read(p)
if err != nil {
    return err
}

    x.SetTypedefType(result)
    return nil
}

func (x *TypeName) readField11(p thrift.Protocol) error {  // StructType
    result := *NewTypeUri()
err := result.Read(p)
if err != nil {
    return err
}

    x.SetStructType(result)
    return nil
}

func (x *TypeName) readField12(p thrift.Protocol) error {  // UnionType
    result := *NewTypeUri()
err := result.Read(p)
if err != nil {
    return err
}

    x.SetUnionType(result)
    return nil
}

func (x *TypeName) readField13(p thrift.Protocol) error {  // ExceptionType
    result := *NewTypeUri()
err := result.Read(p)
if err != nil {
    return err
}

    x.SetExceptionType(result)
    return nil
}

func (x *TypeName) readField14(p thrift.Protocol) error {  // ListType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetListType(result)
    return nil
}

func (x *TypeName) readField15(p thrift.Protocol) error {  // SetType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetSetType(result)
    return nil
}

func (x *TypeName) readField16(p thrift.Protocol) error {  // MapType
    enumResult, err := p.ReadI32()
if err != nil {
    return err
}
result := Void(enumResult)

    x.SetMapType(result)
    return nil
}



func (x *TypeName) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("TypeName"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := x.writeField3(p); err != nil {
        return err
    }

    if err := x.writeField4(p); err != nil {
        return err
    }

    if err := x.writeField5(p); err != nil {
        return err
    }

    if err := x.writeField6(p); err != nil {
        return err
    }

    if err := x.writeField7(p); err != nil {
        return err
    }

    if err := x.writeField8(p); err != nil {
        return err
    }

    if err := x.writeField9(p); err != nil {
        return err
    }

    if err := x.writeField10(p); err != nil {
        return err
    }

    if err := x.writeField17(p); err != nil {
        return err
    }

    if err := x.writeField11(p); err != nil {
        return err
    }

    if err := x.writeField12(p); err != nil {
        return err
    }

    if err := x.writeField13(p); err != nil {
        return err
    }

    if err := x.writeField14(p); err != nil {
        return err
    }

    if err := x.writeField15(p); err != nil {
        return err
    }

    if err := x.writeField16(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *TypeName) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, typ, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if typ == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // boolType
            if err := x.readField1(p); err != nil {
                return err
            }
        case 2:  // byteType
            if err := x.readField2(p); err != nil {
                return err
            }
        case 3:  // i16Type
            if err := x.readField3(p); err != nil {
                return err
            }
        case 4:  // i32Type
            if err := x.readField4(p); err != nil {
                return err
            }
        case 5:  // i64Type
            if err := x.readField5(p); err != nil {
                return err
            }
        case 6:  // floatType
            if err := x.readField6(p); err != nil {
                return err
            }
        case 7:  // doubleType
            if err := x.readField7(p); err != nil {
                return err
            }
        case 8:  // stringType
            if err := x.readField8(p); err != nil {
                return err
            }
        case 9:  // binaryType
            if err := x.readField9(p); err != nil {
                return err
            }
        case 10:  // enumType
            if err := x.readField10(p); err != nil {
                return err
            }
        case 17:  // typedefType
            if err := x.readField17(p); err != nil {
                return err
            }
        case 11:  // structType
            if err := x.readField11(p); err != nil {
                return err
            }
        case 12:  // unionType
            if err := x.readField12(p); err != nil {
                return err
            }
        case 13:  // exceptionType
            if err := x.readField13(p); err != nil {
                return err
            }
        case 14:  // listType
            if err := x.readField14(p); err != nil {
                return err
            }
        case 15:  // setType
            if err := x.readField15(p); err != nil {
                return err
            }
        case 16:  // mapType
            if err := x.readField16(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(typ); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}
