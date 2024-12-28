cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(cMake VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)

# add the executable
add_executable(cMake main.cpp)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(cMake PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
