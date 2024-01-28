cmake_minimum_required(VERSION 3.24)
project(CH07EXAMPLE1)

set(CMAKE_CXX_STANDARD 17)

set(CXXTEST_INCLUDE_DIR c:/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Restaurant.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h  # YOUR TEST DESCRIPTION FILE
            )

endif()


add_executable(CH07EXAMPLE1 runner.cpp
        Restaurant.cpp
        Restaurant.h newCxxTest.h)
