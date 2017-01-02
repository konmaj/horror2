cmake_minimum_required(VERSION 3.5.1)
project(horror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")

include_directories(./src)
set(SOURCE_FILES ./src/citizen.cc ./src/monster.cc ./src/smalltown.cc)

add_executable(test1 ${SOURCE_FILES} ./tests/test1.cpp)
