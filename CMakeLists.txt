cmake_minimum_required(VERSION 3.13)
INCLUDE( ExternalProject )
project(OiAKProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(OiAKProjekt main.cpp)
target_link_libraries(OiAKProjekt ${PROJECT_SOURCE_DIR}/FloatingPoint/cmake-build-debug/libFloatingPoint.a)

ENABLE_TESTING()
ADD_SUBDIRECTORY( test )