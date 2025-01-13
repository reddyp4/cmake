# Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
add_library(MathFunctions MathFunctions.cxx)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we dont
target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                          )

# Create a variable USE_MYMATH using option and set default to ON
option(USE_MYMATH "Use example provided math implementation" ON)
if (USE_MYMATH)
    # If USE_MYMATH is ON, use target_compile_definitions to pass
    # USE_MYMATH as a precompiled definition to our source files
    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

    # When USE_MYMATH is ON, add a library for SqrtLibrary with source mysqrt.cxx
    add_library(SqrtLibrary STATIC mysqrt.cxx)

    # Link sqrtlibrary to main_compiler_flags
    target_link_libraries(SqrtLibrary PUBLIC main_compiler_flags)

    # When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# link MathFunctions to main_compiler_flags
target_link_libraries(MathFunctions PUBLIC main_compiler_flags)

# install libs for MathFunctions
set(installable_libs MathFunctions main_compiler_flags)
if(TARGET SqrtLibrary)
    list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
# install include headers
install(FILES MathFunctions.h DESTINATION include)
