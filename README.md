# gRPC-chat


A simple chat based on gRPC framework.


Language: C++.

API: protocol buffer.


INSTRUCTIONS:


1. BUILD PROJECT:

   run the following commands in terminal:
   
     $ git clone https://github.com/Kugman/gRPC-chat.git
     
     $ cd gRPC-chat
     
     $ mkdir build
     
     $ cd build
     
     $ cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
     
     $ make
     
     
2. RUN SERVER:

   run the following command in terminal:
   
     $ src/chat_server
     
     
3. RUN CLIENT:

   run the following command in terminal:
   
     $ src/chat_client
