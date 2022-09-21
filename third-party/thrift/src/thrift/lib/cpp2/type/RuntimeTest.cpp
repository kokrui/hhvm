/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/type/Runtime.h>

#include <any>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include <folly/io/IOBuf.h>
#include <folly/portability/GMock.h>
#include <folly/portability/GTest.h>
#include <thrift/lib/cpp2/type/Id.h>
#include <thrift/lib/cpp2/type/Tag.h>
#include <thrift/lib/thrift/gen-cpp2/standard_types.h>

namespace apache::thrift::type {
namespace {

// Test the exact case of AlignedPtr used by RuntimeType.
TEST(AlignedPtr, InfoPointer) {
  using info_pointer = detail::AlignedPtr<const detail::TypeInfo, 2>;
  EXPECT_EQ(~info_pointer::kMask, 3); // Everything except the last 2 bits.
  const auto* fullPtr = (const detail::TypeInfo*)(info_pointer::kMask);

  info_pointer empty, full{fullPtr, 3};
  EXPECT_FALSE(empty.get<0>());
  EXPECT_FALSE(empty.get<1>());
  EXPECT_EQ(empty.get(), nullptr);
  EXPECT_TRUE(full.get<0>());
  EXPECT_TRUE(full.get<1>());
  EXPECT_EQ(full.get(), fullPtr);

  empty.set<0>();
  full.clear<0>();
  EXPECT_TRUE(empty.get<0>());
  EXPECT_FALSE(empty.get<1>());
  EXPECT_EQ(empty.get(), nullptr);
  EXPECT_FALSE(full.get<0>());
  EXPECT_TRUE(full.get<1>());
  EXPECT_EQ(full.get(), fullPtr);

  empty.set<1>();
  full.clear<1>();
  EXPECT_TRUE(empty.get<0>());
  EXPECT_TRUE(empty.get<1>());
  EXPECT_EQ(empty.get(), nullptr);
  EXPECT_FALSE(full.get<0>());
  EXPECT_FALSE(full.get<1>());
  EXPECT_EQ(full.get(), fullPtr);

  empty.clear<0>();
  full.set<0>();
  EXPECT_FALSE(empty.get<0>());
  EXPECT_TRUE(empty.get<1>());
  EXPECT_EQ(empty.get(), nullptr);
  EXPECT_TRUE(full.get<0>());
  EXPECT_FALSE(full.get<1>());
  EXPECT_EQ(full.get(), fullPtr);
}

TEST(RuntimeTest, Void) {
  Ref ref;
  EXPECT_EQ(ref.type(), Type::get<void_t>());
  EXPECT_TRUE(ref.empty());
  ref.clear();
  EXPECT_TRUE(ref.empty());
  EXPECT_THROW(ref.get(FieldId{1}), std::logic_error);
  EXPECT_THROW(ref.get("field1"), std::logic_error);

  EXPECT_THROW(ref.as<string_t>(), std::bad_any_cast);
  EXPECT_TRUE(ref.tryAs<string_t>() == nullptr);
}

TEST(RuntimeTest, Int) {
  int32_t value = 1;
  Ref ref = Ref::to(value);
  EXPECT_EQ(ref.type(), Type::get<i32_t>());
  EXPECT_FALSE(ref.empty());
  EXPECT_TRUE(ref.add(ref));
  EXPECT_EQ(value, 2);
  EXPECT_EQ(ref, Ref::to(2));
  EXPECT_EQ(ref, Value::of(2));

  ref.clear();
  EXPECT_TRUE(ref.empty());
  EXPECT_EQ(value, 0);
  EXPECT_EQ(ref.as<i32_t>(), 0);
  EXPECT_EQ(ref, Ref::to(0));
  EXPECT_EQ(ref, Value::create<i32_t>());
}

TEST(RuntimeTest, List) {
  std::vector<std::string> value;
  std::string elem = "hi";
  auto ref = Ref::to<list<string_t>>(value);
  EXPECT_TRUE(ref.empty());
  EXPECT_EQ(ref.size(), 0);
  ref.append(Ref::to<string_t>(elem));
  EXPECT_THAT(value, ::testing::ElementsAre("hi"));

  EXPECT_FALSE(ref.empty());
  EXPECT_EQ(ref.size(), 1);
  EXPECT_THROW(ref[FieldId{1}], std::logic_error);
  EXPECT_THROW(ref["field1"], std::logic_error);
  EXPECT_EQ(ref[0], "hi");
  EXPECT_EQ(ref[Ordinal{1}], "hi");
  EXPECT_THROW(ref[1], std::out_of_range);
  EXPECT_THROW(ref.add(Ref::to<string_t>(value[0])), std::runtime_error);
  EXPECT_THROW(ref[Ref::to(0)], std::logic_error);

  ref.clear();
  EXPECT_TRUE(ref.empty());
  EXPECT_TRUE(value.empty());
}

TEST(RuntimeTest, Set) {
  std::set<std::string> value;
  auto ref = Ref::to<set<string_t>>(value);
  EXPECT_TRUE(ref.empty());
  EXPECT_EQ(ref.size(), 0);
  EXPECT_TRUE(ref.add("hi"));
  EXPECT_THAT(value, ::testing::ElementsAre("hi"));

  EXPECT_FALSE(ref.empty());
  EXPECT_EQ(ref.size(), 1);
  EXPECT_THROW(ref.get(FieldId{1}), std::runtime_error);
  EXPECT_THROW(ref.get("hi"), std::runtime_error);
  EXPECT_THROW(ref.get(Ref::to<string_t>("hi")), std::runtime_error);

  ref.clear();
  EXPECT_TRUE(ref.empty());
  EXPECT_TRUE(value.empty());
}

TEST(RuntimeTest, Map) {
  std::map<std::string, int> value;
  auto ref = Ref::to<map<string_t, i32_t>>(value);
  EXPECT_TRUE(ref.empty());
  EXPECT_EQ(ref.size(), 0);
  EXPECT_FALSE(ref.put("one", 1));
  EXPECT_EQ(value["one"], 1);

  ref["one"] = 2;
  EXPECT_EQ(value["one"], 2);

  EXPECT_FALSE(ref.empty());
  EXPECT_EQ(ref.size(), 1);
  EXPECT_THROW(ref.put(FieldId{1}, 2), std::logic_error);
  EXPECT_THROW(ref[FieldId{1}], std::logic_error);
  EXPECT_EQ(ref["one"], 2);
  EXPECT_EQ(ref["two"], 0);

  ref.clear();
  EXPECT_TRUE(ref.empty());
  EXPECT_TRUE(value.empty());
}

TEST(RuntimeTest, DynMap) {
  using Tag = type::map<type::string_t, type::string_t>;
  auto map = Value::create<Tag>();
  map["hi"] = "bye";
  EXPECT_EQ(map.size(), 1);
  EXPECT_TRUE(map["empty"].empty());
  EXPECT_EQ(map.size(), 2);
  EXPECT_EQ(map["hi"], "bye");
  EXPECT_THROW(map.get("bye"), std::out_of_range);
}

TEST(RuntimeTest, DynStruct) {
  Value obj = Value::create<type::UriStruct>();
  obj["scheme"] = "http";
  type::UriStruct& data = obj.as<type::UriStruct>();
  EXPECT_EQ(data.scheme(), "http");
  data.scheme() = "ftp";
  EXPECT_EQ(obj["scheme"], "ftp");
}

TEST(RuntimeTest, MapAdd) {
  std::map<std::string, int> value;
  auto ref = Ref::to<map<string_t, i32_t>>(value);

  // ensure = add if not present.
  EXPECT_EQ(ref.ensure("zero"), 0);
  EXPECT_EQ(ref.ensure("one", 1), 1);
  EXPECT_EQ(ref.ensure("one", 2), 1);
  EXPECT_EQ(value["zero"], 0);
  EXPECT_EQ(value["one"], 1);
}

// TODO(afuller): Add test for ensuring an optional field.
TEST(RuntimeTest, Struct) {
  type::UriStruct actual;
  auto ref = Ref::to(actual);
  EXPECT_FALSE(ref.empty());
  EXPECT_EQ(ref.size(), 5);
  EXPECT_EQ(*actual.scheme(), "");
  EXPECT_EQ(ref[FieldId{1}], "");
  EXPECT_EQ(ref.ensure("scheme", "baz"), "");

  EXPECT_TRUE(ref.put(FieldId{1}, "foo"));
  EXPECT_EQ(*actual.scheme(), "foo");
  EXPECT_EQ(ref[FieldId{1}], "foo");
  EXPECT_EQ(ref.ensure(FieldId{1}, "baz"), "foo");
  ref.clear(FieldId{1});
  EXPECT_EQ(*actual.scheme(), "");
  EXPECT_EQ(ref[FieldId{1}], "");

  EXPECT_TRUE(ref.put("scheme", "bar"));
  EXPECT_EQ(*actual.scheme(), "bar");
  EXPECT_EQ(ref["scheme"], "bar");
  EXPECT_EQ(ref.ensure("scheme"), std::string("bar"));
  ref.clear("scheme");
  EXPECT_EQ(*actual.scheme(), "");
  EXPECT_EQ(ref["scheme"], "");

  EXPECT_THROW(ref[FieldId{}], std::out_of_range);
  EXPECT_THROW(ref["bad"], std::out_of_range);
  EXPECT_THROW(ref.clear(FieldId{}), std::out_of_range);
  EXPECT_THROW(ref.clear("bad"), std::out_of_range);
  EXPECT_THROW(ref.ensure(FieldId{}), std::out_of_range);
  EXPECT_THROW(ref.ensure("bad"), std::out_of_range);
  EXPECT_THROW(ref.put(FieldId{}, ""), std::out_of_range);
  EXPECT_THROW(ref.put("bad", ""), std::out_of_range);
}

TEST(RuntimeTest, IdenticalRef) {
  float value = 1.0f;
  auto ref = Ref::to(value);
  EXPECT_FALSE(ref.empty());
  ref.clear();
  float zero = 0.0;
  float negZero = -0.0;
  double dblZero = 0.0;
  EXPECT_TRUE(ref.empty());
  EXPECT_TRUE(ref.identical(zero));
  EXPECT_FALSE(ref.identical(negZero));
  EXPECT_FALSE(ref.identical(dblZero));
}

TEST(RuntimeTest, ConstRef) {
  constexpr int32_t one = 1;
  auto ref = Ref::to(one);
  EXPECT_FALSE(ref.empty());
  EXPECT_TRUE(ref.identical(1));
  // Cannot be modified.
  EXPECT_THROW(ref.clear(), std::logic_error);
}

TEST(RuntimeTest, BinaryRef) {
  std::string data;
  auto ref = Ref::to<binary_t>(data);
  ref.assign("hi");
  EXPECT_EQ(data, "hi");
  ref = "bye";
  EXPECT_EQ(data, "bye");
}

TEST(RuntimeTest, IdenticalValue) {
  Value value;
  value = Value::of<float_t>(1.0f);
  EXPECT_FALSE(value.empty());
  value.clear();
  EXPECT_TRUE(value.empty());
  EXPECT_TRUE(value.identical(0.0f));
  EXPECT_FALSE(value.identical(-0.0f));
  EXPECT_FALSE(value.identical(0.0));
}

TEST(RuntimeTest, VoidValue) {
  Value value;
  EXPECT_EQ(value.type(), Type::get<void_t>());
  EXPECT_TRUE(value.empty());
  value.clear();
  EXPECT_TRUE(value.empty());

  EXPECT_THROW(value.as<string_t>(), std::bad_any_cast);
  EXPECT_TRUE(value.tryAs<string_t>() == nullptr);
}

TEST(RuntimeTest, IntValue) {
  Value value = Value::of<i32_t>(1);
  EXPECT_EQ(value.type(), Type::get<i32_t>());
  EXPECT_FALSE(value.empty());
  value.clear();
  EXPECT_TRUE(value.empty());

  EXPECT_EQ(value.as<i32_t>(), 0);
  value.as<i32_t>() = 2;
  EXPECT_FALSE(value.empty());

  EXPECT_EQ(value.as<i32_t>(), 2);
  value.assign(3);
  EXPECT_EQ(value.as<i32_t>(), 3);
  value = 4;
  EXPECT_EQ(value.as<i32_t>(), 4);
}

TEST(RuntimeTest, ListValue) {
  Value value;
  value = Value::create<list<string_t>>();
  EXPECT_TRUE(value.empty());
  value.as<list<string_t>>().emplace_back("hi");
  EXPECT_FALSE(value.empty());
  Value other(value);
  EXPECT_FALSE(other.empty());
  value.clear();
  EXPECT_TRUE(value.empty());
  EXPECT_TRUE(value.as<list<string_t>>().empty());
  value = other;
  EXPECT_FALSE(value.empty());
}

TEST(RuntimeTest, ListCppType) {
  using T = std::list<std::string>;
  using Tag = cpp_type<T, type::list<string_t>>;
  auto list = Value::create<Tag>();
  list.append("foo");
  EXPECT_EQ(list[0], "foo");
}

TEST(RuntimeTest, MapCppType) {
  using T = std::unordered_map<std::string, int>;
  using Tag = cpp_type<T, type::map<string_t, i32_t>>;

  auto map = Value::create<Tag>();
  map.put("foo", 2);
  Ref value = map["foo"];
  EXPECT_EQ(value.as<i32_t>(), 2);
  EXPECT_GT(value, 1);
  EXPECT_EQ(value, value);

  auto otherMap = Value::create<Tag>();
  EXPECT_NE(map, otherMap);
  otherMap.put("bar", 2);
  EXPECT_NE(map, otherMap);

  EXPECT_THROW(map < otherMap, std::logic_error);
}

TEST(RuntimeTest, IntInterOp) {
  int8_t data = 1;
  auto smallInt = Ref::to(data);
  auto largeInt = Value::of<i64_t>(2);

  EXPECT_EQ(smallInt, int8_t(1));
  EXPECT_LT(largeInt, 5L);

  EXPECT_EQ(smallInt, 1);
  EXPECT_EQ(smallInt, 1.0);
  EXPECT_EQ(largeInt, 2);
  EXPECT_EQ(largeInt, 2.0f);
  EXPECT_NE(largeInt, 2.1f);
  EXPECT_NE(smallInt, 0.9);
  EXPECT_LT(smallInt, 1.5f);
  EXPECT_GT(largeInt, 1.5);

  smallInt = 3;
  EXPECT_EQ(data, 3);
  smallInt = 500;
  EXPECT_EQ(data, -12); // TODO(afuller): Clamp or throw.
  largeInt = 4.5;
  EXPECT_EQ(largeInt, 4.0);
}

TEST(RuntimeTest, FloatInterOp) {
  EXPECT_EQ(Ref::to<double_t>(2.0), Ref::to<float_t>(2.0f));
  EXPECT_LT(Ref::to<float_t>(1.0), Ref::to<double_t>(2.0f));
  EXPECT_GT(
      Ref::to<double_t>(std::numeric_limits<double>::infinity()),
      Ref::to<float_t>(-std::numeric_limits<float>::infinity()));
}

TEST(RuntimeTest, StringBinaryInterOp) {
  using STag = type::string_t;
  using BTag = type::cpp_type<folly::IOBuf, type::binary_t>;

  auto stringHi = Value::of<STag>("hi");
  auto stringBye = Value::of<STag>("bye");

  auto binaryHiBuf = folly::IOBuf::wrapBufferAsValue("hi", 2);
  auto binaryHi = Ref::to<BTag>(binaryHiBuf);
  auto binaryByeBuf = folly::IOBuf::wrapBufferAsValue("bye", 3);
  auto binaryBye = ConstRef::to<BTag>(binaryByeBuf);

  // Compare
  EXPECT_EQ(stringHi, binaryHi);
  EXPECT_EQ(binaryBye, stringBye);
  EXPECT_NE(binaryHi, stringBye);
  EXPECT_GT(stringHi, binaryBye);

  // Assign
  binaryHi = stringBye;
  EXPECT_EQ(binaryHi, stringBye);
  EXPECT_EQ(binaryHi, binaryBye);
  binaryHi.assign("hi");
  EXPECT_EQ(binaryHi, stringHi);
  stringHi.assign(binaryBye);
  EXPECT_EQ(stringHi, stringBye);
  EXPECT_EQ(stringHi, binaryBye);
  stringHi = "hi";
  EXPECT_EQ(stringHi, binaryHi);
}

} // namespace
} // namespace apache::thrift::type
