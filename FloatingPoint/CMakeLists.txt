cmake_minimum_required(VERSION 3.13)
project(FloatingPoint)

set(CMAKE_CXX_STANDARD 17)

add_library(FloatingPoint source/library.cpp source/headers/library.h source/Utils.cpp source/headers/Utils.h)
