cmake_minimum_required(VERSION 3.8)
project(TSMatrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TSMatrix.h header.h test.h)
add_executable(TSMatrix ${SOURCE_FILES})