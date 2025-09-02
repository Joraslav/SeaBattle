cmake_minimum_required(VERSION 3.30.0)
project(SeaBattle VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "SeaBattle version ${PROJECT_VERSION}")
message(STATUS "C++ standard ${CMAKE_CXX_STANDARD}")



add_executable(SeaBattle main.cpp)

include(CTest)
enable_testing()

