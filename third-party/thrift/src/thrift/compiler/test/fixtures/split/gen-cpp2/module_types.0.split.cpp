/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/split/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/split/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/split/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/split/gen-cpp2/module_data.h"


namespace apache { namespace thrift {

folly::Range<::cpp2::MyEnum const*> const TEnumTraits<::cpp2::MyEnum>::values = folly::range(TEnumDataStorage<::cpp2::MyEnum>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::MyEnum>::names = folly::range(TEnumDataStorage<::cpp2::MyEnum>::names);

bool TEnumTraits<::cpp2::MyEnum>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::cpp2::MyEnum>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}

}} // apache::thrift


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyDataItem>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyDataItem>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const folly::StringPiece MyDataItem::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<MyDataItem>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece MyDataItem::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<MyDataItem>::name;
}


MyDataItem::MyDataItem(apache::thrift::FragileConstructor) {}


void MyDataItem::__fbthrift_clear() {
  // clear all fields
}

void MyDataItem::__fbthrift_clear_terse_fields() {
}

bool MyDataItem::__fbthrift_is_empty() const {
  return true;
}

bool MyDataItem::operator==(FOLLY_MAYBE_UNUSED const MyDataItem& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool MyDataItem::operator<(FOLLY_MAYBE_UNUSED const MyDataItem& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap(FOLLY_MAYBE_UNUSED MyDataItem& a, FOLLY_MAYBE_UNUSED MyDataItem& b) {
  using ::std::swap;
}

template void MyDataItem::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyDataItem::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyDataItem::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyDataItem::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyDataItem::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyDataItem::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyDataItem::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyDataItem::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace cpp2 { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}} // cpp2
namespace apache::thrift::detail::annotation {
}
