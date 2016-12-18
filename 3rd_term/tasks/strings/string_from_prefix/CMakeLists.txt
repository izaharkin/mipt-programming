cmake_minimum_required(VERSION 3.6)
project(B1_From_Prefix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(B1_From_Prefix ${SOURCE_FILES})
target_link_libraries(B1_From_Prefix string_restoring_lib)