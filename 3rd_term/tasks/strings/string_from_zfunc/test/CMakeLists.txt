add_executable(string_restore_test global_test.cpp)
target_link_libraries(string_restore_test string_restore_lib)

enable_testing()

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(string_restore_test gtest gtest_main)
endif()