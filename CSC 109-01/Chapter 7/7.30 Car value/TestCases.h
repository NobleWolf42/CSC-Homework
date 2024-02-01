/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "Car.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testModelYear() {

        Car test1;
        test1.SetModelYear(2000);
        test1.SetPurchasePrice(42000);
        TS_ASSERT_EQUALS(test1.GetModelYear(), 2000);

    }

    void testPurchasePrice() {

        Car test2;
        test2.SetModelYear(2015);
        test2.SetPurchasePrice(23000);
        TS_ASSERT_EQUALS(test2.GetPurchasePrice(), 23000);

    }

    void testCurrentValue() {

        Car test3;
        test3.SetModelYear(2010);
        test3.SetPurchasePrice(50000);
        test3.CalcCurrentValue(2020);
        TS_ASSERT_EQUALS(test3.GetCurrentValue(), 9844);

    }

    void testPrint() {

        Car test4;
        test4.SetModelYear(2000);
        test4.SetPurchasePrice(50000);
        test4.CalcCurrentValue(2010);
        TS_ASSERT_THROWS_NOTHING(test4.PrintInfo());

    }

};
#endif /* TESTCASES_H */
