cmake_minimum_required(VERSION 3.26)
project(task1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task1
        T.cpp
        T.h
        task1.cpp)
