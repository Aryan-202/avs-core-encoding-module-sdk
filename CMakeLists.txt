cmake_minimum_required(VERSION 3.15)
project(avs VERSION 1.0.0 LANGUAGE C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

target_include_directories(include)

add_executable(avs
    src/main.c
)