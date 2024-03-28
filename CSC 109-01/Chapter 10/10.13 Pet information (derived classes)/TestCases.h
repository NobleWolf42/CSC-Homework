/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Cat.h"
#include "Pet.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstruction() {

        Pet testPet1;
        Cat testCat1;

        testPet1;

        TS_ASSERT_EQUALS(test1.GetFirst(), "Test");
        TS_ASSERT_EQUALS(test1.GetLast(), "1");
        TS_ASSERT_EQUALS(test1.GetGPA(), 3.58);
        
    }

};
#endif /* TESTCASES_H */
