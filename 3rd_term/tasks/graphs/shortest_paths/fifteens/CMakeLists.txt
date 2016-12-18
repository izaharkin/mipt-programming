cmake_minimum_required(VERSION 3.6)
project(Fifteens)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(run_fifteens ${SOURCE_FILES})

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(run_fifteens astar_lib)