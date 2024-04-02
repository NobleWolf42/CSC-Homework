/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
#include<iostream>

//Include your classes header file(s) below and uncomment.
#include "Flower.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstruction() {

        Flower test1;
        
        test1.SetPlantName("Test1");
        test1.SetPlantCost(9);
        test1.SetPlantType(true);
        test1.SetColorOfFlowers("red");

        test1.Plant::PrintInfo();
        test1.PrintInfo();

        TS_ASSERT_EQUALS(test1.GetPlantName(), "Test1");
        TS_ASSERT_EQUALS(test1.GetPlantCost(), 9);
        TS_ASSERT(test1.GetPlantType());
        TS_ASSERT_EQUALS(test1.GetColorOfFlowers(), "red");
        
    }

};
#endif /* TESTCASES_H */
