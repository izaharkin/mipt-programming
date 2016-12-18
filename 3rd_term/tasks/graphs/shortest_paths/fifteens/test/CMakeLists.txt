set(TEST_SRC basic_check.cpp)
add_executable(run_common_test ${TEST_SRC})

target_link_libraries(run_common_test astar_lib)

enable_testing()

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(run_common_test gtest gtest_main)
endif()