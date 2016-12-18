cmake_minimum_required(VERSION 3.6)
project(trade_arbitrage)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
#add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(trade_arbitrage ${SOURCE_FILES})
target_link_libraries(trade_arbitrage ford_bellman_lib)