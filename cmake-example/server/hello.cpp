//
// Created by 张梵 on 2/17/21.
//
#include <iostream>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

int main() {
    int a = 0;
    int b = 3;
    int c = a + b;
    int d = c;
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    std::cout << "Hello" << std::endl;
    return 0;
}