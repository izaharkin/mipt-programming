cmake_minimum_required(VERSION 3.6)
project(E_MaxFlow)

set(CMAKE_CXX_STANDARD 14)

# Ускоряем компиляцию через ccache, если он есть
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
    set(GLOBAL_CMAKE_CCACHE_RULES -DCMAKE_C_COMPILER=/usr/lib/ccache/cc -DCMAKE_CXX_COMPILER=/usr/lib/ccache/c++)
    set(GLOBAL_CCACHE_ENV -DCMAKE_C_COMPILER=/usr/lib/ccache/cc -DCMAKE_CXX_COMPILER=/usr/lib/ccache/c++)
endif(CCACHE_PROGRAM)

# Подключаем наши решения
add_subdirectory(src)
add_subdirectory(test)

add_executable(run_solver main.cpp)
target_link_libraries(run_solver max_flow_lib)