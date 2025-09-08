cmake_minimum_required(VERSION 3.30.0)
project(SeaBattle_backend LANGUAGES C CXX)

message(STATUS "Configure backend")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} main.cpp)

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
# Создание переменных для сборки
# =========================================================

# Устновка путей
set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
set(GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/game)
set(NETWORK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/network)

# Заголовки и исходники utils
file(GLOB UTILS_HEADERS src/utils/*.hpp)
file(GLOB UTILS_SOURCES src/utils/*.cpp)

# Заголовки и исходники game
file(GLOB GAME_HEADERS src/game/*.hpp)
file(GLOB GAME_SOURCES src/game/*.cpp)

# Заголовки и исходники network
file(GLOB NETWORK_HEADERS src/network/*.hpp)
file(GLOB NETWORK_SOURCES src/network/*.cpp)

# =========================================================
# Создание библиотек
# =========================================================

# utils
add_library(utils STATIC ${UTILS_HEADERS} ${UTILS_SOURCES})

# game
add_library(game STATIC ${GAME_HEADERS} ${GAME_SOURCES})

# network
add_library(network STATIC ${NETWORK_HEADERS} ${NETWORK_SOURCES})

# =========================================================
# Подключение include-директорий
# =========================================================

target_include_directories(utils PUBLIC ${UTILS_DIR})
target_include_directories(game PUBLIC ${GAME_DIR} ${UTILS_DIR})
target_include_directories(network PUBLIC
    ${NETWORK_DIR}
    ${GAME_DIR}
    ${UTILS_DIR}
    ${Boost_INCLUDE_DIRS}
)

# =========================================================
# Линковка
# =========================================================

target_link_libraries(game PUBLIC utils)
target_link_libraries(network PUBLIC game utils Boost::asio Boost::beast)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        utils
        game
        network
        Boost::asio
        Boost::beast
)

# =========================================================
# Сообщения об успешной сборке
# =========================================================
message(STATUS "Backend configured successfully ^_^")
