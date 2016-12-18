set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB AdjList.cpp Matrix.h WeightedVertex.cpp Edge.cpp
        EdgeList.cpp Graph.cpp DSU.cpp ISpanningTreeFinderBehavior.cpp
        KruskalStrategy.cpp PrimStrategy.cpp SpanningTreeFinder.cpp MinimalTreeSolver.cpp)

add_library(min_sp_tree_lib STATIC ${SOURCE_LIB})