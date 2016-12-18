add_executable(treap_width_test global_test.cpp)
target_link_libraries(treap_width_test trees_lib)

find_package(GTest REQUIRED)
if (${GTEST_FOUND})
    include_directories(${GTEST_PATHS})
    target_link_libraries(treap_width_test gtest gtest_main)
endif()