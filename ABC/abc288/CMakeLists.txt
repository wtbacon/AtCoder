cmake_minimum_required(VERSION 3.13)

project(abc288)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
add_executable(abc288A A.cpp)
add_executable(abc288B B.cpp)
add_executable(abc288C C.cpp)
