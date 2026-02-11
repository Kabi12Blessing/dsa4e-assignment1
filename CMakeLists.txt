cmake_minimum_required(VERSION 3.10)
project(assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug build
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE sources
    "src/*.cpp"
    "src/*/*.cpp"
)

add_executable(assignment1 ${sources})

# Placx executable in bin
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
