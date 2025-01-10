cmake_minimum_required(VERSION 3.0.0)
project(cMakeTutorial1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(cMakeTutorial1 main.cpp)

set_property(TARGET cMakeTutorial1 PROPERTY CXX_STANDARD 17)

#Needed for MacOS-M1-ARM
