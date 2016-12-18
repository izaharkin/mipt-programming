cmake_minimum_required(VERSION 3.6)
project(A_Substring)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(run_solver ${SOURCE_FILES})

target_link_libraries(run_solver substring_lib)