/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Course.h"
#include "Node.h"
#include "Single_Linked_List.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testCourse() {

        Course test1a("Who knows", 502.2, "Whee", 4, 25);
        Course test1b;
        Course test1c(test1a);
        Course test1d;
        Course test1e;

        test1e = test1a;

        std::cout << "1a: " << test1a << std::endl;
        
        test1b.SetCoursenum(502.2);
        test1b.SetSeats(25);
        test1b.SetSections(4);
        test1b.SetTerm("Whee");
        test1b.SetDept("Who knows");

        TS_ASSERT_EQUALS(test1a.GetCoursenum(), 502.2);
        TS_ASSERT_EQUALS(test1a.GetSeats(), 25);
        TS_ASSERT_EQUALS(test1a.GetSections(), 4);
        TS_ASSERT_EQUALS(test1a.GetTerm(), "Whee");
        TS_ASSERT_EQUALS(test1a.GetDept(), "Who knows");
        TS_ASSERT(test1b == test1c);
        TS_ASSERT(test1b == test1e);
        TS_ASSERT(!(test1b == test1d));
        TS_ASSERT(!(test1b != test1e));
        TS_ASSERT(test1b != test1d);
        TS_ASSERT(test1d < test1b);
        TS_ASSERT(test1b >= test1a);
        TS_ASSERT(!(test1d >= test1b));
        TS_ASSERT(!(test1b < test1a));
        
    }

    void testNode() {

        Node<string>* test2a = new Node<string>("Test2 A");
        Node<Course> test2b(Course("Who knows", 502.2, "Whee", 4, 25));
        Node<double> test2c(25.6);
        Node<int> test2d(5);
        Node<string> test2e("Test2 E", test2a);
        Node<string> test2f;
        Node<string>* test2g = new Node<string>("Test2 G");
        Node<string>* test2h = new Node<string>("Test2 H", test2g);

        test2f = test2e;
        
        test2c.SetData(502.2);
        test2f.SetNext(test2a);

        TS_ASSERT_EQUALS(test2a->GetData(), "Test2 A");
        TS_ASSERT_EQUALS(test2a->GetNext(), nullptr);
        TS_ASSERT_DIFFERS(test2e.GetNext(), nullptr);
        TS_ASSERT_EQUALS(test2b.GetData(), Course("Who knows", 502.2, "Whee", 4, 25));
        TS_ASSERT_EQUALS(test2c.GetData(), 502.2);
        TS_ASSERT_EQUALS(test2d.GetData(), 5);
        TS_ASSERT_EQUALS(test2e.GetData(), "Test2 E");
        TS_ASSERT_EQUALS(test2f.GetData(), "Test2 E");
        TS_ASSERT_EQUALS(test2g->GetData(), "Test2 G");
        TS_ASSERT_EQUALS(test2h->GetData(), "Test2 H");
    }

    void testLinkedList() {

        Single_Linked_List<int> test3a;
        Single_Linked_List<double> test3b;
        Single_Linked_List<string> test3c;
        Single_Linked_List<Course> test3d;

        int testint = 6;

        test3a.push_front(5);
        test3a.push_front(4);
        test3a.push_back(6);
        test3b.push_front(5.23);
        test3c.push_front("Test3C");
        test3d.push_front(Course("Who knows", 502.2, "Whee", 4, 25));

        TS_ASSERT_EQUALS(test3a.get(0), 4);
        TS_ASSERT_EQUALS(test3a.get(1), 5);
        TS_ASSERT_EQUALS(test3a.get(2), 6);
        TS_ASSERT_EQUALS(test3b.get(0), 5.23);
        TS_ASSERT_EQUALS(test3c.get(0), "Test3C");
        TS_ASSERT_EQUALS(test3d.get(0), Course("Who knows", 502.2, "Whee", 4, 25));

        test3a.pop_back();
        test3a.pop_front();
        TS_ASSERT_EQUALS(test3a.get(0), 5);
        TS_ASSERT_EQUALS(test3a.front(), 5);
        TS_ASSERT_EQUALS(test3a.back(), 5);
        TS_ASSERT(!(test3a.empty()));
        TS_ASSERT_EQUALS(test3a.size(), 1);
        TS_ASSERT_THROWS_ANYTHING(test3a.get(1));

        test3a.insert(1, 7);

        TS_ASSERT_EQUALS(test3a.get(1), 7);

        test3a.sortedInsert(testint);

        TS_ASSERT_EQUALS(test3a.get(0), 5);
        TS_ASSERT_EQUALS(test3a.get(1), 6);
        TS_ASSERT_EQUALS(test3a.get(2), 7);

        test3a.pop_back();
        test3a.pop_back();
        test3a.pop_back();

        TS_ASSERT(test3a.empty());
    }

    void testHead() {
        Single_Linked_List<int> test4a;

        test4a.push_back(5);
        TS_ASSERT_EQUALS(test4a.get(0), 5);
    }

    void testPopFront() {
        Single_Linked_List<int> test5a;
        TS_ASSERT_THROWS_ANYTHING(test5a.pop_front());
        TS_ASSERT_THROWS_ANYTHING(test5a.pop_back());
    }

    void testPopFront2() {
        Single_Linked_List<int> test6a;

        test6a.push_front(5);
        test6a.pop_front();

        TS_ASSERT(test6a.empty());
    }

    void testFront() {
        Single_Linked_List<int> test7a;

        TS_ASSERT_THROWS_ANYTHING(test7a.front());
    }

    void testBack() {
        Single_Linked_List<int> test8a;

        TS_ASSERT_THROWS_ANYTHING(test8a.back());
    }

    void testInsert() {
        Single_Linked_List<int> test9a;

        test9a.insert(0, 5);
        test9a.insert(1, 6);
        test9a.insert(2, 8);
        test9a.insert(2, 7);

        TS_ASSERT_EQUALS(test9a.get(0), 5);
        TS_ASSERT_EQUALS(test9a.get(1), 6);
        TS_ASSERT_EQUALS(test9a.get(2), 7);
        TS_ASSERT_EQUALS(test9a.get(3), 8);
    }

    void testSortedInsert() {
        int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6;
        Single_Linked_List<int> test10a;

        test10a.sortedInsert(num3);
        test10a.sortedInsert(num2);
        test10a.sortedInsert(num5);
        test10a.sortedInsert(num1);
        test10a.sortedInsert(num4);
        test10a.sortedInsert(num6);

        TS_ASSERT_EQUALS(test10a.get(0), 1);
        TS_ASSERT_EQUALS(test10a.get(1), 2);
        TS_ASSERT_EQUALS(test10a.get(2), 3);
        TS_ASSERT_EQUALS(test10a.get(3), 4);
        TS_ASSERT_EQUALS(test10a.get(4), 5);

        test10a.pop_back();
        test10a.pop_back();
        test10a.pop_back();
        test10a.pop_back();
        test10a.pop_back();

        test10a.sortedInsert(num2);

        TS_ASSERT_EQUALS(test10a.get(0), 1);
        TS_ASSERT_EQUALS(test10a.get(1), 2);
    }

};
#endif /* TESTCASES_H */
