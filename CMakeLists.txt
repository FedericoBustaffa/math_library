cmake_minimum_required(VERSION 3.20)

project(linear_algebra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE HEADERS "include/*.hpp")
file(GLOB_RECURSE SOURCES "main.cpp" "src/vector/*.cpp" "src/matrix/*.cpp")

add_executable(test ${HEADERS} ${SOURCES})
target_include_directories(test PRIVATE "include/")
