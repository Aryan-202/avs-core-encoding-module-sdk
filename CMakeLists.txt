cmake_minimum_required(VERSION 3.20...3.30)

# Project Configuration
project(
    avs_core
    VERSION 0.1.0
    DESCRIPTION "AVS Core Media Encoding Module SDK"
    LANGUAGES C CXX
)

# Modern CMake
if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Out-of-source builds are required! Please create a build directory (e.g. 'mkdir build && cd build && cmake ..') and build from there.")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

add_library(project_warnings INTERFACE)
add_library(project_options INTERFACE)

if(MSVC)
    target_compile_options(project_warnings INTERFACE
        /W4          # Reasonable and high warning level
        /w14242      # 'identifier': conversion from 'type1' to 'type2', possible loss of data
        /w14254      # 'operator': conversion from 'type1:bitfield' to 'type2:bitfield', possible loss of data
        /w14263      # 'function': member function does not override any base class virtual member function
        /w14265      # 'class': class has virtual functions, but destructor is not virtual
        /w14287      # 'operator': unsigned/negative constant mismatch
        /we4289      # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the for-loop scope
        /w14296      # 'operator': expression is always false
        /w14311      # 'variable': pointer truncation from 'type1' to 'type2'
        /w14545      # expression before comma evaluates to a function which is missing an argument list
        /w14546      # function call before comma missing argument list
        /w14547      # 'operator': operator before comma has no effect; expected operator with side-effect
        /w14549      # 'operator': operator before comma has no effect; did you intend 'operator'?
        /w14555      # expression has no effect; expected expression with side-effect
        /w14619      # pragma warning: there is no warning number 'number'
        /w14640      # Enable warning on thread-unsafe static member initialization
        /w14826      # Conversion from 'type1' to 'type2' is sign-extended.
        /w14905      # wide string literal cast to 'LPSTR'
        /w14906      # string literal cast to 'LPWSTR'
        /w14928      # illegal copy-initialization; more than one user-defined conversion has been implicitly applied
        /permissive-  # Enforce standards conformance
    )
    target_compile_options(project_options INTERFACE
        /utf-8       # Set source and execution character sets to UTF-8
    )
else()
    target_compile_options(project_warnings INTERFACE
        -Wall
        -Wextra
        -Wshadow             # Warn when a variable shadows another one
        -Wnon-virtual-dtor   # Warn when a class has virtual functions but no virtual destructor
        -Wold-style-cast     # Warn for C-style casts
        -Wcast-align         # Warn for potential performance cast alignment issues
        -Wunused             # Warn on anything unused
        -Woverloaded-virtual  # Warn if a derived class function shadows a virtual function
        -Wpedantic           # Warn on non-standard C++
        -Wconversion         # Warn on conversions that might lose data
        -Wsign-conversion    # Warn on sign conversions
        -Wnull-dereference   # Warn on potential null pointer dereferences
        -Wdouble-promotion   # Warn if float is implicitly promoted to double
        -Wformat=2           # Warn on security issues around format functions
    )
endif()

# Target: Library (avs_core)
add_library(avs_core INTERFACE)

target_link_libraries(avs_core
    INTERFACE
        project_warnings
        project_options
)

target_include_directories(avs_core
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)