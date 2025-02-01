/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Hash_Table_Chain.h"
#include "Person.h"
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

    void testPerson() {
        Person test3a("Hello", "Vote", "19", 2005);
        Person test3b("Hello", "Old", "70", 1954);
        Person test3c("Hello", "Drink", "22", 2002);
        Person test3d;
        Person test3e = test3a;

        hash<std::string> test3f;
        hash<Person> test3g;

        TS_ASSERT_EQUALS(test3a.get_given_name(), "Hello");
        TS_ASSERT_EQUALS(test3a.get_family_name(), "Vote");
        TS_ASSERT_EQUALS(test3a.get_birth_year(), 2005);
        TS_ASSERT_EQUALS(test3a.get_ID_number(), "19");
        TS_ASSERT_EQUALS(test3a.age(2024), 19);
        TS_ASSERT(test3a.can_vote(2024));
        TS_ASSERT(!test3a.can_drink(2024));
        TS_ASSERT(!test3a.is_senior(2024));

        TS_ASSERT_EQUALS(test3b.get_given_name(), "Hello");
        TS_ASSERT_EQUALS(test3b.get_family_name(), "Old");
        TS_ASSERT_EQUALS(test3b.get_birth_year(), 1954);
        TS_ASSERT_EQUALS(test3b.get_ID_number(), "70");
        TS_ASSERT_EQUALS(test3b.age(2024), 70);
        TS_ASSERT(test3b.can_vote(2024));
        TS_ASSERT(test3b.can_drink(2024));
        TS_ASSERT(test3b.is_senior(2024));

        TS_ASSERT_EQUALS(test3c.get_given_name(), "Hello");
        TS_ASSERT_EQUALS(test3c.get_family_name(), "Drink");
        TS_ASSERT_EQUALS(test3c.get_birth_year(), 2002);
        TS_ASSERT_EQUALS(test3c.get_ID_number(), "22");
        TS_ASSERT_EQUALS(test3c.age(2024), 22);
        TS_ASSERT(test3c.can_vote(2024));
        TS_ASSERT(test3c.can_drink(2024));
        TS_ASSERT(!test3c.is_senior(2024));

        test3d.set_given_name("Hello");
        test3d.set_family_name("Kid");
        test3d.set_birth_year(2010);

        TS_ASSERT_EQUALS(test3d.get_given_name(), "Hello");
        TS_ASSERT_EQUALS(test3d.get_family_name(), "Kid");
        TS_ASSERT_EQUALS(test3d.get_birth_year(), 2010);
        TS_ASSERT_EQUALS(test3d.get_ID_number(), "");
        TS_ASSERT_EQUALS(test3d.age(2024), 14);
        TS_ASSERT(!test3d.can_vote(2024));
        TS_ASSERT(!test3d.can_drink(2024));
        TS_ASSERT(!test3d.is_senior(2024));

        TS_ASSERT_EQUALS(test3f("Vote"), test3g(test3a));
        
        TS_ASSERT_EQUALS(test3a, test3e);
        TS_ASSERT(test3a != test3b);

        std::cout << test3a << std::endl;
    }

};
#endif /* TESTCASES_H */
