cmake_minimum_required(VERSION 3.26)
project(4_gbk)

set(CMAKE_CXX_STANDARD 14)

include_directories(1)

add_executable(task1 task1.cpp GradeCalc.cpp
        1/GradeCalc.cpp)

