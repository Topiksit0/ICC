# cmake_minimum_required(VERSION <specify CMake version here>)
project(ICC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ICC
        prac1.c
        prac2.c
        pracFuns.c
        pracFuns.h prac3.c)
