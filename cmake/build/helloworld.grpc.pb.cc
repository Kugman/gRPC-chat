// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: helloworld.proto

#include "helloworld.pb.h"
#include "helloworld.grpc.pb.h"

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
namespace helloworld {

static const char* Greeter_method_names[] = {
  "/helloworld.Greeter/SayHello",
  "/helloworld.Greeter/Connect",
  "/helloworld.Greeter/Bye",
  "/helloworld.Greeter/GetMsgs",
};

std::unique_ptr< Greeter::Stub> Greeter::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Greeter::Stub> stub(new Greeter::Stub(channel));
  return stub;
}

Greeter::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SayHello_(Greeter_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Connect_(Greeter_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Bye_(Greeter_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetMsgs_(Greeter_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Greeter::Stub::SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::helloworld::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

void Greeter::Stub::experimental_async::SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* Greeter::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* Greeter::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSayHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Greeter::Stub::Connect(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::helloworld::MsgStatus* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Connect_, context, request, response);
}

void Greeter::Stub::experimental_async::Connect(::grpc::ClientContext* context, const ::helloworld::UserData* request, ::helloworld::MsgStatus* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Connect_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::Connect(::grpc::ClientContext* context, const ::helloworld::UserData* request, ::helloworld::MsgStatus* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Connect_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::helloworld::MsgStatus>* Greeter::Stub::PrepareAsyncConnectRaw(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::MsgStatus>::Create(channel_.get(), cq, rpcmethod_Connect_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::helloworld::MsgStatus>* Greeter::Stub::AsyncConnectRaw(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncConnectRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Greeter::Stub::Bye(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::helloworld::MsgStatus* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Bye_, context, request, response);
}

void Greeter::Stub::experimental_async::Bye(::grpc::ClientContext* context, const ::helloworld::UserData* request, ::helloworld::MsgStatus* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Bye_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::Bye(::grpc::ClientContext* context, const ::helloworld::UserData* request, ::helloworld::MsgStatus* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Bye_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::helloworld::MsgStatus>* Greeter::Stub::PrepareAsyncByeRaw(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::MsgStatus>::Create(channel_.get(), cq, rpcmethod_Bye_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::helloworld::MsgStatus>* Greeter::Stub::AsyncByeRaw(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncByeRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Greeter::Stub::GetMsgs(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::helloworld::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetMsgs_, context, request, response);
}

void Greeter::Stub::experimental_async::GetMsgs(::grpc::ClientContext* context, const ::helloworld::UserData* request, ::helloworld::HelloReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetMsgs_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::GetMsgs(::grpc::ClientContext* context, const ::helloworld::UserData* request, ::helloworld::HelloReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetMsgs_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* Greeter::Stub::PrepareAsyncGetMsgsRaw(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::HelloReply>::Create(channel_.get(), cq, rpcmethod_GetMsgs_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* Greeter::Stub::AsyncGetMsgsRaw(::grpc::ClientContext* context, const ::helloworld::UserData& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetMsgsRaw(context, request, cq);
  result->StartCall();
  return result;
}

Greeter::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::HelloRequest, ::helloworld::HelloReply>(
          [](Greeter::Service* service,
             ::grpc::ServerContext* ctx,
             const ::helloworld::HelloRequest* req,
             ::helloworld::HelloReply* resp) {
               return service->SayHello(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::UserData, ::helloworld::MsgStatus>(
          [](Greeter::Service* service,
             ::grpc::ServerContext* ctx,
             const ::helloworld::UserData* req,
             ::helloworld::MsgStatus* resp) {
               return service->Connect(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::UserData, ::helloworld::MsgStatus>(
          [](Greeter::Service* service,
             ::grpc::ServerContext* ctx,
             const ::helloworld::UserData* req,
             ::helloworld::MsgStatus* resp) {
               return service->Bye(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::UserData, ::helloworld::HelloReply>(
          [](Greeter::Service* service,
             ::grpc::ServerContext* ctx,
             const ::helloworld::UserData* req,
             ::helloworld::HelloReply* resp) {
               return service->GetMsgs(ctx, req, resp);
             }, this)));
}

Greeter::Service::~Service() {
}

::grpc::Status Greeter::Service::SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::Connect(::grpc::ServerContext* context, const ::helloworld::UserData* request, ::helloworld::MsgStatus* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::Bye(::grpc::ServerContext* context, const ::helloworld::UserData* request, ::helloworld::MsgStatus* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::GetMsgs(::grpc::ServerContext* context, const ::helloworld::UserData* request, ::helloworld::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace helloworld

