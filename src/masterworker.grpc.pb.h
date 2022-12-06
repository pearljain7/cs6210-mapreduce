// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: masterworker.proto
#ifndef GRPC_masterworker_2eproto__INCLUDED
#define GRPC_masterworker_2eproto__INCLUDED

#include "masterworker.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace masterworker {

class WorkerService final {
 public:
  static constexpr char const* service_full_name() {
    return "masterworker.WorkerService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status RegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::masterworker::MapReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::MapReply>> AsyncRegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::MapReply>>(AsyncRegisterMapServiceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::MapReply>> PrepareAsyncRegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::MapReply>>(PrepareAsyncRegisterMapServiceRaw(context, request, cq));
    }
    virtual ::grpc::Status RegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::masterworker::ReduceReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::ReduceReply>> AsyncRegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::ReduceReply>>(AsyncRegisterReduceServiceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::ReduceReply>> PrepareAsyncRegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::ReduceReply>>(PrepareAsyncRegisterReduceServiceRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void RegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest* request, ::masterworker::MapReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void RegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest* request, ::masterworker::MapReply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void RegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest* request, ::masterworker::ReduceReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void RegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest* request, ::masterworker::ReduceReply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::MapReply>* AsyncRegisterMapServiceRaw(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::MapReply>* PrepareAsyncRegisterMapServiceRaw(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::ReduceReply>* AsyncRegisterReduceServiceRaw(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::masterworker::ReduceReply>* PrepareAsyncRegisterReduceServiceRaw(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status RegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::masterworker::MapReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::MapReply>> AsyncRegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::MapReply>>(AsyncRegisterMapServiceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::MapReply>> PrepareAsyncRegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::MapReply>>(PrepareAsyncRegisterMapServiceRaw(context, request, cq));
    }
    ::grpc::Status RegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::masterworker::ReduceReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::ReduceReply>> AsyncRegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::ReduceReply>>(AsyncRegisterReduceServiceRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::ReduceReply>> PrepareAsyncRegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::masterworker::ReduceReply>>(PrepareAsyncRegisterReduceServiceRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void RegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest* request, ::masterworker::MapReply* response, std::function<void(::grpc::Status)>) override;
      void RegisterMapService(::grpc::ClientContext* context, const ::masterworker::MapRequest* request, ::masterworker::MapReply* response, ::grpc::ClientUnaryReactor* reactor) override;
      void RegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest* request, ::masterworker::ReduceReply* response, std::function<void(::grpc::Status)>) override;
      void RegisterReduceService(::grpc::ClientContext* context, const ::masterworker::ReduceRequest* request, ::masterworker::ReduceReply* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::masterworker::MapReply>* AsyncRegisterMapServiceRaw(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::masterworker::MapReply>* PrepareAsyncRegisterMapServiceRaw(::grpc::ClientContext* context, const ::masterworker::MapRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::masterworker::ReduceReply>* AsyncRegisterReduceServiceRaw(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::masterworker::ReduceReply>* PrepareAsyncRegisterReduceServiceRaw(::grpc::ClientContext* context, const ::masterworker::ReduceRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_RegisterMapService_;
    const ::grpc::internal::RpcMethod rpcmethod_RegisterReduceService_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status RegisterMapService(::grpc::ServerContext* context, const ::masterworker::MapRequest* request, ::masterworker::MapReply* response);
    virtual ::grpc::Status RegisterReduceService(::grpc::ServerContext* context, const ::masterworker::ReduceRequest* request, ::masterworker::ReduceReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_RegisterMapService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_RegisterMapService() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_RegisterMapService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterMapService(::grpc::ServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegisterMapService(::grpc::ServerContext* context, ::masterworker::MapRequest* request, ::grpc::ServerAsyncResponseWriter< ::masterworker::MapReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_RegisterReduceService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_RegisterReduceService() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_RegisterReduceService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterReduceService(::grpc::ServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegisterReduceService(::grpc::ServerContext* context, ::masterworker::ReduceRequest* request, ::grpc::ServerAsyncResponseWriter< ::masterworker::ReduceReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_RegisterMapService<WithAsyncMethod_RegisterReduceService<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_RegisterMapService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_RegisterMapService() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::masterworker::MapRequest, ::masterworker::MapReply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::masterworker::MapRequest* request, ::masterworker::MapReply* response) { return this->RegisterMapService(context, request, response); }));}
    void SetMessageAllocatorFor_RegisterMapService(
        ::grpc::MessageAllocator< ::masterworker::MapRequest, ::masterworker::MapReply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::masterworker::MapRequest, ::masterworker::MapReply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_RegisterMapService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterMapService(::grpc::ServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* RegisterMapService(
      ::grpc::CallbackServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_RegisterReduceService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_RegisterReduceService() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::masterworker::ReduceRequest, ::masterworker::ReduceReply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::masterworker::ReduceRequest* request, ::masterworker::ReduceReply* response) { return this->RegisterReduceService(context, request, response); }));}
    void SetMessageAllocatorFor_RegisterReduceService(
        ::grpc::MessageAllocator< ::masterworker::ReduceRequest, ::masterworker::ReduceReply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::masterworker::ReduceRequest, ::masterworker::ReduceReply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_RegisterReduceService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterReduceService(::grpc::ServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* RegisterReduceService(
      ::grpc::CallbackServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_RegisterMapService<WithCallbackMethod_RegisterReduceService<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_RegisterMapService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_RegisterMapService() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_RegisterMapService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterMapService(::grpc::ServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_RegisterReduceService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_RegisterReduceService() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_RegisterReduceService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterReduceService(::grpc::ServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_RegisterMapService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_RegisterMapService() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_RegisterMapService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterMapService(::grpc::ServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegisterMapService(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_RegisterReduceService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_RegisterReduceService() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_RegisterReduceService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterReduceService(::grpc::ServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegisterReduceService(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_RegisterMapService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_RegisterMapService() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->RegisterMapService(context, request, response); }));
    }
    ~WithRawCallbackMethod_RegisterMapService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterMapService(::grpc::ServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* RegisterMapService(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_RegisterReduceService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_RegisterReduceService() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->RegisterReduceService(context, request, response); }));
    }
    ~WithRawCallbackMethod_RegisterReduceService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RegisterReduceService(::grpc::ServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* RegisterReduceService(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_RegisterMapService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_RegisterMapService() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::masterworker::MapRequest, ::masterworker::MapReply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::masterworker::MapRequest, ::masterworker::MapReply>* streamer) {
                       return this->StreamedRegisterMapService(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_RegisterMapService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status RegisterMapService(::grpc::ServerContext* /*context*/, const ::masterworker::MapRequest* /*request*/, ::masterworker::MapReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedRegisterMapService(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::masterworker::MapRequest,::masterworker::MapReply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_RegisterReduceService : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_RegisterReduceService() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::masterworker::ReduceRequest, ::masterworker::ReduceReply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::masterworker::ReduceRequest, ::masterworker::ReduceReply>* streamer) {
                       return this->StreamedRegisterReduceService(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_RegisterReduceService() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status RegisterReduceService(::grpc::ServerContext* /*context*/, const ::masterworker::ReduceRequest* /*request*/, ::masterworker::ReduceReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedRegisterReduceService(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::masterworker::ReduceRequest,::masterworker::ReduceReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_RegisterMapService<WithStreamedUnaryMethod_RegisterReduceService<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_RegisterMapService<WithStreamedUnaryMethod_RegisterReduceService<Service > > StreamedService;
};

}  // namespace masterworker


#endif  // GRPC_masterworker_2eproto__INCLUDED
