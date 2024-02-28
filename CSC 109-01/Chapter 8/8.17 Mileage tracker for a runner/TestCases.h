/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "MileageTrackerNode.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void test3ConstructorsAndInsertAfter() {

        MileageTrackerNode* head = new MileageTrackerNode();
        MileageTrackerNode* test1 = new MileageTrackerNode(3.6, "5/3/17");
        MileageTrackerNode* test2 = new MileageTrackerNode(7.2, "1/10/03");

        head->InsertAfter(test1);
        test1->InsertAfter(test2);

        TS_ASSERT_DIFFERS(head->GetNext(), nullptr);
        TS_ASSERT_DIFFERS(test1->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2->GetDate(), "1/10/03");
        TS_ASSERT_EQUALS(test1->GetMiles(), 3.6);
        TS_ASSERT_THROWS_NOTHING(test2->PrintNodeData());
        delete head;
        
    }



};
#endif /* TESTCASES_H */
