cmake_minimum_required(VERSION 3.23)

set(project "Persons")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES Person.cpp)

set(${project}_HEADERS Person.h)

set(${project}_SOURCE_LIST ${${project}_SOURCES} ${${project}_HEADERS})

add_library(${project} STATIC ${${project}_SOURCE_LIST} "wayBill.h" "wayBill.cpp" "payCheck.h" "payCheck.cpp" "receipt.h" "receipt.cpp")
