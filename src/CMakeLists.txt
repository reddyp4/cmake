cmake_minimum_required(VERSION 3.0.0)
project(cMakeTutorial1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(main main.cpp)
target_link_libraries(main tutorial02)

#mset_property(TARGET cMakeTutorial1 PROPERTY CXX_STANDARD 17)

