set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB KMPStrategy.cpp
        StringFunctions.cpp
        SubstringFinder.cpp
        SubstringSolver.cpp)

add_library(substring_lib SHARED ${SOURCE_LIB})