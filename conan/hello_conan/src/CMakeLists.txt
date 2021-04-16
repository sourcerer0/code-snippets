cmake_minimum_required(VERSION 3.1)
project(hello_world CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(hello_world hello_world.cpp)
