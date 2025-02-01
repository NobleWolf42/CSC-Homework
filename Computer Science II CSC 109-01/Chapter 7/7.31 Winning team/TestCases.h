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
        test1.SetTeamName("Test1");
        test1.SetTeamWins(42000);
        test1.SetTeamLosses(42000);
        TS_ASSERT_EQUALS(test1.GetTeamName(), "Test1");

    }

    void testWins() {

        Team test2;
        test2.SetTeamName("Test2");
        test2.SetTeamWins(7);
        test2.SetTeamLosses(3);
        TS_ASSERT_EQUALS(test2.GetTeamWins(), 7);

    }

    void testLosses() {

        Team test3;
        test3.SetTeamName("Test3");
        test3.SetTeamWins(1);
        test3.SetTeamLosses(2);
        TS_ASSERT_EQUALS(test3.GetTeamLosses(), 2);

    }

    void testWinPercentage() {

        Team test4;
        test4.SetTeamName("Test4");
        test4.SetTeamWins(10);
        test4.SetTeamLosses(10);
        TS_ASSERT_EQUALS(test4.GetWinPercentage(), 0.5);

    }

    void testPrint1() {

        Team test5;
        test5.SetTeamName("Test5");
        test5.SetTeamWins(5);
        test5.SetTeamLosses(1);
        TS_ASSERT_THROWS_NOTHING(test5.PrintStanding());

    }

    void testPrint2() {

        Team test6;
        test6.SetTeamName("Test6");
        test6.SetTeamWins(1);
        test6.SetTeamLosses(5);
        TS_ASSERT_THROWS_NOTHING(test6.PrintStanding());

    }

};
#endif /* TESTCASES_H */
