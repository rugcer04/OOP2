cmake_minimum_required(VERSION 3.31)
project(Studentai)

include_directories(include)

add_subdirectory(external/googletest)

set(CMAKE_CXX_FLAGS "-O3")

file(GLOB SOURCES "src/*.cpp")
add_library(Studentai STATIC ${SOURCES})

file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests gtest gtest_main Studentai)

enable_testing()

add_test(NAME StudentaiTests COMMAND runTests)
