set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB BSTree.h
        Treap.h
        WidthSolver.cpp)

add_library(trees_lib SHARED ${SOURCE_LIB})