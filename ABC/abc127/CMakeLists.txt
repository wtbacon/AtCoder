cmake_minimum_required(VERSION 3.13)

project(abc127)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
add_executable(abc127A A.cpp)
add_executable(abc127B B.cpp)
add_executable(abc127C C.cpp)
add_executable(abc127D D.cpp)
