# Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
add_library(MathFunctions MathFunctions.cxx)

# Create a variable USE_MYMATH using option and set default to ON
option(USE_MYMATH "Use example provided math implementation" ON)
if (USE_MYMATH)
    # If USE_MYMATH is ON, use target_compile_definitions to pass
    # USE_MYMATH as a precompiled definition to our source files
    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

    # When USE_MYMATH is ON, add a library for SqrtLibrary with source mysqrt.cxx
    add_library(SqrtLibrary STATIC mysqrt.cxx)

    # TODO 13: When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()
