cmake_minimum_required(VERSION 3.6)
project(D_Different_subsrtings)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(D_Different_subsrtings ${SOURCE_FILES})
target_link_libraries(D_Different_subsrtings sufarr_lib)