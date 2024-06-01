/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "circular_list.h"
#include<string>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testCircular_list() {
        KW::circular_list<int> test1;
        KW::circular_list<int> test4;
        const char* names[] = {"Tom", "Dick", "Harry", "Sharon", "Sam"};
        KW::circular_list<std::string> test3(names, names+5);

        for (int i = 0; i < 10; i++) {
            test1.push_back(i);
        }

        for (int i = 10; i < 20; i++) {
            test4.push_front(i);
        }

        KW::circular_list<int> test2(test1);
        KW::circular_list<int> deleteMe(test1);

        TS_ASSERT_EQUALS(test1.size(), 10);
        TS_ASSERT_EQUALS(test2.size(), 10);
        TS_ASSERT_EQUALS(test1.front(), 0);
        TS_ASSERT_EQUALS(test2.front(), 0);
        TS_ASSERT_EQUALS(test1.back(), 9);
        TS_ASSERT_EQUALS(test2.back(), 9);
        TS_ASSERT_EQUALS(test3.front(), "Tom");
        TS_ASSERT_EQUALS(test3.back(), "Sam");
        TS_ASSERT_EQUALS(test4.front(), 19);
        
        test1.pop_back();
        test2.pop_back();
        test1.pop_front();
        test2.pop_front();

        TS_ASSERT_EQUALS(test1.front(), test2.front());

        test1.swap(test4);

        TS_ASSERT_EQUALS(test4.front(), test2.front());
        TS_ASSERT_DIFFERS(test1.front(), test2.front());

        KW::circular_list<int> test5;
        test5 = test1;
        
        TS_ASSERT_EQUALS(test1.back(), test5.back());

        test4.pop_back();
        test4.pop_back();
        test4.pop_back();
        test4.pop_back();
        test4.pop_back();
        test4.pop_back();
        test4.pop_back();
        test4.pop_back();

        test2.pop_front();
        test2.pop_front();
        test2.pop_front();
        test2.pop_front();
        test2.pop_front();
        test2.pop_front();
        test2.pop_front();
        test2.pop_front();

        TS_ASSERT_THROWS_ANYTHING(test4.pop_back());
        TS_ASSERT_THROWS_ANYTHING(test2.pop_front());

        test2.push_back(5);
        test2.insert(test2.end(), 4);
        test2.insert(test2.begin(), 2);
        test2.insert(test2.find(5), 1);

        TS_ASSERT_EQUALS(test2.back(), 4);
        TS_ASSERT_EQUALS(test2.front(), 2);

        test2.erase(test2.find(5));
        test2.erase(test2.find(1));
        test2.erase(test2.find(4));

        TS_ASSERT_EQUALS(test2.back(), 2);
        TS_ASSERT_EQUALS(test2.front(), 2);

        test2.erase(test2.begin());

        TS_ASSERT_THROWS_ANYTHING(test2.pop_front());
        TS_ASSERT_THROWS_ANYTHING(test2.erase(test2.end()));
        TS_ASSERT_THROWS_ANYTHING(test2.front());
        TS_ASSERT_THROWS_ANYTHING(test2.back());
        TS_ASSERT(test2.empty());
        TS_ASSERT_EQUALS(test2.find(5), test4.find(5));
        

    }

};
#endif /* TESTCASES_H */
