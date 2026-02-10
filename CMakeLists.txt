cmake_minimum_required(VERSION 3.10)

project(assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect ALL cpp files, including subdirectories like src/ekabi/
file(GLOB_RECURSE SOURCES
    "src/**/*.cpp"
)

add_executable(assignment1 ${SOURCES})
