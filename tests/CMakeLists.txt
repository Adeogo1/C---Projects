cmake_minimum_required(VERSION 3.22)
project(tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(tests main.cpp FriendFunctionTest.cpp FriendFunctionTest.h)
