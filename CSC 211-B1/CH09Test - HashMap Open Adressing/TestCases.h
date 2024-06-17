/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Hash_Table_Open.h"
#include <string>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testHashTable() {
        KW::hash_map<std::string, std::string> test1a;

        test1a["hello"] = "world";
        test1a["lorium"] = "impsum";
        test1a["hal"] = "9000";

        std::pair<const std::string, std::string> test1b("glad", "OS");
        test1a.insert(test1b);

        TS_ASSERT_EQUALS(test1a["hello"], "world");
        TS_ASSERT_EQUALS(test1a["lorium"], "impsum");
        TS_ASSERT_EQUALS(test1a["hal"], "9000");
        TS_ASSERT_EQUALS(test1a["glad"], "OS");
    }

    void testRehash() {
        KW::hash_map<int, int> test2a;

        for (int i = 0; i < 61; i++) {
            test2a[i] = i;
        }

        std::pair<int, int> test2b(5000, 5000);
        test2a.insert(test2b);
        test2a.insert(test2b);

        for (int i = 0; i < 61; i++) {
            TS_ASSERT_EQUALS(test2a[i], i);
        }
        TS_ASSERT_EQUALS(test2a[5000], 5000);

        std::cout << test2a.to_string() << std::endl;
    }

};
#endif /* TESTCASES_H */
