/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#include "hphp/runtime/base/apc-handle.h"

#include "hphp/runtime/base/apc-array.h"
#include "hphp/runtime/base/apc-bespoke.h"
#include "hphp/runtime/base/apc-clsmeth.h"
#include "hphp/runtime/base/apc-collection.h"
#include "hphp/runtime/base/apc-named-entity.h"
#include "hphp/runtime/base/apc-object.h"
#include "hphp/runtime/base/apc-rclass-meth.h"
#include "hphp/runtime/base/apc-rfunc.h"
#include "hphp/runtime/base/apc-string.h"
#include "hphp/runtime/base/apc-typed-value.h"
#include "hphp/runtime/base/mixed-array.h"
#include "hphp/runtime/ext/apc/ext_apc.h"
#include "hphp/runtime/vm/class-meth-data-ref.h"

namespace HPHP {

//////////////////////////////////////////////////////////////////////

const StaticString s_invalidMethCaller("Cannot store meth_caller in APC");

APCHandle::Pair APCHandle::Create(const_variant_ref source,
                                  APCHandleLevel level,
                                  bool unserializeObj) {
  auto const cell = source.asTypedValue();
  switch (cell.type()) {
    case KindOfUninit: {
      auto const value = APCTypedValue::tvUninit();
      return {value->getHandle(), sizeof(APCTypedValue)};
    }
    case KindOfNull: {
      auto const value = APCTypedValue::tvNull();
      return {value->getHandle(), sizeof(APCTypedValue)};
    }
    case KindOfBoolean: {
      auto const value = val(cell).num ? APCTypedValue::tvTrue()
                                       : APCTypedValue::tvFalse();
      return {value->getHandle(), sizeof(APCTypedValue)};
    }
    case KindOfInt64: {
      auto const value = new APCTypedValue(val(cell).num);
      return {value->getHandle(), sizeof(APCTypedValue)};
    }
    case KindOfDouble: {
      auto const value = new APCTypedValue(val(cell).dbl);
      return {value->getHandle(), sizeof(APCTypedValue)};
    }
    case KindOfRFunc:
      return APCRFunc::Construct(val(cell).prfunc);
    case KindOfFunc: {
      auto const func = val(cell).pfunc;
      if (func->isMethCaller()) {
        SystemLib::throwInvalidOperationExceptionObject(
          VarNR{s_invalidMethCaller.get()}
        );
      }
      auto const serialize_func =
        RuntimeOption::EvalAPCSerializeFuncs &&
        // Right now cls_meth() can serialize as an array, and attempting to
        // recursively serialize elements in the array will eventually attempt
        // to serialize a method pointer.
        !func->isMethod();
      if (serialize_func) {
        if (func->isPersistent()) {
          auto const value = new APCTypedValue(func);
          return {value->getHandle(), sizeof(APCTypedValue)};
        }
        auto const value = new APCNamedEntity(func);
        return {value->getHandle(), sizeof(APCNamedEntity)};
      }
      invalidFuncConversion("string");
    }
    case KindOfClass: {
      auto const cls = val(cell).pclass;
      if (cls->isPersistent()) {
        auto const value = new APCTypedValue(cls);
        return {value->getHandle(), sizeof(APCTypedValue)};
      }
      auto const value = new APCNamedEntity(cls);
      return {value->getHandle(), sizeof(APCNamedEntity)};
    }
    case KindOfLazyClass: {
      auto const value = new APCTypedValue(val(cell).plazyclass);
      return {value->getHandle(), sizeof(APCTypedValue)};
    }
    case KindOfPersistentString:
    case KindOfString: {
      auto const s = val(cell).pstr;
      if (auto const value = APCTypedValue::HandlePersistent(s)) {
        return value;
      }
      auto const st = lookupStaticString(s);
      if (st) {
        auto const value = new APCTypedValue(APCTypedValue::StaticStr{}, st);
        return {value->getHandle(), sizeof(APCTypedValue)};
      }
      if (apcExtension::UseUncounted) {
        auto const st = StringData::MakeUncounted(s->slice());
        auto const value = new APCTypedValue(APCTypedValue::UncountedStr{}, st);
        return {value->getHandle(), st->size() + sizeof(APCTypedValue)};
      }
      return APCString::MakeSharedString(s);
    }

    case KindOfPersistentVec:
    case KindOfVec: {
      auto const ad = val(cell).parr;
      assertx(ad->isVecType());
      return APCArray::MakeSharedVec(ad, level, unserializeObj);
    }

    case KindOfPersistentDict:
    case KindOfDict: {
      auto const ad = val(cell).parr;
      assertx(ad->isDictType());
      return APCArray::MakeSharedDict(ad, level, unserializeObj);
    }

    case KindOfPersistentKeyset:
    case KindOfKeyset: {
      auto const ad = val(cell).parr;
      assertx(ad->isKeysetType());
      return APCArray::MakeSharedKeyset(ad, level, unserializeObj);
    }

    case KindOfObject:
      if (val(cell).pobj->isCollection()) {
        return APCCollection::Make(val(cell).pobj,
                                   level,
                                   unserializeObj);
      }
      return unserializeObj ? APCObject::Construct(val(cell).pobj) :
             APCString::MakeSerializedObject(apc_serialize(source));

    case KindOfResource:
      return APCArray::MakeSharedEmptyVec();

    case KindOfClsMeth: {
      if (RO::EvalAPCSerializeClsMeth) {
        auto const meth = val(cell).pclsmeth;
        if (meth->getCls()->isPersistent()) {
          auto const value = new APCTypedValue(meth);
          return {value->getHandle(), sizeof(APCTypedValue)};
        }
        auto const value = new APCClsMeth(meth->getCls(), meth->getFunc());
        return {value->getHandle(), sizeof(APCClsMeth)};
      }
      raiseClsMethToVecWarningHelper();
      auto arr = clsMethToVecHelper(val(cell).pclsmeth);
      assertx(arr->isVecType());
      return APCArray::MakeSharedVec(arr.detach(), level, unserializeObj);
    }

    case KindOfRClsMeth:
      return APCRClsMeth::Construct(val(cell).prclsmeth);

    case KindOfRecord: // TODO (T41019518)
      raise_error(Strings::RECORD_NOT_SUPPORTED);
  }
  not_reached();
}

Variant APCHandle::toLocalHelper() const {
  assertx(!isTypedValue());
  switch (m_kind) {
    case APCKind::Uninit:
    case APCKind::Null:
    case APCKind::Bool:
    case APCKind::Int:
    case APCKind::Double:
    case APCKind::PersistentFunc:
    case APCKind::PersistentClass:
    case APCKind::LazyClass:
    case APCKind::PersistentClsMeth:
    case APCKind::StaticArray:
    case APCKind::StaticBespoke:
    case APCKind::StaticString:
    case APCKind::UncountedArray:
    case APCKind::UncountedBespoke:
    case APCKind::UncountedString:
      not_reached();

    case APCKind::FuncEntity:
      return APCNamedEntity::fromHandle(this)->getEntityOrNull();

    case APCKind::ClassEntity:
      return APCNamedEntity::fromHandle(this)->getEntityOrNull();

    case APCKind::ClsMeth:
      return APCClsMeth::fromHandle(this)->getEntityOrNull();

    case APCKind::SharedString:
      return Variant::attach(
        StringData::MakeProxy(APCString::fromHandle(this))
      );
    case APCKind::SerializedVec: {
      auto const serVec = APCString::fromHandle(this)->getStringData();
      auto const v = apc_unserialize(serVec->data(), serVec->size());
      assertx(v.isVec());
      return v;
    }
    case APCKind::SerializedDict: {
      auto const serDict = APCString::fromHandle(this)->getStringData();
      auto const v = apc_unserialize(serDict->data(), serDict->size());
      assertx(v.isDict());
      return v;
    }
    case APCKind::SerializedKeyset: {
      auto const serKeyset = APCString::fromHandle(this)->getStringData();
      auto const v = apc_unserialize(serKeyset->data(), serKeyset->size());
      assertx(v.isKeyset());
      return v;
    }
    case APCKind::SharedVec:
      return Variant::attach(
        APCArray::fromHandle(this)->toLocalVec()
      );
    case APCKind::SharedLegacyVec:
      return Variant::attach(
        APCArray::fromHandle(this)->toLocalLegacyVec()
      );
    case APCKind::SharedDict:
      return Variant::attach(
        APCArray::fromHandle(this)->toLocalDict()
      );
    case APCKind::SharedLegacyDict:
      return Variant::attach(
        APCArray::fromHandle(this)->toLocalLegacyDict()
      );
    case APCKind::SharedKeyset:
      return Variant::attach(
        APCArray::fromHandle(this)->toLocalKeyset()
      );
    case APCKind::SerializedObject: {
      auto const serObj = APCString::fromHandle(this)->getStringData();
      return apc_unserialize(serObj->data(), serObj->size());
    }
    case APCKind::SharedCollection:
      return APCCollection::fromHandle(this)->createObject();
    case APCKind::SharedObject:
      return APCObject::MakeLocalObject(this);
    case APCKind::RFunc:
      return APCRFunc::Make(this);
    case APCKind::RClsMeth:
      return APCRClsMeth::Make(this);
  }
  not_reached();
}

void APCHandle::deleteShared() {
  assertx(checkInvariants());
  switch (m_kind) {
    case APCKind::Uninit:
    case APCKind::Null:
    case APCKind::Bool:
      return;
    case APCKind::Int:
    case APCKind::Double:
    case APCKind::StaticArray:
    case APCKind::StaticString:
    case APCKind::PersistentFunc:
    case APCKind::PersistentClass:
    case APCKind::LazyClass:
    case APCKind::PersistentClsMeth:
      delete APCTypedValue::fromHandle(this);
      return;

    case APCKind::ClsMeth:
      delete APCClsMeth::fromHandle(this);
      return;

    case APCKind::FuncEntity:
      delete APCNamedEntity::fromHandle(this);
      return;

    case APCKind::ClassEntity:
      delete APCNamedEntity::fromHandle(this);
      return;

    case APCKind::SharedString:
    case APCKind::SerializedVec:
    case APCKind::SerializedDict:
    case APCKind::SerializedKeyset:
    case APCKind::SerializedObject:
      APCString::Delete(APCString::fromHandle(this));
      return;

    case APCKind::SharedVec:
    case APCKind::SharedLegacyVec:
    case APCKind::SharedDict:
    case APCKind::SharedLegacyDict:
    case APCKind::SharedKeyset:
      APCArray::Delete(this);
      return;

    case APCKind::SharedObject:
      APCObject::Delete(this);
      return;

    case APCKind::SharedCollection:
      APCCollection::Delete(this);
      return;

    case APCKind::RFunc:
      APCRFunc::Delete(this);
      return;

    case APCKind::RClsMeth:
      APCRClsMeth::Delete(this);
      return;

    case APCKind::StaticBespoke:
      freeAPCBespoke(APCTypedValue::fromHandle(this));
      return;

    case APCKind::UncountedArray:
    case APCKind::UncountedBespoke:
    case APCKind::UncountedString:
      assertx(false);
      return;
  }
  not_reached();
}

bool APCHandle::checkInvariants() const {
  switch (m_kind) {
    case APCKind::Uninit:
      assertx(m_type == KindOfUninit);
      return true;
    case APCKind::Null:
      assertx(m_type == KindOfNull);
      return true;
    case APCKind::Bool:
      assertx(m_type == KindOfBoolean);
      return true;
    case APCKind::Int:
      assertx(m_type == KindOfInt64);
      return true;
    case APCKind::Double:
      assertx(m_type == KindOfDouble);
      return true;
    case APCKind::PersistentFunc:
      assertx(m_type == KindOfFunc);
      return true;
    case APCKind::PersistentClass:
      assertx(m_type == KindOfClass);
      return true;
    case APCKind::LazyClass:
      assertx(m_type == KindOfLazyClass);
      return true;
    case APCKind::PersistentClsMeth:
      assertx(m_type == KindOfClsMeth);
      return true;
    case APCKind::StaticString:
    case APCKind::UncountedString:
      assertx(m_type == KindOfPersistentString);
      return true;
    case APCKind::StaticArray:
    case APCKind::StaticBespoke:
    case APCKind::UncountedArray:
    case APCKind::UncountedBespoke:
      assertx(m_type == KindOfPersistentVec ||
              m_type == KindOfPersistentDict ||
              m_type == KindOfPersistentKeyset);
      return true;
    case APCKind::FuncEntity:
    case APCKind::ClassEntity:
    case APCKind::ClsMeth:
    case APCKind::RFunc:
    case APCKind::RClsMeth:
    case APCKind::SharedString:
    case APCKind::SharedVec:
    case APCKind::SharedLegacyVec:
    case APCKind::SharedDict:
    case APCKind::SharedLegacyDict:
    case APCKind::SharedKeyset:
    case APCKind::SharedObject:
    case APCKind::SharedCollection:
    case APCKind::SerializedVec:
    case APCKind::SerializedDict:
    case APCKind::SerializedKeyset:
    case APCKind::SerializedObject:
      assertx(m_type == kInvalidDataType);
      return true;
  }
  not_reached();
  return false;
}

//////////////////////////////////////////////////////////////////////

}
