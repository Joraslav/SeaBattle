cmake_minimum_required(VERSION 3.30.0)
project(SeaBattle VERSION 0.1.0 LANGUAGES C CXX)

# Настройка компилятора
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wextra
    -pedantic
    -Wno-unused-parameter
)

message(STATUS "SeaBattle version ${PROJECT_VERSION}")
message(STATUS "C++ standard ${CMAKE_CXX_STANDARD}")

# Опции сборки
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_BACKEND "Build backend" ON)

# Включение сборки бекенда
if(BUILD_BACKEND)
    add_subdirectory(backend)
    message(STATUS "Build backend")
endif()

# Включение сборки тестов
if(BUILD_TESTS)
    add_subdirectory(tests)
    message(STATUS "Build tests")
endif()
