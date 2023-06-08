/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-python-capi/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/basic-python-capi/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::test::fixtures::basic-python-capi::MyEnum> {
  using type = ::test::fixtures::basic-python-capi::MyEnum;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = {{
      type::MyValue1,
      type::MyValue2,
  }};
  static constexpr std::array<folly::StringPiece, size> names = {{
      "MyValue1",
      "MyValue2",
  }};
};

template <> struct TEnumDataStorage<::test::fixtures::basic-python-capi::MyUnion::Type> {
  using type = ::test::fixtures::basic-python-capi::MyUnion::Type;
  static constexpr const std::size_t size = 6;
  static constexpr std::array<type, size> values = {{
      type::myEnum,
      type::myStruct,
      type::myDataItem,
      type::doubleSet,
      type::doubleList,
      type::strMap,
  }};
  static constexpr std::array<folly::StringPiece, size> names = {{
      "myEnum",
      "myStruct",
      "myDataItem",
      "doubleSet",
      "doubleList",
      "strMap",
  }};
};

template <> struct TStructDataStorage<::test::fixtures::basic-python-capi::MyStruct> {
  static constexpr const std::size_t fields_size = 8;
  static const folly::StringPiece name;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<folly::StringPiece, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic-python-capi::MyDataItem> {
  static constexpr const std::size_t fields_size = 0;
  static const folly::StringPiece name;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<folly::StringPiece, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::basic-python-capi::MyUnion> {
  static constexpr const std::size_t fields_size = 6;
  static const folly::StringPiece name;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<folly::StringPiece, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

}} // apache::thrift
