cmake_minimum_required(VERSION 3.16)

set(_VCPKG_INSTALLED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

project(how-to-build)

find_package(Threads)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

enable_testing()

add_subdirectory(proto)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(test)