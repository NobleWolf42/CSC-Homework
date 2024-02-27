/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "TwoDArray.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testSetAndGet() {
        double a;
        double* the_array = new double(a);
        double* row_vals = new double(a);

        row_vals[0] = 11;
        row_vals[1] = 2;
        row_vals[2] = 3;
        row_vals[3] = 4;
        row_vals[4] = 5;
        row_vals[5] = 6;
        row_vals[6] = 7;
        set_row(the_array, 0, 7, row_vals);
    
        row_vals[0] = 10;
        row_vals[1] = 9;
        row_vals[2] = 8;
        row_vals[3] = 7;
        row_vals[4] = 6;
        row_vals[5] = 5;
        row_vals[6] = 4;
        set_row(the_array, 1, 7, row_vals);
    
        row_vals[0] = 12;
        row_vals[1] = 11;
        row_vals[2] = 11;
        row_vals[3] = 11;
        row_vals[4] = 11;
        row_vals[5] = 31;
        row_vals[6] = 11;
        set_row(the_array, 2, 7, row_vals);
    
        row_vals[0] = 5;
        row_vals[1] = 5;
        row_vals[2] = 5;
        row_vals[3] = 5;
        row_vals[4] = 5;
        row_vals[5] = 5;
        row_vals[6] = 5;
        set_row(the_array, 3, 7, row_vals);
    
        row_vals[0] = 12;
        row_vals[1] = 3;
        row_vals[2] = 4;
        row_vals[3] = 9;
        row_vals[4] = 8;
        row_vals[5] = 7;
        row_vals[6] = 6;
        set_row(the_array, 4, 7, row_vals);

        row_vals[0] = 12;
        row_vals[1] = 3;
        row_vals[2] = 4;
        row_vals[3] = 9;
        row_vals[4] = 8;
        row_vals[5] = 7;
        row_vals[6] = 6;
        set_row(the_array, 5, 7, row_vals);

        TS_ASSERT_EQUALS(test1.getHouseNumber(), 0);
        TS_ASSERT_EQUALS(test1.getStreet(), "");
        TS_ASSERT_EQUALS(test1.getApartmentNumber(), 0);
        TS_ASSERT_EQUALS(test1.getCity(), "");
        TS_ASSERT_EQUALS(test1.getState(), "");
        TS_ASSERT_EQUALS(test1.getPostalCode(), "");

    }

    void testConstructor2() {

        Address test2(12, "Test2 ST", 34, "Not Today", "SN", "12345");
        TS_ASSERT_EQUALS(test2.getHouseNumber(), 12);
        TS_ASSERT_EQUALS(test2.getStreet(), "Test2 ST");
        TS_ASSERT_EQUALS(test2.getApartmentNumber(), 34);
        TS_ASSERT_EQUALS(test2.getCity(), "Not Today");
        TS_ASSERT_EQUALS(test2.getState(), "SN");
        TS_ASSERT_EQUALS(test2.getPostalCode(), "12345");

    }

    void testConstructor3() {

        Address test3(73, "Test3 AVE", "Still No", "LL", "55555");
        TS_ASSERT_EQUALS(test3.getHouseNumber(), 73);
        TS_ASSERT_EQUALS(test3.getStreet(), "Test3 AVE");
        TS_ASSERT_EQUALS(test3.getApartmentNumber(), 0);
        TS_ASSERT_EQUALS(test3.getCity(), "Still No");
        TS_ASSERT_EQUALS(test3.getState(), "LL");
        TS_ASSERT_EQUALS(test3.getPostalCode(), "55555");

    }

    void testSetFunctions() {

        Address test4;
        test4.setHouseNumber(55);
        test4.setStreet("Test4 RD");
        test4.setApartmentNumber(22);
        test4.setCity("Hehe");
        test4.setState("NA");
        test4.setPostalCode("00000");
        TS_ASSERT_EQUALS(test4.getHouseNumber(), 55);
        TS_ASSERT_EQUALS(test4.getStreet(), "Test4 RD");
        TS_ASSERT_EQUALS(test4.getApartmentNumber(), 22);
        TS_ASSERT_EQUALS(test4.getCity(), "Hehe");
        TS_ASSERT_EQUALS(test4.getState(), "NA");
        TS_ASSERT_EQUALS(test4.getPostalCode(), "00000");
        TS_ASSERT_THROWS_NOTHING(test4.print());

    }

    void testOverload() {

        Address test5a;
        Address test5b;
        test5a.setPostalCode("55555");
        test5b.setPostalCode("00000");
        TS_ASSERT(test5b < test5a);

    }

};
#endif /* TESTCASES_H */
