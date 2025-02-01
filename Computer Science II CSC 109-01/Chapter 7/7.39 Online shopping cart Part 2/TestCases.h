/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "ShoppingCart.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testITPDefaultConstructor() {

        ItemToPurchase test1;
        TS_ASSERT_EQUALS(test1.GetName(), "none");
        TS_ASSERT_EQUALS(test1.GetPrice(), 0);
        TS_ASSERT_EQUALS(test1.GetQuantity(), 0);
        
    }

    void testITPNonDefaultConstructor() {

        ItemToPurchase test2a("Test2a");
        TS_ASSERT_EQUALS(test2a.GetName(), "Test2a");
        TS_ASSERT_EQUALS(test2a.GetDescription(), "none");
        TS_ASSERT_EQUALS(test2a.GetPrice(), 0);
        TS_ASSERT_EQUALS(test2a.GetQuantity(), 0);

        ItemToPurchase test2b("Test2b", "Testing2b", 5, 6);
        TS_ASSERT_EQUALS(test2b.GetName(), "Test2b");
        TS_ASSERT_EQUALS(test2b.GetDescription(), "Testing2b");
        TS_ASSERT_EQUALS(test2b.GetPrice(), 5);
        TS_ASSERT_EQUALS(test2b.GetQuantity(), 6);
        
    }

    void testITPName() {

        ItemToPurchase test3;
        test3.SetName("Test3");
        TS_ASSERT_EQUALS(test3.GetName(), "Test3");

    }

    void testITPDescription() {

        ItemToPurchase test4;
        test4.SetDescription("Testing4");
        TS_ASSERT_EQUALS(test4.GetDescription(), "Testing4");

    }

    void testITPPrice() {

        ItemToPurchase test5;
        test5.SetPrice(5);
        TS_ASSERT_EQUALS(test5.GetPrice(), 5);

    }

    void testITPQuantity() {

        ItemToPurchase test6;
        test6.SetQuantity(15);
        TS_ASSERT_EQUALS(test6.GetQuantity(), 15);

    }

    void testITPPrint() {

        ItemToPurchase test7("Test7", "Testing7", 55, 16);
        TS_ASSERT_THROWS_NOTHING(test7.PrintItemCost());
        TS_ASSERT_THROWS_NOTHING(test7.PrintItemDescription());

    }

    void testSCDefaultConstructor() {

        ShoppingCart test8;
        TS_ASSERT_EQUALS(test8.GetCustomerName(), "none");
        TS_ASSERT_EQUALS(test8.GetDate(), "January 1, 2016");
        TS_ASSERT_THROWS_NOTHING(test8.PrintTotal());
        
    }

    void testSCNonDefaultConstructor() {

        ShoppingCart test9("Test9", "March 2015");
        TS_ASSERT_EQUALS(test9.GetCustomerName(), "Test9");
        TS_ASSERT_EQUALS(test9.GetDate(), "March 2015");
        
    }

    void testSCAddItemGetNumItems() {

        ItemToPurchase test10a("Test10a", "Testin10a", 6, 3);
        ShoppingCart test10b("Test10b", "May 2010");
        ItemToPurchase test10c("Test10c", "Testin10c", 3, 2);
        test10b.AddItem(test10a);
        test10b.AddItem(test10c);
        TS_ASSERT_EQUALS(test10b.GetNumItemsInCart(), 5);

    }

    void testSCRemoveItemGetCost() {

        ItemToPurchase test11a("Test11a", "Testin11a", 4, 5);
        ShoppingCart test11b("Test11b", "May 2013");
        test11b.RemoveItem("Test11a");
        TS_ASSERT_EQUALS(test11b.GetCostOfCart(), 0);

    }

    void testSCModifyItem() {

        ItemToPurchase test12a("Test12a", "Testin12a", 4, 5);
        ShoppingCart test12b("Test12b", "May 2013");
        ItemToPurchase test12c("Test12a", "Testin12a", 4, 3);
        test12b.AddItem(test12a);
        test12b.ModifyItem(test12c);
        TS_ASSERT_EQUALS(test12b.GetCostOfCart(), 12);

    }

    void testSCPrint() {

        ItemToPurchase test13a("Test13a", "Testin13a", 1, 9);
        ShoppingCart test13b("Test13b", "May 2012");
        TS_ASSERT_THROWS_NOTHING(test13b.PrintTotal());
        TS_ASSERT_THROWS_NOTHING(test13b.PrintDescriptions());

    }



};
#endif /* TESTCASES_H */
