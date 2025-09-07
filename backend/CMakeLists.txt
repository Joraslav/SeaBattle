cmake_minimum_required(VERSION 3.30.0)
project(SeaBattle_backend LANGUAGES C CXX)

message(STATUS "Configure backend")

if(NOT CMAKE_CXX_STANDARD EQUAL 20)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# =========================================================
# Поиск библиотек
# =========================================================

# Поиск Boost
find_package(Boost REQUIRED COMPONENTS asio beast)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found! ^x^")
else()
    message(STATUS "Boost found! ^_^ Version: ${Boost_VERSION}")
endif()

# =========================================================
# Подключение утилит
# =========================================================
file(GLOB_RECURSE UTILS src/utils/*.hpp src/utils/*.cpp)
add_library(SeaBattle_utils STATIC ${UTILS})
target_include_directories(SeaBattle_utils PUBLIC src/utils)
