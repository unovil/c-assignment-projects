cmake_minimum_required(VERSION 3.23)
project(VariadicFunctions C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(VariadicFunctions main.c
        headers/vmath.c headers/vmath.h headers/print.c headers/print.h)
