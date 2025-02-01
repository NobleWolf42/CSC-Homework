/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Number.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstructor() {

        Number test1 = Number(5);
        TS_ASSERT_EQUALS(test1.GetNum(), 5);
        
    }

    void testSetNum() {

        Number test2 = Number(5);

        test2.SetNum(10);

        TS_ASSERT_EQUALS(test2.GetNum(), 10);
        
    }

    void testOverloaded() {

        Number test3 = Number(5);
        std::cout << test3;
        
    }



};
#endif /* TESTCASES_H */
