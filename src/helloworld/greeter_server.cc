
#include <iostream>
#include <memory>
#include <string>

#include <map>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::UserData;
using helloworld::MsgStatus;
using helloworld::Greeter;
//using namespace std;

static std::map<std::string, std::string> messages_map;


// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
  
  
  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    std::map<std::string, std::string>::iterator it = messages_map.find(request->dst());
    if(it != messages_map.end()){
    	it->second += "From " + request->name() + ": " + request->text() + "\n";
    	reply->set_message("sent!");
    }else{
    	reply->set_message("USER NOT FOUND!!");
    }	
    return Status::OK;
  }
  
  Status Connect(ServerContext* context, const UserData* request,
                  MsgStatus* reply) override {
    std::string prefix;
    std::map<std::string, std::string>::iterator it = messages_map.find(request->name());
    if(it != messages_map.end()){
    	prefix = "This User Name Exists already: ";
    	reply->set_stats(prefix + request->name());
    	return Status::CANCELLED;
    } else {
    	messages_map[request->name()] = "";
    	prefix = "Hello ";
    }
    reply->set_stats(prefix + request->name());
    return Status::OK;
  }
  
  Status Bye(ServerContext* context, const UserData* request,
                  MsgStatus* reply) override {
                  https://github.com/Kugman/gRPC-chat.git
    std::map<std::string, std::string>::iterator it = messages_map.find(request->name());
    if(it != messages_map.end())
    	messages_map.erase (it);
    std::string prefix("Bye ");
    reply->set_stats(prefix + request->name());
    return Status::OK;
  }
  
  
    Status GetMsgs(ServerContext* context, const UserData* request,
                  HelloReply* reply) override {
                  
    std::map<std::string, std::string>::iterator it = messages_map.find(request->name());
    if(it != messages_map.end()){
        std::string msgs(it->second);
    	reply->set_message(msgs);
	messages_map[it->first] = "";
    }else{
    	reply->set_message("you are not connected!");
    	return Status::CANCELLED;
    }
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;


  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
