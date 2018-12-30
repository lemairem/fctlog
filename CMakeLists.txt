cmake_minimum_required(VERSION 3.1)
project(fctlog)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAG "-g -Wall")
include_directories(src/include)

add_subdirectory(demo)
add_subdirectory(test)
