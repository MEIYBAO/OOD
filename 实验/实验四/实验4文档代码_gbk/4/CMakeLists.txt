cmake_minimum_required(VERSION 3.26)
project(4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(4
        demo4.cpp
        toy.cpp
        toy.hpp)
