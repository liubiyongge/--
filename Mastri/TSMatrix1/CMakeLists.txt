cmake_minimum_required(VERSION 3.8)
project(TSMatrix_Orthogonal_List_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "TSMatrix(Orthogonal List).h" header.h test.h)
add_executable(TSMatrix_Orthogonal_List_ ${SOURCE_FILES})