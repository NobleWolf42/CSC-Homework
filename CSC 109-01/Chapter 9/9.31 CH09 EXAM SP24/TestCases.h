/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Student.h"
#include "Course.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstructor() {

        Student test1("Test", "1", 3.58);

        TS_ASSERT_EQUALS(test1.GetFirst(), "Test");
        TS_ASSERT_EQUALS(test1.GetLast(), "1");
        TS_ASSERT_EQUALS(test1.GetGPA(), 3.58);
        
    }

    void testEqualsOperator() {

        Student test2a("Test", "2", 3.58);
        Student test2b("Test", "2", 3.58);
        Student test2c("Test", "2c", 2.56);

        TS_ASSERT_EQUALS((test2a == test2b), true);
        TS_ASSERT_EQUALS((test2a == test2c), false);
        
    }

    void testGetRoster() {

        Student test3a("Test", "3a", 1.58);
        Student test3b("Test", "3b", 3.58);
        Student test3c("Test", "3c", 2.56);

        Course test3;
        test3.AddStudent(test3a);


        TS_ASSERT_EQUALS(test3.GetRoster().at(0).GetLast(), "3a");
        
    }

    void testLoadFile() {

        Course test4;
        test4.LoadFile("course1.txt");
        test4.Print();


        TS_ASSERT_EQUALS(test4.GetRoster().at(0).GetLast(), "Sandoval");
        
    }

    void testFindGPA() {

        Course test5;
        test5.LoadFile("course1.txt");

        TS_ASSERT_EQUALS(test5.FindStudentHighestGpa().GetLast(), "Clayton");
        
    }

    void testPassCourse() {

        Course test6;
        Course test6a;
        test6.LoadFile("course1.txt");
        test6.PassCourse("pass1.txt");
        test6a.LoadFile("pass1.txt");


        TS_ASSERT_EQUALS(test6a.GetRoster().at(1).GetLast(), "Miller");
        
    }

    void testRemoveStudent() {

        Student test7s("Marvin", "Sandoval", 70);
        Course test7;
        test7.LoadFile("course1.txt");
        test7.RemoveStudent(test7s);

        std::cout << test7 << std::endl;


        TS_ASSERT_EQUALS(test7.GetRoster().at(0).GetLast(), "Bridges");
        
    }

    void testErrors() {

        Student test7s("Marvin", "Whee", 70);
        Course test8;
        test8.LoadFile("c.txt");
        test8.RemoveStudent(test7s);
        test8.LoadFile("course1.txt");
        test8.PassCourse("");
        test8.RemoveStudent(test7s);

    }

};
#endif /* TESTCASES_H */
