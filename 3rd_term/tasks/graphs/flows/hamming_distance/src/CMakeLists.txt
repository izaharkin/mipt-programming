cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB AdjList.cpp
        EdgeList.cpp
        DinicStrategy.cpp
        IStrategy.h
        Graph.cpp
        GraphBuilder.cpp
        MaxFlowFinder.cpp
        HammingSolver.cpp)

add_library(hamming_lib SHARED ${SOURCE_LIB})