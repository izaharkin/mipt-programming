set(CMAKE_CXX_STANDARD 14)

set(LIB_SRC DistinctStringSolver.cpp
        SuffixArray.cpp
        SuffixArrayStrategy.cpp
        SubstringsQuantitySolver.cpp
        utils.cpp)

add_library(sufarr_lib ${LIB_SRC})