/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "Restaurant.h"
#include <string>
using std::string;

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testModelYear() {

        Car test1;
        test1.SetModelYear(2000);
        test1.SetPurchasePrice(50000);
        TS_ASSERT_EQUALS(test1.GetModelYear(), 2000);

    }

    void testPurchasePrice() { // test non default constructor

        Car test2;
        test2.SetModelYear(2000);
        test2.SetPurchasePrice(50000);
        TS_ASSERT_EQUALS(test2.GetPurchasePrice(), 50000);

    }

    void testPrint() { // test default constructor

        Restaurant rest3;
        rest3.SetName("Test5");
        rest3.SetRating(5);
        TS_ASSERT_THROWS_NOTHING(rest3.Print())

    }

};
#endif /* NEWCXXTEST_H */
