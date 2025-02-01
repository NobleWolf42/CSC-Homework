/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "ItemToPurchase.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDefaultConstructor() {

        ItemToPurchase test1;
        TS_ASSERT_EQUALS(test1.GetName(), "none");
        TS_ASSERT_EQUALS(test1.GetPrice(), 0);
        TS_ASSERT_EQUALS(test1.GetQuantity(), 0);
        
    }

    void testName() {

        ItemToPurchase test2;
        test2.SetName("Test2");
        TS_ASSERT_EQUALS(test2.GetName(), "Test2");

    }

    void testPrice() {

        ItemToPurchase test3;
        test3.SetPrice(5);
        TS_ASSERT_EQUALS(test3.GetPrice(), 5);

    }

    void testQuantity() {

        ItemToPurchase test4;
        test4.SetQuantity(15);
        TS_ASSERT_EQUALS(test4.GetQuantity(), 15);

    }

};
#endif /* TESTCASES_H */
