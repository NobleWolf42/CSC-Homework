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

    void testConstructor() { // test non default constructor

        Restaurant rest3("GG", 3);
        string name = rest3.GetName();
        TS_ASSERT_EQUALS(name, "GG");
        int rating = rest3.GetRating();
        TS_ASSERT_EQUALS(rating, 3);

    }

    void testDefaultConstructor() { // test default constructor

        Restaurant rest3;
        string name = rest3.GetName();
        TS_ASSERT_EQUALS(name, "");
        int rating = rest3.GetRating();
        TS_ASSERT_EQUALS(rating, 0);

    }

    void testSetName() { // test default constructor

        Restaurant rest3;
        rest3.SetName("Set");
        TS_ASSERT_EQUALS(rest3.GetName(), "Set");

    }

    void testSetRating() { // test default constructor

        Restaurant rest3;
        rest3.SetRating(5);
        TS_ASSERT_EQUALS(rest3.GetRating(), 5);

    }

    void testPrint() { // test default constructor

        Restaurant rest3;
        rest3.SetName("Test5");
        rest3.SetRating(5);
        TS_ASSERT_THROWS_NOTHING(rest3.Print())

    }

};
#endif /* NEWCXXTEST_H */
