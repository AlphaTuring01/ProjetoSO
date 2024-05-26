cmake_minimum_required(VERSION 3.0)

project(RoundRobin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.cpp)

add_executable(RoundRobin ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${SRC_FILES})
