add_executable(string_restoring_test global_test.cpp)
target_link_libraries(string_restoring_test string_restoring_lib)

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(string_restoring_test gtest gtest_main)
endif()