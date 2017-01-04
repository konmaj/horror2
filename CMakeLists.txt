cmake_minimum_required(VERSION 2.8)
project(horror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")

include_directories(./src)

set(SOURCE_FILES
        src/helper.cc
        src/helper.h)

add_executable(test1 ./tests/test1.cpp ${SOURCE_FILES})
