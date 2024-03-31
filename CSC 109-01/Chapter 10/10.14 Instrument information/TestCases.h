/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "StringInstrument.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstruction() {

        StringInstrument test1;
        
        test1.SetName("Violin");
        test1.SetManufacturer("Whee");
        test1.SetYearBuilt(1994);
        test1.SetCost(5245);
        test1.SetNumOfStrings(4);
        test1.SetNumOfFrets(0);
        test1.SetIsBowed(true);
        test1.PrintInfo();

        TS_ASSERT_EQUALS(test1.GetName(), "Violin");
        TS_ASSERT_EQUALS(test1.GetManufacturer(), "Whee");
        TS_ASSERT_EQUALS(test1.GetYearBuilt(), 1994);
        TS_ASSERT_EQUALS(test1.GetCost(), 5245);
        TS_ASSERT_EQUALS(test1.GetNumOfStrings(), 4);
        TS_ASSERT_EQUALS(test1.GetNumOfFrets(), 0);
        TS_ASSERT_EQUALS(test1.GetIsBowed(), true);
        
    }

};
#endif /* TESTCASES_H */
