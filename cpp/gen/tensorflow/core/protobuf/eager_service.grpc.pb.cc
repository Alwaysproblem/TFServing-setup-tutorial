// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: tensorflow/core/protobuf/eager_service.proto

#include "tensorflow/core/protobuf/eager_service.pb.h"
#include "tensorflow/core/protobuf/eager_service.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace tensorflow {
namespace eager {

static const char* EagerService_method_names[] = {
  "/tensorflow.eager.EagerService/CreateContext",
  "/tensorflow.eager.EagerService/UpdateContext",
  "/tensorflow.eager.EagerService/Enqueue",
  "/tensorflow.eager.EagerService/StreamingEnqueue",
  "/tensorflow.eager.EagerService/WaitQueueDone",
  "/tensorflow.eager.EagerService/RunComponentFunction",
  "/tensorflow.eager.EagerService/KeepAlive",
  "/tensorflow.eager.EagerService/CloseContext",
};

std::unique_ptr< EagerService::Stub> EagerService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< EagerService::Stub> stub(new EagerService::Stub(channel));
  return stub;
}

EagerService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_CreateContext_(EagerService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_UpdateContext_(EagerService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Enqueue_(EagerService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_StreamingEnqueue_(EagerService_method_names[3], ::grpc::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_WaitQueueDone_(EagerService_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RunComponentFunction_(EagerService_method_names[5], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_KeepAlive_(EagerService_method_names[6], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CloseContext_(EagerService_method_names[7], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status EagerService::Stub::CreateContext(::grpc::ClientContext* context, const ::tensorflow::eager::CreateContextRequest& request, ::tensorflow::eager::CreateContextResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_CreateContext_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::CreateContextResponse>* EagerService::Stub::AsyncCreateContextRaw(::grpc::ClientContext* context, const ::tensorflow::eager::CreateContextRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::CreateContextResponse>(channel_.get(), cq, rpcmethod_CreateContext_, context, request);
}

::grpc::Status EagerService::Stub::UpdateContext(::grpc::ClientContext* context, const ::tensorflow::eager::UpdateContextRequest& request, ::tensorflow::eager::UpdateContextResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_UpdateContext_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::UpdateContextResponse>* EagerService::Stub::AsyncUpdateContextRaw(::grpc::ClientContext* context, const ::tensorflow::eager::UpdateContextRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::UpdateContextResponse>(channel_.get(), cq, rpcmethod_UpdateContext_, context, request);
}

::grpc::Status EagerService::Stub::Enqueue(::grpc::ClientContext* context, const ::tensorflow::eager::EnqueueRequest& request, ::tensorflow::eager::EnqueueResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Enqueue_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::EnqueueResponse>* EagerService::Stub::AsyncEnqueueRaw(::grpc::ClientContext* context, const ::tensorflow::eager::EnqueueRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::EnqueueResponse>(channel_.get(), cq, rpcmethod_Enqueue_, context, request);
}

::grpc::ClientReaderWriter< ::tensorflow::eager::EnqueueRequest, ::tensorflow::eager::EnqueueResponse>* EagerService::Stub::StreamingEnqueueRaw(::grpc::ClientContext* context) {
  return new ::grpc::ClientReaderWriter< ::tensorflow::eager::EnqueueRequest, ::tensorflow::eager::EnqueueResponse>(channel_.get(), rpcmethod_StreamingEnqueue_, context);
}

::grpc::ClientAsyncReaderWriter< ::tensorflow::eager::EnqueueRequest, ::tensorflow::eager::EnqueueResponse>* EagerService::Stub::AsyncStreamingEnqueueRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return new ::grpc::ClientAsyncReaderWriter< ::tensorflow::eager::EnqueueRequest, ::tensorflow::eager::EnqueueResponse>(channel_.get(), cq, rpcmethod_StreamingEnqueue_, context, tag);
}

::grpc::Status EagerService::Stub::WaitQueueDone(::grpc::ClientContext* context, const ::tensorflow::eager::WaitQueueDoneRequest& request, ::tensorflow::eager::WaitQueueDoneResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_WaitQueueDone_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::WaitQueueDoneResponse>* EagerService::Stub::AsyncWaitQueueDoneRaw(::grpc::ClientContext* context, const ::tensorflow::eager::WaitQueueDoneRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::WaitQueueDoneResponse>(channel_.get(), cq, rpcmethod_WaitQueueDone_, context, request);
}

::grpc::Status EagerService::Stub::RunComponentFunction(::grpc::ClientContext* context, const ::tensorflow::eager::RunComponentFunctionRequest& request, ::tensorflow::eager::RunComponentFunctionResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_RunComponentFunction_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::RunComponentFunctionResponse>* EagerService::Stub::AsyncRunComponentFunctionRaw(::grpc::ClientContext* context, const ::tensorflow::eager::RunComponentFunctionRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::RunComponentFunctionResponse>(channel_.get(), cq, rpcmethod_RunComponentFunction_, context, request);
}

::grpc::Status EagerService::Stub::KeepAlive(::grpc::ClientContext* context, const ::tensorflow::eager::KeepAliveRequest& request, ::tensorflow::eager::KeepAliveResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_KeepAlive_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::KeepAliveResponse>* EagerService::Stub::AsyncKeepAliveRaw(::grpc::ClientContext* context, const ::tensorflow::eager::KeepAliveRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::KeepAliveResponse>(channel_.get(), cq, rpcmethod_KeepAlive_, context, request);
}

::grpc::Status EagerService::Stub::CloseContext(::grpc::ClientContext* context, const ::tensorflow::eager::CloseContextRequest& request, ::tensorflow::eager::CloseContextResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_CloseContext_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tensorflow::eager::CloseContextResponse>* EagerService::Stub::AsyncCloseContextRaw(::grpc::ClientContext* context, const ::tensorflow::eager::CloseContextRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tensorflow::eager::CloseContextResponse>(channel_.get(), cq, rpcmethod_CloseContext_, context, request);
}

EagerService::Service::Service() {
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::CreateContextRequest, ::tensorflow::eager::CreateContextResponse>(
          std::mem_fn(&EagerService::Service::CreateContext), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::UpdateContextRequest, ::tensorflow::eager::UpdateContextResponse>(
          std::mem_fn(&EagerService::Service::UpdateContext), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::EnqueueRequest, ::tensorflow::eager::EnqueueResponse>(
          std::mem_fn(&EagerService::Service::Enqueue), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[3],
      ::grpc::RpcMethod::BIDI_STREAMING,
      new ::grpc::BidiStreamingHandler< EagerService::Service, ::tensorflow::eager::EnqueueRequest, ::tensorflow::eager::EnqueueResponse>(
          std::mem_fn(&EagerService::Service::StreamingEnqueue), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::WaitQueueDoneRequest, ::tensorflow::eager::WaitQueueDoneResponse>(
          std::mem_fn(&EagerService::Service::WaitQueueDone), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[5],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::RunComponentFunctionRequest, ::tensorflow::eager::RunComponentFunctionResponse>(
          std::mem_fn(&EagerService::Service::RunComponentFunction), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[6],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::KeepAliveRequest, ::tensorflow::eager::KeepAliveResponse>(
          std::mem_fn(&EagerService::Service::KeepAlive), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      EagerService_method_names[7],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< EagerService::Service, ::tensorflow::eager::CloseContextRequest, ::tensorflow::eager::CloseContextResponse>(
          std::mem_fn(&EagerService::Service::CloseContext), this)));
}

EagerService::Service::~Service() {
}

::grpc::Status EagerService::Service::CreateContext(::grpc::ServerContext* context, const ::tensorflow::eager::CreateContextRequest* request, ::tensorflow::eager::CreateContextResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::UpdateContext(::grpc::ServerContext* context, const ::tensorflow::eager::UpdateContextRequest* request, ::tensorflow::eager::UpdateContextResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::Enqueue(::grpc::ServerContext* context, const ::tensorflow::eager::EnqueueRequest* request, ::tensorflow::eager::EnqueueResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::StreamingEnqueue(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::tensorflow::eager::EnqueueResponse, ::tensorflow::eager::EnqueueRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::WaitQueueDone(::grpc::ServerContext* context, const ::tensorflow::eager::WaitQueueDoneRequest* request, ::tensorflow::eager::WaitQueueDoneResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::RunComponentFunction(::grpc::ServerContext* context, const ::tensorflow::eager::RunComponentFunctionRequest* request, ::tensorflow::eager::RunComponentFunctionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::KeepAlive(::grpc::ServerContext* context, const ::tensorflow::eager::KeepAliveRequest* request, ::tensorflow::eager::KeepAliveResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EagerService::Service::CloseContext(::grpc::ServerContext* context, const ::tensorflow::eager::CloseContextRequest* request, ::tensorflow::eager::CloseContextResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace tensorflow
}  // namespace eager

