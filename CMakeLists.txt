cmake_minimum_required(VERSION 2.8)
project(horror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")

include_directories(./src)

set(SOURCE_FILES
        src/helper.cc
        src/helper.h
        src/citizen.cc
        src/citizen.h
        src/monster.cc
        src/monster.h
        src/smalltown.cc
        src/smalltown.h)

add_executable(example ./tests/example.cpp ${SOURCE_FILES})
add_executable(test1 ./tests/test1.cpp ${SOURCE_FILES})
