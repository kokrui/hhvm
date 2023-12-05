/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/sink/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/sink/gen-cpp2/SinkService.h"

#include <thrift/lib/cpp2/gen/service_tcc.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> SinkService_method_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_method_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodAndReponse_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::InitialResponse*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodAndReponse_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::InitialException>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodSinkThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException1>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodSinkThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodFinalThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException2>>
    > SinkService_methodFinalThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodBothThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException1>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException2>>
    > SinkService_methodBothThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodFast_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodFast_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_method(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::executeRequest_method<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_method(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_method_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.method", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "method", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "method");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_method<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_method<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_tm_method(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_method(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_method_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_method_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_method_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeResponse("method", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_method(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "method");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::executeRequest_methodAndReponse<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_methodAndReponse(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_methodAndReponse_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodAndReponse", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "methodAndReponse", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "methodAndReponse");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_methodAndReponse<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_methodAndReponse<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_tm_methodAndReponse(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodAndReponse(apache::thrift::ContextStack* ctx, ::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_methodAndReponse_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_methodAndReponse_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_methodAndReponse_presult::FinalResponsePResultType;
  result.get<0>().value = &_return.response;
  result.setIsSet(0, true);

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return.sinkConsumer),
      std::move(executor));

  return {serializeResponse("methodAndReponse", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodAndReponse");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::executeRequest_methodThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_methodThrow(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_methodThrow_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodThrow", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "methodThrow", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "methodThrow");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_methodThrow<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_methodThrow<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_tm_methodThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_methodThrow_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_methodThrow_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_methodThrow_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeResponse("methodThrow", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ::cpp2::SinkService_methodThrow_presult result;
  if (ew.with_exception([&]( ::cpp2::InitialException& e) {
    if (ctx) {
      ctx->userExceptionWrapped(true, ew);
    }
    ::apache::thrift::util::appendExceptionToHeader(ew, *reqCtx);
    ::apache::thrift::util::appendErrorClassificationToHeader< ::cpp2::InitialException>(ew, *reqCtx);
    result.fields.get<0>().ref() = e;
    result.fields.setIsSet(0, true);
  }
  )) {} else
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodThrow");
    return;
  }
  ProtocolOut_ prot;
  auto response = serializeResponse("methodThrow", &prot, ctx, result.fields);
  auto payload = std::move(response).extractPayload(
      req->includeEnvelope(), prot.protocolType(), protoSeqId, apache::thrift::MessageType::T_REPLY, "methodThrow");
  payload.transform(reqCtx->getHeader()->getWriteTransforms());
  req->sendSinkReply(std::move(payload), apache::thrift::detail::SinkConsumerImpl{});
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::executeRequest_methodSinkThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_methodSinkThrow(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_methodSinkThrow_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodSinkThrow", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "methodSinkThrow", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "methodSinkThrow");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_methodSinkThrow<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_methodSinkThrow<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_tm_methodSinkThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodSinkThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_methodSinkThrow_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_methodSinkThrow_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_methodSinkThrow_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeResponse("methodSinkThrow", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodSinkThrow");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::executeRequest_methodFinalThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_methodFinalThrow(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_methodFinalThrow_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodFinalThrow", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "methodFinalThrow", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "methodFinalThrow");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_methodFinalThrow<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_methodFinalThrow<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_tm_methodFinalThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodFinalThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_methodFinalThrow_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_methodFinalThrow_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_methodFinalThrow_presult::FinalResponsePResultType;

  struct ExMapType {
    bool operator()(FinalResponsePResultType& res, folly::exception_wrapper ew) {
      if (ew.with_exception([&]( ::cpp2::SinkException2& e) {
            res.get<1>().ref() = e;
            res.setIsSet(1, true);
          })) {
        return true;
      }
      return false;
    }
  };

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeResponse("methodFinalThrow", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodFinalThrow");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::executeRequest_methodBothThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_methodBothThrow(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_methodBothThrow_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodBothThrow", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "methodBothThrow", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "methodBothThrow");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_methodBothThrow<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_methodBothThrow<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_tm_methodBothThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodBothThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_methodBothThrow_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_methodBothThrow_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_methodBothThrow_presult::FinalResponsePResultType;

  struct ExMapType {
    bool operator()(FinalResponsePResultType& res, folly::exception_wrapper ew) {
      if (ew.with_exception([&]( ::cpp2::SinkException2& e) {
            res.get<1>().ref() = e;
            res.setIsSet(1, true);
          })) {
        return true;
      }
      return false;
    }
  };

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeResponse("methodBothThrow", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodBothThrow");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodFast(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, FOLLY_MAYBE_UNUSED apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, nullptr, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  apache::thrift::ServerRequest serverRequest{std::move(req), std::move(serializedRequest), ctx, {}, {}, {}, {}};
  executeRequest_methodFast<ProtocolIn_, ProtocolOut_>(std::move(serverRequest));
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::executeRequest_methodFast(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::SinkService_methodFast_pargs args;
  apache::thrift::ContextStack::UniquePtr ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodFast", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "methodFast", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "methodFast");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_methodFast<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_methodFast<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , nullptr
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  iface_->async_eb_methodFast(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::SerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodFast(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  ::cpp2::SinkService_methodFast_presult::FieldsType result;
  using SinkPResultType = ::cpp2::SinkService_methodFast_presult::SinkPResultType;
  using FinalResponsePResultType = ::cpp2::SinkService_methodFast_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeResponse("methodFast", &prot, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodFast(apache::thrift::ResponseChannelRequest::UniquePtr req,FOLLY_MAYBE_UNUSED int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodFast");
    return;
  }
}


} // cpp2
