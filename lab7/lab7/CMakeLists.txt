cmake_minimum_required(VERSION 3.23)

set(project "lab7")
project(${project})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Persons)

add_executable(${project} main.cpp
        Persons/Person.cpp
        Persons/payCheck.cpp)

target_link_libraries(${project} Persons)

if(NOT WIN32)
  target_link_libraries(${project} m)
endif()