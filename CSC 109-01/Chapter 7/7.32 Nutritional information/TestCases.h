/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "FoodItem.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDefaultConstructor() {

        FoodItem test1;
        TS_ASSERT_EQUALS(test1.GetName(), "Water");
        TS_ASSERT_EQUALS(test1.GetFat(), 0);
        TS_ASSERT_EQUALS(test1.GetCarbs(), 0);
        TS_ASSERT_EQUALS(test1.GetProtein(), 0);
        TS_ASSERT_EQUALS(test1.GetCalories(1), 0);

    }

    void testNonDefaultConstructor() {

        FoodItem test2 = FoodItem("Test2", 6.0, 4.6, 98.2);
        TS_ASSERT_EQUALS(test2.GetName(), "Test2");
        TS_ASSERT_EQUALS(test2.GetFat(), 6.0);
        TS_ASSERT_EQUALS(test2.GetCarbs(), 4.6);
        TS_ASSERT_EQUALS(test2.GetProtein(), 98.2);
        TS_ASSERT_EQUALS(test2.GetCalories(5), 2326);

    }

    void testPrint() {

        FoodItem test3 = FoodItem("Test3", 5.0, 3.4, 50.7);
        TS_ASSERT_THROWS_NOTHING(test3.PrintInfo());

    }

};
#endif /* TESTCASES_H */
