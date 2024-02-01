cmake_minimum_required(VERSION 3.24)
project(CSC-Homework)

set(CMAKE_CXX_STANDARD 17)

set(CXXTEST_INCLUDE_DIR c:/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    #[[CXXTEST_ADD_TEST(unittest runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Templates/cxxtest/Restaurant.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/Templates/cxxtest/newCxxTest.h  # YOUR TEST DESCRIPTION FILE
            )]]

    #[[CXXTEST_ADD_TEST(7-29test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/Triangle.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-30test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/Car.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/TestCases.h
            )]]
    CXXTEST_ADD_TEST(7-31test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/Team.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/TestCases.h
            )

endif()

#[[add_executable(CH07EXAMPLE1 runner.cpp
        Templates/cxxtest/Restaurant.cpp
        Templates/cxxtest/Restaurant.h Templates/cxxtest/newCxxTest.h)]]

#[[add_executable(CH07-29 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/Triangle.cpp
        CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/Triangle.h CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/TestCases.h)]]

#[[add_executable(CH07-30 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/Car.cpp
        CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/Car.h CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/TestCases.h)]]

add_executable(CH07-31 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/Team.cpp
        CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/Team.h CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/TestCases.h)
