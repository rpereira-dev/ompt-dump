# CMake Minimum version
cmake_minimum_required(VERSION 3.10)

# Project name
project(ompt_dump)

# Lib name
add_library(ompt_dump SHARED src/tool.c)

# Include directory
include_directories(include)

# Installation
INSTALL(TARGETS ompt_dump LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include FILES_MATCHING PATTERN "*.h*")

# Tests
include(CTest)
add_subdirectory(tests/)
enable_testing()
