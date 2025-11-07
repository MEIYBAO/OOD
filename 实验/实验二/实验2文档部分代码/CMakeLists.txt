cmake_minimum_required(VERSION 3.26)
project(2)

set(CMAKE_CXX_STANDARD 14)

include_directories(task1)
include_directories(task2)
include_directories(task3)
include_directories(task4)

add_executable(2
        task1/T.cpp
        task1/T.h
        task1/task1.cpp
        task2/Complex.cpp
        task2/Complex.h
        task2/task2.cpp
        task3/PlayerControl.cpp
        task3/PlayerControl.h
        task3/task3.cpp
        task4/task4.cpp)
