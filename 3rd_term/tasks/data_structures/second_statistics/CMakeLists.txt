cmake_minimum_required(VERSION 3.6)
project(F_Second_Staticstics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(F_Second_Staticstics ${SOURCE_FILES})

target_link_libraries(F_Second_Staticstics segment_tree_lib)
target_link_libraries(F_Second_Staticstics gtest)