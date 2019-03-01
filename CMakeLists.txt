cmake_minimum_required (VERSION 3.1)
project(venus_project VERSION 2.0)

set(CMAKE_CXX_FLAGS "-masm=intel")

add_executable(venus_example src/main.cpp)

