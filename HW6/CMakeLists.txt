cmake_minimum_required(VERSION 3.20)

project(HW6 CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

if(CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(./MaxNumber)
add_subdirectory(./Sort)
add_subdirectory(./Inversion)
add_subdirectory(./ThreeSum)