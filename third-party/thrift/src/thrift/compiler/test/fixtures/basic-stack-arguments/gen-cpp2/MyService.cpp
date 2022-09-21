/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/MyService.h"
#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/MyService.tcc"
#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

std::unique_ptr<apache::thrift::AsyncProcessor> apache::thrift::ServiceHandler<::cpp2::MyService>::getProcessor() {
  return std::make_unique<::cpp2::MyServiceAsyncProcessor>(this);
}

apache::thrift::ServiceHandler<::cpp2::MyService>::CreateMethodMetadataResult apache::thrift::ServiceHandler<::cpp2::MyService>::createMethodMetadata() {
  return ::apache::thrift::detail::ap::createMethodMetadataMap<::cpp2::MyServiceAsyncProcessor>(getServiceRequestInfoMap().value().get());
}

std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> apache::thrift::ServiceHandler<::cpp2::MyService>::getServiceRequestInfoMap() const {
  return __fbthrift_serviceInfoHolder.requestInfoMap();
}

::cpp2::MyServiceServiceInfoHolder apache::thrift::ServiceHandler<::cpp2::MyService>::__fbthrift_serviceInfoHolder;


bool apache::thrift::ServiceHandler<::cpp2::MyService>::sync_hasDataById(::std::int64_t /*id*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("hasDataById");
}

bool apache::thrift::ServiceHandler<::cpp2::MyService>::hasDataById(::std::int64_t p_id) {
  return sync_hasDataById(p_id);
}

folly::SemiFuture<bool> apache::thrift::ServiceHandler<::cpp2::MyService>::semifuture_hasDataById(::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_hasDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  return hasDataById(p_id);
}

folly::Future<bool> apache::thrift::ServiceHandler<::cpp2::MyService>::future_hasDataById(::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_hasDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_hasDataById(p_id), getInternalKeepAlive());
}

#if FOLLY_HAS_COROUTINES
folly::coro::Task<bool> apache::thrift::ServiceHandler<::cpp2::MyService>::co_hasDataById(::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::Coro};
  __fbthrift_invocation_hasDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
  apache::thrift::detail::si::ignore(p_id);
  folly::throw_exception(apache::thrift::detail::si::UnimplementedCoroMethod::withoutCapturedArgs());
}

folly::coro::Task<bool> apache::thrift::ServiceHandler<::cpp2::MyService>::co_hasDataById(apache::thrift::RequestParams /* params */, ::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::CoroParam};
  __fbthrift_invocation_hasDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Coro, std::memory_order_relaxed);
  return co_hasDataById(p_id);
}
#endif // FOLLY_HAS_COROUTINES

void apache::thrift::ServiceHandler<::cpp2::MyService>::async_tm_hasDataById(std::unique_ptr<apache::thrift::HandlerCallback<bool>> callback, ::std::int64_t p_id) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
#if FOLLY_HAS_COROUTINES
determineInvocationType:
#endif // FOLLY_HAS_COROUTINES
  auto invocationType = __fbthrift_invocation_hasDataById.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
#if FOLLY_HAS_COROUTINES
        __fbthrift_invocation_hasDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::CoroParam, std::memory_order_relaxed);
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_hasDataById(params, p_id);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
#else // FOLLY_HAS_COROUTINES
        __fbthrift_invocation_hasDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
#endif // FOLLY_HAS_COROUTINES
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_hasDataById(p_id);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_hasDataById(p_id);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
#if FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::CoroParam:
      {
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_hasDataById(params, p_id);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Coro:
      {
        auto task = co_hasDataById(p_id);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
#endif // FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        callback->result(hasDataById(p_id));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
#if FOLLY_HAS_COROUTINES
  } catch (apache::thrift::detail::si::UnimplementedCoroMethod&) {
    goto determineInvocationType;
#endif // FOLLY_HAS_COROUTINES
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

void apache::thrift::ServiceHandler<::cpp2::MyService>::sync_getDataById(::std::string& /*_return*/, ::std::int64_t /*id*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("getDataById");
}

void apache::thrift::ServiceHandler<::cpp2::MyService>::getDataById(::std::string& _return, ::std::int64_t p_id) {
  return sync_getDataById(_return, p_id);
}

folly::SemiFuture<::std::string> apache::thrift::ServiceHandler<::cpp2::MyService>::semifuture_getDataById(::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_getDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  ::std::string ret;
  getDataById(ret, p_id);
  return folly::makeSemiFuture(std::move(ret));
}

folly::Future<::std::string> apache::thrift::ServiceHandler<::cpp2::MyService>::future_getDataById(::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_getDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_getDataById(p_id), getInternalKeepAlive());
}

#if FOLLY_HAS_COROUTINES
folly::coro::Task<::std::string> apache::thrift::ServiceHandler<::cpp2::MyService>::co_getDataById(::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::Coro};
  __fbthrift_invocation_getDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
  apache::thrift::detail::si::ignore(p_id);
  folly::throw_exception(apache::thrift::detail::si::UnimplementedCoroMethod::withoutCapturedArgs());
}

folly::coro::Task<::std::string> apache::thrift::ServiceHandler<::cpp2::MyService>::co_getDataById(apache::thrift::RequestParams /* params */, ::std::int64_t p_id) {
  auto expected{apache::thrift::detail::si::InvocationType::CoroParam};
  __fbthrift_invocation_getDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Coro, std::memory_order_relaxed);
  return co_getDataById(p_id);
}
#endif // FOLLY_HAS_COROUTINES

void apache::thrift::ServiceHandler<::cpp2::MyService>::async_tm_getDataById(std::unique_ptr<apache::thrift::HandlerCallback<::std::string>> callback, ::std::int64_t p_id) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
#if FOLLY_HAS_COROUTINES
determineInvocationType:
#endif // FOLLY_HAS_COROUTINES
  auto invocationType = __fbthrift_invocation_getDataById.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
#if FOLLY_HAS_COROUTINES
        __fbthrift_invocation_getDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::CoroParam, std::memory_order_relaxed);
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_getDataById(params, p_id);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
#else // FOLLY_HAS_COROUTINES
        __fbthrift_invocation_getDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
#endif // FOLLY_HAS_COROUTINES
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_getDataById(p_id);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_getDataById(p_id);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
#if FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::CoroParam:
      {
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_getDataById(params, p_id);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Coro:
      {
        auto task = co_getDataById(p_id);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
#endif // FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        ::std::string _return;
        getDataById(_return, p_id);
        callback->result(_return);
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
#if FOLLY_HAS_COROUTINES
  } catch (apache::thrift::detail::si::UnimplementedCoroMethod&) {
    goto determineInvocationType;
#endif // FOLLY_HAS_COROUTINES
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

void apache::thrift::ServiceHandler<::cpp2::MyService>::sync_putDataById(::std::int64_t /*id*/, const ::std::string& /*data*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("putDataById");
}

void apache::thrift::ServiceHandler<::cpp2::MyService>::putDataById(::std::int64_t p_id, const ::std::string& p_data) {
  return sync_putDataById(p_id, p_data);
}

folly::SemiFuture<folly::Unit> apache::thrift::ServiceHandler<::cpp2::MyService>::semifuture_putDataById(::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_putDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  putDataById(p_id, p_data);
  return folly::makeSemiFuture();
}

folly::Future<folly::Unit> apache::thrift::ServiceHandler<::cpp2::MyService>::future_putDataById(::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_putDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_putDataById(p_id, p_data), getInternalKeepAlive());
}

#if FOLLY_HAS_COROUTINES
folly::coro::Task<void> apache::thrift::ServiceHandler<::cpp2::MyService>::co_putDataById(::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::Coro};
  __fbthrift_invocation_putDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
  apache::thrift::detail::si::ignore(p_id, p_data);
  folly::throw_exception(apache::thrift::detail::si::UnimplementedCoroMethod::withoutCapturedArgs());
}

folly::coro::Task<void> apache::thrift::ServiceHandler<::cpp2::MyService>::co_putDataById(apache::thrift::RequestParams /* params */, ::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::CoroParam};
  __fbthrift_invocation_putDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Coro, std::memory_order_relaxed);
  return co_putDataById(p_id, p_data);
}
#endif // FOLLY_HAS_COROUTINES

void apache::thrift::ServiceHandler<::cpp2::MyService>::async_tm_putDataById(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, ::std::int64_t p_id, const ::std::string& p_data) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
#if FOLLY_HAS_COROUTINES
determineInvocationType:
#endif // FOLLY_HAS_COROUTINES
  auto invocationType = __fbthrift_invocation_putDataById.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
#if FOLLY_HAS_COROUTINES
        __fbthrift_invocation_putDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::CoroParam, std::memory_order_relaxed);
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_putDataById(params, p_id, p_data);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
#else // FOLLY_HAS_COROUTINES
        __fbthrift_invocation_putDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
#endif // FOLLY_HAS_COROUTINES
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_putDataById(p_id, p_data);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_putDataById(p_id, p_data);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
#if FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::CoroParam:
      {
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_putDataById(params, p_id, p_data);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Coro:
      {
        auto task = co_putDataById(p_id, p_data);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
#endif // FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        putDataById(p_id, p_data);
        callback->done();
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
#if FOLLY_HAS_COROUTINES
  } catch (apache::thrift::detail::si::UnimplementedCoroMethod&) {
    goto determineInvocationType;
#endif // FOLLY_HAS_COROUTINES
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

void apache::thrift::ServiceHandler<::cpp2::MyService>::sync_lobDataById(::std::int64_t /*id*/, const ::std::string& /*data*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("lobDataById");
}

void apache::thrift::ServiceHandler<::cpp2::MyService>::lobDataById(::std::int64_t p_id, const ::std::string& p_data) {
  return sync_lobDataById(p_id, p_data);
}

folly::SemiFuture<folly::Unit> apache::thrift::ServiceHandler<::cpp2::MyService>::semifuture_lobDataById(::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_lobDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  lobDataById(p_id, p_data);
  return folly::makeSemiFuture();
}

folly::Future<folly::Unit> apache::thrift::ServiceHandler<::cpp2::MyService>::future_lobDataById(::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_lobDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_lobDataById(p_id, p_data), getInternalKeepAlive());
}

#if FOLLY_HAS_COROUTINES
folly::coro::Task<void> apache::thrift::ServiceHandler<::cpp2::MyService>::co_lobDataById(::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::Coro};
  __fbthrift_invocation_lobDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
  apache::thrift::detail::si::ignore(p_id, p_data);
  folly::throw_exception(apache::thrift::detail::si::UnimplementedCoroMethod::withoutCapturedArgs());
}

folly::coro::Task<void> apache::thrift::ServiceHandler<::cpp2::MyService>::co_lobDataById(apache::thrift::RequestParams /* params */, ::std::int64_t p_id, const ::std::string& p_data) {
  auto expected{apache::thrift::detail::si::InvocationType::CoroParam};
  __fbthrift_invocation_lobDataById.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Coro, std::memory_order_relaxed);
  return co_lobDataById(p_id, p_data);
}
#endif // FOLLY_HAS_COROUTINES

void apache::thrift::ServiceHandler<::cpp2::MyService>::async_tm_lobDataById(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback, ::std::int64_t p_id, const ::std::string& p_data) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
#if FOLLY_HAS_COROUTINES
determineInvocationType:
#endif // FOLLY_HAS_COROUTINES
  auto invocationType = __fbthrift_invocation_lobDataById.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
#if FOLLY_HAS_COROUTINES
        __fbthrift_invocation_lobDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::CoroParam, std::memory_order_relaxed);
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_lobDataById(params, p_id, p_data);
        apache::thrift::detail::si::async_tm_coro_oneway(std::move(callback), std::move(task));
        return;
#else // FOLLY_HAS_COROUTINES
        __fbthrift_invocation_lobDataById.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
#endif // FOLLY_HAS_COROUTINES
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_lobDataById(p_id, p_data);
        apache::thrift::detail::si::async_tm_future_oneway(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_lobDataById(p_id, p_data);
        apache::thrift::detail::si::async_tm_semifuture_oneway(std::move(callback), std::move(fut));
        return;
      }
#if FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::CoroParam:
      {
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_lobDataById(params, p_id, p_data);
        apache::thrift::detail::si::async_tm_coro_oneway(std::move(callback), std::move(task));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Coro:
      {
        auto task = co_lobDataById(p_id, p_data);
        apache::thrift::detail::si::async_tm_coro_oneway(std::move(callback), std::move(task));
        return;
      }
#endif // FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        lobDataById(p_id, p_data);
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
#if FOLLY_HAS_COROUTINES
  } catch (apache::thrift::detail::si::UnimplementedCoroMethod&) {
    goto determineInvocationType;
#endif // FOLLY_HAS_COROUTINES
  } catch (...) {
    callback->exception(std::current_exception());
  }
}


namespace cpp2 {

bool MyServiceSvNull::hasDataById(::std::int64_t /*id*/) {
  return 0;
}

void MyServiceSvNull::getDataById(::std::string& /*_return*/, ::std::int64_t /*id*/) {}

void MyServiceSvNull::putDataById(::std::int64_t /*id*/, const ::std::string& /*data*/) {
  return;
}

void MyServiceSvNull::lobDataById(::std::int64_t /*id*/, const ::std::string& /*data*/) {
  return;
}


const char* MyServiceAsyncProcessor::getServiceName() {
  return "MyService";
}

void MyServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<::apache::thrift::ServiceHandler<::cpp2::MyService>>::gen(response);
}

void MyServiceAsyncProcessor::processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

void MyServiceAsyncProcessor::processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, iface_, std::move(req), std::move(serializedRequest), methodMetadata, protType, context, eb, tm);
}

void MyServiceAsyncProcessor::executeRequest(apache::thrift::ServerRequest&& request, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) {
  apache::thrift::detail::ap::execute(this, std::move(request), apache::thrift::detail::ServerRequestHelper::protocol(request), methodMetadata);
}

const MyServiceAsyncProcessor::ProcessMap& MyServiceAsyncProcessor::getOwnProcessMap() {
  return kOwnProcessMap_;
}

const MyServiceAsyncProcessor::ProcessMap MyServiceAsyncProcessor::kOwnProcessMap_ {
  {"hasDataById",
    {&MyServiceAsyncProcessor::setUpAndProcess_hasDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::setUpAndProcess_hasDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_hasDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_hasDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"getDataById",
    {&MyServiceAsyncProcessor::setUpAndProcess_getDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::setUpAndProcess_getDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_getDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_getDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"putDataById",
    {&MyServiceAsyncProcessor::setUpAndProcess_putDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::setUpAndProcess_putDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_putDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_putDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"lobDataById",
    {&MyServiceAsyncProcessor::setUpAndProcess_lobDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::setUpAndProcess_lobDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_lobDataById<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &MyServiceAsyncProcessor::executeRequest_lobDataById<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
};

apache::thrift::ServiceRequestInfoMap const& MyServiceServiceInfoHolder::requestInfoMap() const {
  static folly::Indestructible<apache::thrift::ServiceRequestInfoMap> requestInfoMap{staticRequestInfoMap()};
  return *requestInfoMap;
}

apache::thrift::ServiceRequestInfoMap MyServiceServiceInfoHolder::staticRequestInfoMap() {
  apache::thrift::ServiceRequestInfoMap requestInfoMap = {
  {"hasDataById",
    {false,
     apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE,
     "MyService.hasDataById",
     std::nullopt,
     apache::thrift::concurrency::NORMAL}},
  {"getDataById",
    {false,
     apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE,
     "MyService.getDataById",
     std::nullopt,
     apache::thrift::concurrency::NORMAL}},
  {"putDataById",
    {false,
     apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE,
     "MyService.putDataById",
     std::nullopt,
     apache::thrift::concurrency::NORMAL}},
  {"lobDataById",
    {false,
     apache::thrift::RpcKind::SINGLE_REQUEST_NO_RESPONSE,
     "MyService.lobDataById",
     std::nullopt,
     apache::thrift::concurrency::NORMAL}},
  };

  return requestInfoMap;
}
} // cpp2
