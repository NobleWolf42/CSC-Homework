/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
#include<iostream>

//Include your classes header file(s) below and uncomment.
#include "UberEats.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testUberEats() {

        UberEats<std::string, std::string, std::string> test1("566eid", "Hello World", "Toyota", "Mexican");

        test1.addMiles(100.0);

        TS_ASSERT_EQUALS(test1.getEmployeeId(), "566eid");
        TS_ASSERT_EQUALS(test1.getEmployeeName(), "Hello World");
        TS_ASSERT_EQUALS(test1.getTotalMiles(), 100.0);
        TS_ASSERT_EQUALS(test1.getVehicleType(), "Toyota");

        test1.setVehicleType("Honda");

        TS_ASSERT_EQUALS(test1.getVehicleType(), "Honda");
        TS_ASSERT_EQUALS(test1.getFoodType(), "Mexican");
        
        test1.setFoodType("TestFood");

        TS_ASSERT_EQUALS(test1.getFoodType(), "TestFood");

        TS_ASSERT_THROWS_ANYTHING(test1.addMiles(-50.0));
        
    }

};
#endif /* TESTCASES_H */
