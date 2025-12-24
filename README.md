# 3D Solar System Simulation

A basic OpenGL application for simulating the solar system in 3D.

## Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- CMake (version 3.10 or higher)
- OpenGL
- GLFW3
- GLEW

## Building on Windows

### Using vcpkg (Recommended)
```bash
# Install dependencies
vcpkg install glfw3 glew

# Build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

### Manual Installation
1. Download and install GLFW from https://www.glfw.org/
2. Download and install GLEW from http://glew.sourceforge.net/
3. Configure CMake with appropriate paths

## Building on Linux

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install libglfw3-dev libglew-dev

# Build
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./SolarSystem
```

## Controls

- **ESC**: Close the window

## Current Status

Basic OpenGL window with dark blue background. Ready for solar system implementation.
