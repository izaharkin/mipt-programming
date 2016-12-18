add_executable(substring_test global_test.cpp)

include_directories(src)
target_link_libraries(substring_test substring_lib)

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(substring_test gtest gtest_main)
endif()