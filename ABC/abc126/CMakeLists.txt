cmake_minimum_required(VERSION 3.13)

project(abc126)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
add_executable(abc126A A.cpp)
add_executable(abc126B B.cpp)
add_executable(abc126C C.cpp)
add_executable(abc126D D.cpp)
