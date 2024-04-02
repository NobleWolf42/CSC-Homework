/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
#include<iostream>

//Include your classes header file(s) below and uncomment.
#include "Time.h"
#include "Date.h"
#include "Daily.h"
//#include "Monthly.h"
//#include "Onetime.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testTime() {

        Time test1a(12, 46, 17);
        Time test1b;
        Time test1c(12, 37, 57);

        TS_ASSERT_EQUALS(test1a.get_hours(), 12);
        TS_ASSERT_EQUALS(test1a.get_minutes(), 46);
        TS_ASSERT_EQUALS(test1a.get_seconds(), 17);
        TS_ASSERT_EQUALS(test1a.seconds_from(test1c), 500);

        test1c.add_seconds(500);

        TS_ASSERT_EQUALS(test1a.seconds_from(test1c), 0);

    }

    void testDate() {

        Date test2a(2015, 11, 20);
        Date test2b;
        Date test2c(2015, 11, 20);

        TS_ASSERT_EQUALS(test2a.get_year(), 2015);
        TS_ASSERT_EQUALS(test2a.get_month(), 11);
        TS_ASSERT_EQUALS(test2a.get_day(), 20);
        TS_ASSERT(test2a == test2c);

    }

    void testDaily() {

        Time s(12, 46, 0);
        Time e(14, 46, 0);
        Daily test3("Test3", s, e);

        test3.print();

    }

};
#endif /* TESTCASES_H */
