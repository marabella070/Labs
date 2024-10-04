cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -Wall -Wextra -Werror")

set(SOURCES
    src/Time/Time.h
    src/Time/Time.cpp
    src/main.cpp)

add_executable(solution ${SOURCES})