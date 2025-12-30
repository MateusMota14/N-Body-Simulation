set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Força compatibilidade com deps antigas")

cmake_minimum_required(VERSION 3.24)
project(BouncyBall)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- BUSCANDO SFML 3 ---
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SFML)

file(GLOB SOURCES 
    "main.cpp"
    "dynamics/src/*.cpp"
)

add_executable(BouncyBall ${SOURCES})

target_include_directories(BouncyBall PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/dynamics/include"
)

target_link_libraries(BouncyBall PRIVATE SFML::Graphics)