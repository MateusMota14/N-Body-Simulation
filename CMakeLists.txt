set(CMAKE_POLICY_DEFAULT_CMP0000 NEW)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

cmake_minimum_required(VERSION 3.24...3.31)
project(BouncyBall)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # Para você ver o progresso se algo baixar

# 1. SFML 3.0
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)

# 2. Dear ImGui Core
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.5
)

# 3. imgui-sfml Wrapper v3.0
FetchContent_Declare(
    imgui-sfml
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
    GIT_TAG v3.0
)

# --- POPULATE ---
FetchContent_MakeAvailable(SFML imgui)

# Avisa ao wrapper onde o core está
set(IMGUI_DIR ${imgui_SOURCE_DIR} CACHE PATH "Path to imgui core")
set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "" FORCE)
set(IMGUI_SFML_IMGUI_DEMO ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(imgui-sfml)

# --- FONTES ---
file(GLOB SOURCES 
    "main.cpp"
    "dynamics/src/*.cpp"
)

add_executable(BouncyBall ${SOURCES})

target_include_directories(BouncyBall PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/dynamics/include"
)

# REMOVIDO: target_compile_definitions(BouncyBall PRIVATE IMGUI_USER_CONFIG=...)
# O imgui-sfml v3.0 já faz isso internamente agora!

target_link_libraries(BouncyBall PRIVATE 
    SFML::Graphics 
    ImGui-SFML::ImGui-SFML
)