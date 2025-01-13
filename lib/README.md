# cmake
cmake build system for cpp

Source: https://cmake.org/cmake/help/latest/guide/tutorial/index.html

Why CMake?
Can handle dependencies
Supports cross-platform development

Summary from notes:
Need following in VSCode
- CMakeTools extension

CMakeLists.txt: sets how to build/compile
cmake_minimum_required(): 
project()
add_executable()

.json:
Group settings together using .json
CMakePresets.json: multiple presets, add to continuous integration system, share configs between developers

Source: cmake.org

Step1: Building Basic Project
Minimum commands: 
cmake_minimum_required(): 
project()
add_executable()

Step: State CMake use CXX Standard 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

Adding version number
project(NAME VERSION 1.0)

Copy input file with specified CMake variables
configure_file(Config.h.in Config.h)

Where to look for include files?
target_include_directories(Main PUBLIC "${PROJECT_BINARY_DIR}")