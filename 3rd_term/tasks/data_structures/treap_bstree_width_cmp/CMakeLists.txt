cmake_minimum_required(VERSION 3.6)
project(treap_bstree_width)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(run_solver ${SOURCE_FILES})
target_link_libraries(run_solver trees_lib)