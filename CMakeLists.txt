cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(cMake VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)

# add sub-directory to add MathFunctions to this project
add_subdirectory(MathFunctions)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")

# add the executable
add_executable(cMake main.cxx)

# Use target_link_libraries to link the library to our executable
target_link_libraries(cMake PUBLIC MathFunctions)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# Add MathFunctions to Tutorial's target_include_directories()
target_include_directories(cMake PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )
