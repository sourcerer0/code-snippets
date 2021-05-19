cmake_minimum_required(VERSION 3.0)
project(someTests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(testLibrary__v1_0 testLibrary.c)