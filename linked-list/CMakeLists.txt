cmake_minimum_required(VERSION 3.9)
project(leetproblems)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-fsanitize=address")

add_executable(exec main.cpp)
