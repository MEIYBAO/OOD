cmake_minimum_required(VERSION 3.26)
project(task3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task3
        PlayerControl.cpp
        PlayerControl.h)
