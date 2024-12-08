cmake_minimum_required(VERSION 3.20)

project(linear_algebra)

file(GLOB_RECURSE HEADERS "include/*.hpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(test ${HEADERS} ${SOURCES})
target_include_directories(test PRIVATE "include/")