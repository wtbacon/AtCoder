cmake_minimum_required(VERSION 3.13)

project(template)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
add_executable(template Template.cpp)
add_executable(dpTemplate DpTemplate.cpp)
add_executable(graphTemplate GraphTemplate.cpp)
