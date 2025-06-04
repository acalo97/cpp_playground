cmake_minimum_required(VERSION 3.10)
project(HelloWorld VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_executable(hello_world
    main.cpp
    foo/foo.cpp
)

target_include_directories(hello_world PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/foo)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test source files
file(GLOB TEST_SOURCES "foo/test/*.cpp")

add_executable(foo_test ${TEST_SOURCES})
target_link_libraries(foo_test gtest gtest_main pthread)

add_test(NAME FooUnitTests COMMAND foo_test)
