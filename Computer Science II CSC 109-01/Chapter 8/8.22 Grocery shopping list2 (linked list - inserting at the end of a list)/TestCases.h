/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "ItemNode.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void test2ConstructorsAndInsertAfterEnd() {

        ItemNode* head = new ItemNode();
        ItemNode* test1 = new ItemNode("Item1");
        ItemNode* test2 = new ItemNode("Item2");

        head->InsertAfter(test1);
        test1->InsertAtEnd(head, test2);

        TS_ASSERT_DIFFERS(head->GetNext(), nullptr);
        TS_ASSERT_DIFFERS(test1->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2->GetItem(), "Item2");
        TS_ASSERT_THROWS_NOTHING(test2->PrintNodeData());
        
    }



};
#endif /* TESTCASES_H */
