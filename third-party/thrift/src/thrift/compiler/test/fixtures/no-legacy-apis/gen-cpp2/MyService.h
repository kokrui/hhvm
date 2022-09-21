/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/no-legacy-apis/gen-cpp2/MyServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/no-legacy-apis/gen-cpp2/module_types.h"
#include "thrift/annotation/gen-cpp2/thrift_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace test { namespace fixtures { namespace basic {
class MyService;
class MyServiceAsyncProcessor;

class MyServiceServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
}}} // test::fixtures::basic

namespace apache::thrift {
template <>
class ServiceHandler<::test::fixtures::basic::MyService> : public apache::thrift::ServerInterface {
 public:
  std::string_view getGeneratedName() const override { return "MyService"; }

  static const char* __fbthrift_thrift_uri() {
    return "test.dev/fixtures/no-legacy-apis/MyService";
  }

  typedef ::test::fixtures::basic::MyServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

  virtual void sync_query(::test::fixtures::basic::MyStruct& /*_return*/, std::unique_ptr<::test::fixtures::basic::MyUnion> /*u*/);
  virtual void query(::test::fixtures::basic::MyStruct& /*_return*/, std::unique_ptr<::test::fixtures::basic::MyUnion> /*u*/);
  virtual folly::Future<std::unique_ptr<::test::fixtures::basic::MyStruct>> future_query(std::unique_ptr<::test::fixtures::basic::MyUnion> p_u);
  virtual folly::SemiFuture<std::unique_ptr<::test::fixtures::basic::MyStruct>> semifuture_query(std::unique_ptr<::test::fixtures::basic::MyUnion> p_u);
#if FOLLY_HAS_COROUTINES
  virtual folly::coro::Task<std::unique_ptr<::test::fixtures::basic::MyStruct>> co_query(std::unique_ptr<::test::fixtures::basic::MyUnion> p_u);
  virtual folly::coro::Task<std::unique_ptr<::test::fixtures::basic::MyStruct>> co_query(apache::thrift::RequestParams params, std::unique_ptr<::test::fixtures::basic::MyUnion> p_u);
#endif
  virtual void async_tm_query(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::test::fixtures::basic::MyStruct>>> callback, std::unique_ptr<::test::fixtures::basic::MyUnion> p_u);
 private:
  static ::test::fixtures::basic::MyServiceServiceInfoHolder __fbthrift_serviceInfoHolder;
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_query{apache::thrift::detail::si::InvocationType::AsyncTm};
};

} // namespace apache::thrift

namespace test { namespace fixtures { namespace basic {
using MyServiceSvIf [[deprecated("Use apache::thrift::ServiceHandler<MyService> instead")]] = ::apache::thrift::ServiceHandler<MyService>;
}}} // test::fixtures::basic
namespace test { namespace fixtures { namespace basic {
class MyServiceSvNull : public ::apache::thrift::ServiceHandler<MyService> {
 public:
  void query(::test::fixtures::basic::MyStruct& /*_return*/, std::unique_ptr<::test::fixtures::basic::MyUnion> /*u*/) override;
};

class MyServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessorBase {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  ::apache::thrift::ServiceHandler<::test::fixtures::basic::MyService>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessorBase::ProcessFuncs<MyServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessorBase::ProcessMap<ProcessFuncs>;
  static const MyServiceAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const MyServiceAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_query(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_query(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::SerializedResponse return_query(apache::thrift::ContextStack* ctx, ::test::fixtures::basic::MyStruct const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_query(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  MyServiceAsyncProcessor(::apache::thrift::ServiceHandler<::test::fixtures::basic::MyService>* iface) :
      iface_(iface) {}
  ~MyServiceAsyncProcessor() override {}
};

}}} // test::fixtures::basic
