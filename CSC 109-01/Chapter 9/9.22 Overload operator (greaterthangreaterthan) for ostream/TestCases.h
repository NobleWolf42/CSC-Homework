/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Number.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDefaultConstructor() {

        PhoneList test1a;
        PhoneNode test1b;

        TS_ASSERT_EQUALS(test1a.getHead(), nullptr);
        TS_ASSERT_EQUALS(test1a.getTail(), nullptr);
        TS_ASSERT_EQUALS(test1b.getNextNodePtr(), nullptr);
        
    }

    void testNonDefaultConstructor() {

        PhoneNode* test2a = new PhoneNode("Whee", "Hello", "HeHe");
        PhoneNode test2b("Whee", "Hello", "HeHe", test2a);
        TS_ASSERT_EQUALS(test2a->getNextNodePtr(), nullptr);
        TS_ASSERT_DIFFERS(test2b.getNextNodePtr(), nullptr);
        
    }

    void testInsertSort() {

        PhoneList* test3a = new PhoneList();
        PhoneNode* test3b = new PhoneNode("555-555-5555", "Ben", "Carpenter");
        PhoneNode* test3c = new PhoneNode("444-444-4444", "Ben", "Carpenter");
        PhoneNode* test3d = new PhoneNode("666-666-6666", "Ben", "Carpenter");
        PhoneNode* test3e = new PhoneNode("555-666-6666", "Ben", "Carpenter");
        test3a->insertSort(test3b);
        test3a->insertSort(test3c);
        test3a->insertSort(test3d);
        test3a->insertSort(test3e);
        TS_ASSERT_THROWS_NOTHING(test3a->printList());
        delete test3a;
        
    }

    void testsetNextNodePtr() {

        PhoneNode* test4a = new PhoneNode("555-555-5555", "Ben", "Carpenter");
        PhoneNode* test4b = new PhoneNode("444-444-4444", "Ben", "Carpenter");
        test4a->setNextNodePtr(test4b);
        TS_ASSERT_EQUALS(test4b->getNextNodePtr(), nullptr);
        TS_ASSERT_DIFFERS(test4a->getNextNodePtr(), nullptr);
        
    }

    void testEqualsOperator() {

        PhoneNode test4a("555-555-5555", "Ben", "Carpenter");
        PhoneNode test4b("555-555-5555", "Ben", "Carpenter");
        TS_ASSERT(test4a == test4b);
        
        
    }



};
#endif /* TESTCASES_H */
