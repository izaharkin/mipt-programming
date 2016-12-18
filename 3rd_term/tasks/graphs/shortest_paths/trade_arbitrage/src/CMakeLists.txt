set(CMAKE_CXX_STANDARD 14)

set(LIB_SRC Edge.cpp Graph.cpp TradeArbitrageSolver.cpp)

add_library(ford_bellman_lib ${LIB_SRC})