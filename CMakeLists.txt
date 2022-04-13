cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
    hello_test
    main.cpp
	mock_test.cpp
	basic_test.cpp
	advanced_test.cpp
)

target_link_libraries(
    hello_test
    gtest_main
	gmock_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
