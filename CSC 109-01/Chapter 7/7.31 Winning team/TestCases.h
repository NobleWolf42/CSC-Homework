/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "Team.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testName() {

        Team test1;
        test1.SetName("Test1");
        test1.SetWins(42000);
        test1.SetLosses(42000);
        TS_ASSERT_EQUALS(test1.GetName(), "Test1");

    }

    void testWins() {

        Team test2;
        test2.SetName("Test2");
        test2.SetWins(7);
        test2.SetLosses(3);
        TS_ASSERT_EQUALS(test2.GetWins(), 7);

    }

    void testLosses() {

        Team test3;
        test3.SetName("Test3");
        test3.SetWins(1);
        test3.SetLosses(2);
        TS_ASSERT_EQUALS(test3.GetLosses(), 2);

    }

    void testWinPercentage() {

        Team test4;
        test4.SetName("Test4");
        test4.SetWins(10);
        test4.SetLosses(10);
        TS_ASSERT_EQUALS(test4.GetWinPercentage(), 0.5);

    }

    void testPrint1() {

        Team test5;
        test5.SetName("Test5");
        test5.SetWins(5);
        test5.SetLosses(1);
        TS_ASSERT_THROWS_NOTHING(test5.PrintStanding());

    }

    void testPrint2() {

        Team test6;
        test6.SetName("Test6");
        test6.SetWins(1);
        test6.SetLosses(5);
        TS_ASSERT_THROWS_NOTHING(test6.PrintStanding());

    }

};
#endif /* TESTCASES_H */
