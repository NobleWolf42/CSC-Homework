/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
#include<iostream>

//Include your classes header file(s) below and uncomment.
#include "WhitePineTree.h"
#include "RedOakTree.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstruction() {

        OakTree test1a("Oak", "Oakwood Park", 10.5);
        PineTree test1b("Pine", "Pinecrest Forest", 75);
        WhitePineTree test1c("White Pine", "Northern Forest", 50);
        RedOakTree test1d("Red Oak", "Deciduous Forest", 20);
        
        test1c.dislayInfo();

        TS_ASSERT_EQUALS(test1a.estimateAge(), 12.6);
        TS_ASSERT_EQUALS(test1b.estimateAge(), 75);
        TS_ASSERT_EQUALS(test1c.estimateAge(), 60);
        TS_ASSERT_EQUALS(test1d.estimateAge(), 30);
        
    }

};
#endif /* TESTCASES_H */
