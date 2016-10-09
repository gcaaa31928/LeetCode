cmake_minimum_required(VERSION 3.5)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCE_FILES 82.cpp)
add_executable(leetcode ${SOURCE_FILES})