add_executable(treap_height_test global_test.cpp)
target_link_libraries(treap_height_test trees_lib)

find_package(GTest REQUIRED)
if (${GTEST_FOUND})
    include_directories(${TEST_PATHS})
    target_link_libraries(treap_height_test gtest gtest_main)
endif()