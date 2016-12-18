set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB EdgeList.cpp
        Graph.cpp
        IMaxFlowFinderStrategy.cpp
        PushRelableStrategy.cpp
        RelableToFrontStrategy.cpp
        MaxFlowFinder.cpp
        MaxFlowSolver.cpp)

add_library(max_flow_lib SHARED ${SOURCE_LIB})