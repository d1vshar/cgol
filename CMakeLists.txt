cmake_minimum_required(VERSION 3.16)
project(cgol C)

set(CMAKE_C_STANDARD 11)

add_executable(cgol main.c)
add_dependencies(cgol raylib)
