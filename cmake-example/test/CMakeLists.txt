find_package(GTest CONFIG REQUIRED)


add_executable(test1 test.cpp)
target_link_libraries(test1 GTest::gtest GTest::gtest_main)
target_compile_features(test1 PRIVATE cxx_std_17)
add_test(test1 test-1)
