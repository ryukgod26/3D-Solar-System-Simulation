cmake_minimum_required(VERSION 3.14)
project(SolarSystemSimulation LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

include(FetchContent)
find_package(glfw3 QUIET)

if(NOT glfw3_FOUND AND NOT TARGET glfw)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.9
    )
    FetchContent_MakeAvailable(glfw)
endif()

add_executable(
    SolarSystem
    main.cpp
    Game.cpp
    Window.cpp
    ShaderProgram.cpp
    Camera.cpp
    Mesh.cpp
    Texture.cpp
    Planet.cpp
    Actor.cpp
    objload.cpp
    stb_image.cpp
    glad.c
)

target_include_directories(SolarSystem PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_compile_definitions(SolarSystem PRIVATE PROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")

target_link_libraries(
    SolarSystem
    PRIVATE
    OpenGL::GL
    glfw
)
