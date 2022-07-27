cmake_minimum_required(VERSION 3.21)
project(FormattingFunctions C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(a main.c headers/essentials.c)
