cmake_minimum_required(VERSION 3.20)
project(FirstPractice)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS --coverage)

add_executable(
        my_main
        main.cpp
        src/solution.h
        src/solution.cpp
        src/regex.h
        src/regex.cpp
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        my_test
        tests/test_1.cpp
        src/solution.h
        src/solution.cpp
        src/regex.h
        src/regex.cpp
)

target_link_libraries(
        my_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_test)

