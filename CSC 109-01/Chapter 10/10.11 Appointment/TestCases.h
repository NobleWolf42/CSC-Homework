/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <fstream>

//Include your classes header file(s) below and uncomment.
#include "Time.h"
#include "Date.h"
#include "Daily.h"
#include "Monthly.h"
#include "Onetime.h"

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
        TS_ASSERT_EQUALS(test1c.seconds_from(test1a), 500);

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
        TS_ASSERT(!(test2a == test2b));

    }

    void testDaily() {
        std::ofstream outputFS;
        std::ifstream inputFS;
        string type;

        Time s(12, 46, 0);
        Time e(14, 46, 0);
        Daily test3a("Test3a", s, e);
        Daily test3b;
        Daily test3c;

        test3a.print();

        outputFS.open("appt.txt");
        test3a.save(outputFS);
        outputFS.close();

        TS_ASSERT_EQUALS(test3a.getStart().get_hours(), s.get_hours());
        TS_ASSERT_EQUALS(test3a.getEnd().get_hours(), e.get_hours());
        TS_ASSERT_EQUALS(test3a.getDescription(), "Test3a");
        TS_ASSERT(test3a.occurs_on(2015, 8, 5));
        TS_ASSERT_EQUALS(test3b.getDescription(), "");

        inputFS.open("appt.txt");
        inputFS >> type;
        test3c.load(inputFS);
        inputFS.close();

        TS_ASSERT_EQUALS(test3c.getStart().get_hours(), s.get_hours());
        TS_ASSERT_EQUALS(test3c.getEnd().get_hours(), e.get_hours());
        TS_ASSERT_EQUALS(test3c.getDescription(), "Test3a");
        TS_ASSERT_EQUALS(type, "Daily");

    }

    void testMonthly() {
        std::ofstream outputFS;
        std::ifstream inputFS;
        string type;

        Time s(12, 46, 0);
        Time e(14, 46, 0);
        Monthly test4a("Test4a", 5, s, e);
        Monthly test4b;
        Monthly test4c;

        test4a.print();

        outputFS.open("appt.txt");
        test4a.save(outputFS);
        outputFS.close();

        TS_ASSERT_EQUALS(test4a.getStart().get_hours(), s.get_hours());
        TS_ASSERT_EQUALS(test4a.getEnd().get_hours(), e.get_hours());
        TS_ASSERT_EQUALS(test4a.getDescription(), "Test4a");
        TS_ASSERT(test4a.occurs_on(2015, 8, 5));
        TS_ASSERT(!test4a.occurs_on(2015, 8, 2));
        TS_ASSERT_EQUALS(test4b.getDescription(), "");

        inputFS.open("appt.txt");
        inputFS >> type;
        test4c.load(inputFS);
        inputFS.close();

        TS_ASSERT_EQUALS(test4c.getStart().get_hours(), s.get_hours());
        TS_ASSERT_EQUALS(test4c.getEnd().get_hours(), e.get_hours());
        TS_ASSERT_EQUALS(test4c.getDescription(), "Test4a");
        TS_ASSERT_EQUALS(type, "Monthly");

    }

    void testOnetime() {
        std::ofstream outputFS;
        std::ifstream inputFS;
        string type;

        Time s(12, 46, 0);
        Time e(14, 46, 0);
        Date d(2015, 7, 11);
        Onetime test5a("Test5a", d, s, e);
        Onetime test5b;
        Onetime test5c;

        test5a.print();

        outputFS.open("appt.txt");
        test5a.save(outputFS);
        outputFS.close();

        TS_ASSERT_EQUALS(test5a.getStart().get_hours(), s.get_hours());
        TS_ASSERT_EQUALS(test5a.getEnd().get_hours(), e.get_hours());
        TS_ASSERT_EQUALS(test5a.getDescription(), "Test5a");
        TS_ASSERT(test5a.occurs_on(2015, 7, 11));
        TS_ASSERT(!test5a.occurs_on(2014, 7, 11));
        TS_ASSERT_EQUALS(test5b.getDescription(), "");

        inputFS.open("appt.txt");
        inputFS >> type;
        test5c.load(inputFS);
        inputFS.close();

        TS_ASSERT_EQUALS(test5c.getStart().get_hours(), s.get_hours());
        TS_ASSERT_EQUALS(test5c.getEnd().get_hours(), e.get_hours());
        TS_ASSERT_EQUALS(test5c.getDescription(), "Test5a");
        TS_ASSERT_EQUALS(type, "Onetime");

    }

};
#endif /* TESTCASES_H */
