cmake_minimum_required(VERSION 3.27.6)

# Set a name and a version number for your project:
project(the-cpp-book VERSION 0.0.1 LANGUAGES CXX)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

# Enable sanitizers for debug builds
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Address Sanitizer (ASan)
    add_compile_options(-fsanitize=address)
    link_libraries(-fsanitize=address)
    
    # Undefined Behavior Sanitizer (UBSan)
    add_compile_options(-fsanitize=undefined)
    link_libraries(-fsanitize=undefined)
    
    # Thread Sanitizer (TSan)
    add_compile_options(-fsanitize=thread)
    link_libraries(-fsanitize=thread)
endif()

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# this needs to be in the top-level CMakeLists.txt to enable tests
include(CTest)

# compile the library
add_subdirectory(src)

# compile the tests
add_subdirectory(tests)

# compile the application
add_subdirectory(app)

# optionally add doxygen target to generate documentation
option(BUILD_DOCS "Enable building of documentation (requires Doxygen)" OFF)
if(BUILD_DOCS)
    find_package(Doxygen REQUIRED)
    set(DOXYGEN_EXCLUDE_PATTERNS "${CMAKE_SOURCE_DIR}/ext/*")
    doxygen_add_docs(doxygen
        ${CMAKE_SOURCE_DIR}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()

# Optionally enable DEBUG_LOG environment variable
option(DEBUG_LOG "Enable DEBUG_LOG environment variable" OFF)
if (DEBUG_LOG)
    add_compile_definitions(DEBUG_LOG)
endif()
