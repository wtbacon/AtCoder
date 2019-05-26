cmake_minimum_required(VERSION 3.13)

project(abc128)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
add_executable(abc128A A.cpp)
add_executable(abc128B B.cpp)
add_executable(abc128C C.cpp)
add_executable(abc128D D.cpp)
