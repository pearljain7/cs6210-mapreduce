// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: masterworker.proto

#include "masterworker.pb.h"
#include "masterworker.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace masterworker {

static const char* MasterWorker_method_names[] = {
  "/masterworker.MasterWorker/mapReduce",
};

std::unique_ptr< MasterWorker::Stub> MasterWorker::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MasterWorker::Stub> stub(new MasterWorker::Stub(channel));
  return stub;
}

MasterWorker::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_mapReduce_(MasterWorker_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status MasterWorker::Stub::mapReduce(::grpc::ClientContext* context, const ::masterworker::MasterQuery& request, ::masterworker::WorkerReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::masterworker::MasterQuery, ::masterworker::WorkerReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_mapReduce_, context, request, response);
}

void MasterWorker::Stub::experimental_async::mapReduce(::grpc::ClientContext* context, const ::masterworker::MasterQuery* request, ::masterworker::WorkerReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::masterworker::MasterQuery, ::masterworker::WorkerReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_mapReduce_, context, request, response, std::move(f));
}

void MasterWorker::Stub::experimental_async::mapReduce(::grpc::ClientContext* context, const ::masterworker::MasterQuery* request, ::masterworker::WorkerReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_mapReduce_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::masterworker::WorkerReply>* MasterWorker::Stub::PrepareAsyncmapReduceRaw(::grpc::ClientContext* context, const ::masterworker::MasterQuery& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::masterworker::WorkerReply, ::masterworker::MasterQuery, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_mapReduce_, context, request);
}

::grpc::ClientAsyncResponseReader< ::masterworker::WorkerReply>* MasterWorker::Stub::AsyncmapReduceRaw(::grpc::ClientContext* context, const ::masterworker::MasterQuery& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncmapReduceRaw(context, request, cq);
  result->StartCall();
  return result;
}

MasterWorker::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MasterWorker_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MasterWorker::Service, ::masterworker::MasterQuery, ::masterworker::WorkerReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MasterWorker::Service* service,
             ::grpc::ServerContext* ctx,
             const ::masterworker::MasterQuery* req,
             ::masterworker::WorkerReply* resp) {
               return service->mapReduce(ctx, req, resp);
             }, this)));
}

MasterWorker::Service::~Service() {
}

::grpc::Status MasterWorker::Service::mapReduce(::grpc::ServerContext* context, const ::masterworker::MasterQuery* request, ::masterworker::WorkerReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace masterworker
