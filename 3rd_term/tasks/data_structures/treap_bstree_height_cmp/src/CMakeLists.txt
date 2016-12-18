set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB BSTree.h Treap.h HeightSolver.cpp)

add_library(trees_lib STATIC ${SOURCE_LIB})