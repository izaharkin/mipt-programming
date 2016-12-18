set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB StringFunctions.cpp
        StringTransformer.cpp
        StringRestoringSolver.cpp)

add_library(string_restoring_lib SHARED ${SOURCE_LIB})