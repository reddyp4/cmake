cmake_minimum_required(VERSION 3.15)
# version 3.15 to use generator expression

# set the project name and version
project(cMake VERSION 1.0)

# specify the C++ standard - NOT NEEDED
# Modern C++
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create interface library
add_library(main_compiler_flags INTERFACE)
target_compile_features(main_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
# Apply above flags to our interface library
target_compile_options(main_compiler_flags INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)

# add sub-directory to add MathFunctions to this project
add_subdirectory(MathFunctions)
# The below line not needed, since at lower level, we added INTERFACE
# INTERFACE: Things that consumer require but producers doesnt
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")

# add the executable
add_executable(cMake main.cxx)

# Use target_link_libraries to link the library to our executable
target_link_libraries(cMake PUBLIC MathFunctions main_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# Add MathFunctions to Tutorial's target_include_directories()
target_include_directories(cMake PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
# not needed with INTERFACE   "${EXTRA_INCLUDES}"
