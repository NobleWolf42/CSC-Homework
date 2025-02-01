/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
#include<iostream>

//Include your classes header file(s) below and uncomment.
#include "Item.h"
#include "ShoppingBags.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testItem() {

        Item test1a("Item1", 10.0);
        
        std::cout << test1a << std::endl;

        TS_ASSERT_EQUALS(test1a.getName(), "Item1");
        TS_ASSERT_EQUALS(test1a.getPrice(), 10.0);
        
    }

    void testShoppingBags() {

        std::vector<Item> shoppingBag;
        std::vector<std::vector<Item>> allBags;

        std::vector<Item> possibleItems = {
            Item("Item1", 10.0),
            Item("Item2", 15.0),
            Item("Item3", 5.0),
            Item("Item4", 8.0)
        };


        ShoppingBags test2a(3);

        size_t a = 4;

        allBags = test2a.ShoppingBagCombinations(shoppingBag, possibleItems);

        test2a.to_string(allBags);

        TS_ASSERT_EQUALS(allBags.size(), a);
        
    }

};
#endif /* TESTCASES_H */
