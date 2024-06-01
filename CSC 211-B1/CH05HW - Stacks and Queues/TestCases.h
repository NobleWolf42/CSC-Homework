/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "ProcessOrders.h"
#include<string>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void test1() {
        ProcessOrders po;
        double amount = po.process_order(2); // 2 in order pending

        TS_ASSERT_EQUALS(amount, 0);
        
        amount = po.process_shipment(5,5); // 3 in inventory

        TS_ASSERT_EQUALS(amount, 15);

        amount = po.process_shipment(2,10); // 5 in inventory

        TS_ASSERT_EQUALS(amount, 0);

        amount = po.process_shipment(2,7); // 7 in inventory

        TS_ASSERT_EQUALS(amount, 0);

        amount = po.process_shipment(1,15); // 8 in inventory

        TS_ASSERT_EQUALS(amount, 0);

        amount = po.process_order(10);// 2 in order pending

        TS_ASSERT_EQUALS(amount, 96);
    }

    void test2() {
        ProcessOrders po;
        double amount = po.process_order(2); // 2 in order pending

        TS_ASSERT_EQUALS(amount, 0);

        amount = po.process_order(10); // 12 in order pending

        TS_ASSERT_EQUALS(amount, 0);
        
        amount = po.process_shipment(5,5); // 7 in order pending

        TS_ASSERT_EQUALS(amount, 37.5);
    }

};
#endif /* TESTCASES_H */
