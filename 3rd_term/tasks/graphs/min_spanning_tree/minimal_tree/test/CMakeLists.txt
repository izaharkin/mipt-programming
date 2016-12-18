add_executable(run_common_tests basic_check.cpp)
target_link_libraries(run_common_tests min_sp_tree_lib)

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(run_common_tests gtest gtest_main)
endif()
