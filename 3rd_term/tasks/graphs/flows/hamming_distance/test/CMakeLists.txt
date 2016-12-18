add_executable(hamming_test hamming_test.cpp)
target_link_libraries(hamming_test hamming_lib)

enable_testing()

find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_PATHS})
    target_link_libraries(hamming_test gtest gtest_main)
endif()