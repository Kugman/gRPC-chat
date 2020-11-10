
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::UserData;
using helloworld::MsgStatus;
using helloworld::Greeter;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(Greeter::NewStub(channel)) {}
    std::string SayHello(const std::string& user, const std::string& dst, const std::string& txt) {
    
    HelloRequest request;
    request.set_name(user);
    request.set_dst(dst);
    request.set_text(txt);

    HelloReply reply;

    ClientContext context;

    Status status = stub_->SayHello(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed" + reply.message();
    }
   } 
    
  std::string Connect(const std::string& user) {
    
    UserData request;
    request.set_name(user);
    MsgStatus reply;
    ClientContext context;
    Status status = stub_->Connect(&context, request, &reply);

    if (status.ok()) {
      return reply.stats();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed" + reply.stats();
    }
  }
  
  
  std::string Bye(const std::string& user) {
    
    UserData request;
    request.set_name(user);
    MsgStatus reply;
    ClientContext context;
    Status status = stub_->Bye(&context, request, &reply);

    if (status.ok()) {
      return reply.stats();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed" + reply.stats();
    }
  }

  
  std::string GetMsgs(const std::string& user) {
    
    UserData request;
    request.set_name(user);
    HelloReply reply;
    ClientContext context;
    Status status = stub_->GetMsgs(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }  
  
  

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};



void print_menu(){
  std::cout << "For connect press 1" << std::endl;
  std::cout << "For send msg press 2" << std::endl;
  std::cout << "For Get Your msgs press 3" << std::endl;
  std::cout << "End press 9" <<std::endl;  
}



int main(int argc, char** argv) {
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target=" << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
    target_str = "localhost:50051";
  }
  GreeterClient greeter(grpc::CreateChannel(
      target_str, grpc::InsecureChannelCredentials()));
  std::string user;
  std::string dest, text, reply;
  
  print_menu();
  
  
  int choice;
  int chr;
  std::cin >> choice;
  while (choice != 9){
  	switch(choice){
  	  case 1: std::cout << "Please Enter Your User Name: ";
  	  	  std::cin >> user;
		  reply = greeter.Connect(user);
		  std::cout << reply << std::endl;
		  break;
		  
  	  case 2: std::cout << "Please Enter User Name For Send: ";
  		  std::cin >> dest;
  		  std::cout << "Please Enter User Message (to finish enter #): ";  		  
  		  chr = getchar();
  		  while(chr != '#'){
  		    text += chr;
  		    chr = getchar();
  		  }  		  
  		  reply = greeter.SayHello(user, dest, text);
  		  std::cout << "status: " << reply << std::endl;
  		  break;
  	  case 3: reply = greeter.GetMsgs(user);
		  std::cout << reply << std::endl;
  		  break;
  	  default : std::cout << "please enter a valid number!" << std::endl;
  	  	  break;
  	}
  	std::cout << "Enter your choice again: ";
  	std::cin >> choice;
  
  
  }
  //getMsg->detach();
  greeter.Bye(user);
  //std::string reply = greeter.SayHello(user);
  //std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
