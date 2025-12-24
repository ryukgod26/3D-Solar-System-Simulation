cmake_minimum_required(VERSION 3.10)
project(SolarSystemSimulation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add executable
add_executable(SolarSystem main.cpp)

# Link libraries
target_link_libraries(SolarSystem 
    OpenGL::GL
    glfw
    GLEW::GLEW
)

# Include directories
target_include_directories(SolarSystem PRIVATE ${OPENGL_INCLUDE_DIR})
