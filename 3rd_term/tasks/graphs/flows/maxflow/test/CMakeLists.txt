add_executable(max_flow_tests max_flow_test.cpp)
target_link_libraries(max_flow_tests max_flow_lib)

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(max_flow_tests gtest gtest_main)
endif()