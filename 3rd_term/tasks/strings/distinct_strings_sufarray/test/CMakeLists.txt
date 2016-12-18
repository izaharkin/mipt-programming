add_executable(distinct_substrings_test global_test.cpp)
target_link_libraries(distinct_substrings_test sufarr_lib)

find_package(GTest REQUIRED)
if (${GTEST_FOUND})
    include_directories(${GTEST_PATHS})
    target_link_libraries(distinct_substrings_test gtest gtest_main)
endif()