cmake_minimum_required(VERSION 3.20)

project(linear_algebra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

file(GLOB_RECURSE HEADERS "include/*.hpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(linalg ${HEADERS} ${SOURCES})
target_include_directories(linalg PRIVATE "include/")

add_executable(test ${HEADERS} "main.cpp")
target_include_directories(test PRIVATE "include/")
target_link_libraries(test PRIVATE linalg)
