# CMake Minimum version
cmake_minimum_required(VERSION 3.10)

project(omp LANGUAGES CXX)

add_executable(omp src/omp.c)
target_link_libraries(omp taskgrind_omp)
add_test(NAME omp COMMAND omp)
