add_executable(segment_tree_test global_test.cpp)
target_link_libraries(segment_tree_test segment_tree_lib)

find_package(GTest REQUIRED)
if (${GTEST_FOUND})
    include_directories(${GTEST_PATHS})
    target_link_libraries(segment_tree_test gtest gtest_main)
endif()