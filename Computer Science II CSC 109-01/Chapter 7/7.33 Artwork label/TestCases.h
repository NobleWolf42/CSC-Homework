/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "Artwork.h"
#include "Artist.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDefaultConstructor() {

        Artwork test1;
        TS_ASSERT_EQUALS(test1.GetTitle(), "Unknown");
        TS_ASSERT_EQUALS(test1.GetYearCreated(), -1);
        
    }

    void testNonDefaultConstructor() {

        Artwork test2 = Artwork("Test3", 1900, Artist("Test3 Person", 1950, 2000));
        TS_ASSERT_EQUALS(test2.GetTitle(), "Test3");
        TS_ASSERT_EQUALS(test2.GetYearCreated(), 1900);

    }

    void testPrint1() {

        Artwork test3 = Artwork("Test3", 1920, Artist("Test3 Person", 1975, 2050));
        TS_ASSERT_THROWS_NOTHING(test3.PrintInfo());

    }

    void testPrint2() {

        Artwork test4 = Artwork("Test4", 1980, Artist("Test4 Person", 1950, -1));
        TS_ASSERT_THROWS_NOTHING(test4.PrintInfo());

    }

    void testPrint3() {

        Artwork test5 = Artwork("Test5", 1810, Artist("Test5 Person", -1, -1));
        TS_ASSERT_THROWS_NOTHING(test5.PrintInfo());

    }

    void testPrint4() {

        Artwork test6;
        TS_ASSERT_THROWS_NOTHING(test6.PrintInfo());

    }

};
#endif /* TESTCASES_H */
