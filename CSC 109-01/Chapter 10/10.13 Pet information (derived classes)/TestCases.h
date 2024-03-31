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

        testPet1.SetName("TestPet1");
        testPet1.SetAge(8);

        testCat1.SetName("TestCat1");
        testCat1.SetAge(5);
        testCat1.SetBreed("KittyMeowMeow");

        TS_ASSERT_EQUALS(testPet1.GetName(), "TestPet1");
        TS_ASSERT_EQUALS(testPet1.GetAge(), 8);
        TS_ASSERT_EQUALS(testCat1.GetName(), "TestCat1");
        TS_ASSERT_EQUALS(testCat1.GetAge(), 5);
        TS_ASSERT_EQUALS(testCat1.GetBreed(), "KittyMeowMeow");
        testCat1.PrintInfo();
        
    }

};
#endif /* TESTCASES_H */
