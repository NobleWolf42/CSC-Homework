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
        size_t testSize = 3;

        test1a["hello"] = "world";
        test1a["lorium"] = "impsum";
        test1a["hal"] = "9000";

        std::pair<const std::string, std::string> test1b("glad", "OS");
        test1a.insert(test1b);

        TS_ASSERT_EQUALS(test1a["hello"], "world");
        TS_ASSERT_EQUALS(test1a["lorium"], "impsum");
        TS_ASSERT_EQUALS(test1a["hal"], "9000");
        TS_ASSERT_EQUALS(test1a["glad"], "OS");

        test1a.erase("glad");

        TS_ASSERT_EQUALS(test1a.find("glad"), test1a.end());
        TS_ASSERT_EQUALS(test1a.find("hello"), test1a.begin());
        TS_ASSERT_EQUALS(test1a.size(), testSize);
        TS_ASSERT_EQUALS(test1a.empty(), false);

        KW::hash_map<std::string, std::string>::iterator temp1 = test1a.begin();
        temp1++;

        KW::hash_map<std::string, std::string>::const_iterator temp2 = test1a.begin();

        KW::hash_map<std::string, std::string>::const_iterator temp3 = test1a.begin();

        TS_ASSERT_EQUALS(test1a.find("lorium"), temp1);

        TS_ASSERT_EQUALS(temp3, temp2);

        temp2++;
        temp3++;
        
        TS_ASSERT_EQUALS(temp3, temp2);

        temp2++;
        temp3++;
        
        TS_ASSERT_EQUALS(temp3, temp2);

        temp2++;
        temp3++;
        
        TS_ASSERT_EQUALS(temp3, temp2);
    }

    void testRehash() {
        KW::hash_map<int, int> test2a;

        for (int i = 0; i < 105; i++) {
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

    void testConstit() {
        KW::hash_map<std::string, std::string> test3a;
        size_t testSize = 3;

        test3a["hello"] = "world";
        test3a["lorium"] = "impsum";
        test3a["hal"] = "9000";

        KW::hash_map<std::string, std::string>::iterator temp1 = test3a.begin();
        KW::hash_map<std::string, std::string>::const_iterator temp2 = test3a.begin();
        KW::hash_map<std::string, std::string>::const_iterator temp3 = test3a.begin();

        temp1++;

        TS_ASSERT_EQUALS(test3a.find("lorium"), temp1);
        TS_ASSERT_EQUALS(temp3, temp2);

        temp2++;
        temp3++;
        
        TS_ASSERT_EQUALS(temp3, temp2);

        temp2++;
        temp3++;
        
        TS_ASSERT_EQUALS(temp3, temp2);

        temp2++;
        temp3++;
        
        TS_ASSERT_EQUALS(temp3, temp2);
    }

};
#endif /* TESTCASES_H */
