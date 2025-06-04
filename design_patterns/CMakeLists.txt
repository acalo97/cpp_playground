cmake_minimum_required(VERSION 3.10)
project(design_patterns VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_executable(design_patterns
    behavioral/chain_of_responsibility/base_handler.cpp
    main.cpp
)

target_include_directories(design_patterns PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/behavioral/chain_of_responsibility)

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
file(GLOB TEST_SOURCES "behavioral/chain_of_responsibility/test/*.cpp")

add_executable(chain_of_responsibility_test ${TEST_SOURCES})
target_link_libraries(chain_of_responsibility_test gtest gtest_main pthread)

add_test(NAME ChainOfResponsibilityTest COMMAND chain_of_responsibility_test)
