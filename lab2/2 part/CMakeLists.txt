cmake_minimum_required(VERSION 3.25)
project(2_part)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(apartments)
add_executable(2_part
        main.cpp apartments/library.cpp)
