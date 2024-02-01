/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "Triangle.h"
#include <string>
using std::string;

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstructor() {

        Triangle test;
        test.SetBase(10);
        test.SetHeight(10);
        test.PrintInfo();
        TS_ASSERT_EQUALS(test.GetArea(), 50);

    }

};
#endif /* TESTCASES_H */
