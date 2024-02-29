/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "InventoryNode.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstructorsAndInsertAtFront() {

        InventoryNode* head = new InventoryNode();
        InventoryNode* test1 = new InventoryNode("Item1", 100);
        InventoryNode* test2 = new InventoryNode("Item2", 200);
        InventoryNode* test3 = new InventoryNode("Item3", 500, test2);

        test3->InsertAtFront(head, test3);
        test1->InsertAtFront(head, test1);

        std::cout << "POINTERS:" << std::endl;
        std::cout << test1->GetNext() << std::endl;
        std::cout << test3->GetNext() << std::endl;



        TS_ASSERT_DIFFERS(head->GetNext(), nullptr);
        TS_ASSERT_DIFFERS(test1->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2->GetNext(), nullptr);
        TS_ASSERT_DIFFERS(test3->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2->GetItem(), "Item2");
        TS_ASSERT_EQUALS(test1->GetNumberOfItems(), 100);
        TS_ASSERT_THROWS_NOTHING(test2->PrintNodeData());
        
    }



};
#endif /* TESTCASES_H */
