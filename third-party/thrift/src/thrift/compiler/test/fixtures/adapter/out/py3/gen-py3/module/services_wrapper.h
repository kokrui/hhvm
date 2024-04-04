/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once
#if __has_include(<thrift/compiler/test/fixtures/adapter/gen-cpp2/Service.h>)
#include <thrift/compiler/test/fixtures/adapter/gen-cpp2/Service.h>
#else
#include <thrift/compiler/test/fixtures/adapter/gen-cpp2/module_handlers.h>
#endif
#if __has_include(<thrift/compiler/test/fixtures/adapter/gen-cpp2/AdapterService.h>)
#include <thrift/compiler/test/fixtures/adapter/gen-cpp2/AdapterService.h>
#else
#include <thrift/compiler/test/fixtures/adapter/gen-cpp2/module_handlers.h>
#endif
#include <folly/python/futures.h>
#include <Python.h>

#include <memory>

namespace facebook {
namespace thrift {
namespace test {

class ServiceWrapper : virtual public ServiceSvIf {
  protected:
    PyObject *if_object;
    folly::Executor *executor;
  public:
    explicit ServiceWrapper(PyObject *if_object, folly::Executor *exc);
    void async_tm_func(apache::thrift::HandlerCallback<int32_t>::Ptr callback
        , std::unique_ptr<std::string> arg1
        , std::unique_ptr<std::string> arg2
        , std::unique_ptr<::facebook::thrift::test::Foo> arg3
    ) override;
folly::SemiFuture<folly::Unit> semifuture_onStartServing() override;
folly::SemiFuture<folly::Unit> semifuture_onStopRequested() override;
};

std::shared_ptr<apache::thrift::ServerInterface> ServiceInterface(PyObject *if_object, folly::Executor *exc);


class AdapterServiceWrapper : virtual public AdapterServiceSvIf {
  protected:
    PyObject *if_object;
    folly::Executor *executor;
  public:
    explicit AdapterServiceWrapper(PyObject *if_object, folly::Executor *exc);
    void async_tm_count(apache::thrift::HandlerCallback<std::unique_ptr<::facebook::thrift::test::CountingStruct>>::Ptr callback) override;
    void async_tm_adaptedTypes(apache::thrift::HandlerCallback<std::unique_ptr<::facebook::thrift::test::HeapAllocated>>::Ptr callback
        , std::unique_ptr<::facebook::thrift::test::HeapAllocated> arg
    ) override;
folly::SemiFuture<folly::Unit> semifuture_onStartServing() override;
folly::SemiFuture<folly::Unit> semifuture_onStopRequested() override;
};

std::shared_ptr<apache::thrift::ServerInterface> AdapterServiceInterface(PyObject *if_object, folly::Executor *exc);
} // namespace facebook
} // namespace thrift
} // namespace test
