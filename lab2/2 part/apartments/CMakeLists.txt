cmake_minimum_required(VERSION 3.25)
project(apartments)

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES library.cpp)

set(${project}_HEADERS library.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(apartments ${${project}_SOURCE_LIST})
