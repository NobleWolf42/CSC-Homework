/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "LinkedListLibrary.h"
#include "BookNode.h"
#include "VectorLibrary.h"
#include "Book.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testLLLConstructor() {

        LinkedListLibrary test1;

        TS_ASSERT_EQUALS(test1.headNode, nullptr);
        TS_ASSERT_EQUALS(test1.lastNode, nullptr);
        
    }

    void testBNConstructor() {

        BookNode* test2a = new BookNode();
        BookNode* test2b = new BookNode("Test2b", "AT2b", 9787543321724);
        BookNode* test2c = new BookNode("Test2c", "AT2c", 9787543321856, test2b);

        TS_ASSERT_EQUALS(test2a->GetBookISBN(), 0);
        TS_ASSERT_EQUALS(test2a->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2b->GetBookISBN(), 9787543321724);
        TS_ASSERT_EQUALS(test2b->GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2c->GetBookISBN(), 9787543321856);
        TS_ASSERT_EQUALS(test2c->GetNext(), test2b);
        
    }

    void testVLConstructor() {

        VectorLibrary test3;
        test3.PrintLibrary();
        
    }

    void testBConstructor() {

        Book test4a;
        Book test4b("Test4a", "AT4a", 9787543321724);

        TS_ASSERT_EQUALS(test4a.GetBookISBN(), 0);
        TS_ASSERT_EQUALS(test4b.GetBookISBN(), 9787543321724);
    }

    void testLLLInsertSorted() {

        LinkedListLibrary* test5 = new LinkedListLibrary();

        BookNode* test5a = new BookNode("Test5a", "AT5a", 9787543321721);
        BookNode* test5c = new BookNode("Test5c", "AT5c", 9787543321720);
        BookNode* test5e = new BookNode("Test5e", "AT5e", 9787543321725);

        TS_ASSERT_EQUALS(test5->InsertSorted(test5a, 0), 1);
        TS_ASSERT_EQUALS(test5->InsertSorted(new BookNode("Test5b", "AT5b", 9787543321722), 1), 2);
        TS_ASSERT_EQUALS(test5->InsertSorted(test5c, 2), 3);
        TS_ASSERT_EQUALS(test5->InsertSorted(new BookNode("Test5d", "AT5d", 9787543321724), 3), 4);
        TS_ASSERT_EQUALS(test5->InsertSorted(test5e, 4), 5);
        TS_ASSERT_EQUALS(test5->headNode, test5c);
        TS_ASSERT_EQUALS(test5->lastNode, test5e);

        test5->PrintLibrary();

        delete test5;
        
    }

    void testVLInsertSorted() {

        VectorLibrary test6;

        Book test6a("Test6a", "AT6a", 9787543321721);
        Book test6b("Test5b", "AT5b", 9787543321722);
        Book test6c("Test5c", "AT5c", 9787543321720);
        Book test6d("Test5d", "AT5d", 9787543321724);
        Book test6e("Test6e", "AT6e", 9787543321725);

        TS_ASSERT_EQUALS(test6.InsertSorted(test6a, 0), 1);
        TS_ASSERT_EQUALS(test6.InsertSorted(test6b, 1), 2);
        TS_ASSERT_EQUALS(test6.InsertSorted(test6c, 2), 5);
        TS_ASSERT_EQUALS(test6.InsertSorted(test6d, 3), 4);
        TS_ASSERT_EQUALS(test6.InsertSorted(test6e, 4), 5);

        test6.PrintLibrary();
        
    }



};

#endif /* TESTCASES_H */
