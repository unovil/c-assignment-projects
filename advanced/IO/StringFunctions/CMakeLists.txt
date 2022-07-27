cmake_minimum_required(VERSION 3.21)
project(StringFunctions C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(StringFunctions main.c)
