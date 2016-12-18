set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB StringFunctions.cpp
        StringConverter.cpp
        StringRestoreSolver.cpp)

add_library(string_restore_lib SHARED ${SOURCE_LIB})