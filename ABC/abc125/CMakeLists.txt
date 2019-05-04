cmake_minimum_required(VERSION 3.13)

project(abc125)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
add_executable(abc125A A.cpp)
add_executable(abc125B B.cpp)
add_executable(abc125C C.cpp)
