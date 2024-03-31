/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "OfferedCourse.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstruction() {

        OfferedCourse test1;
        
        test1.SetCourseNumber("E3356");
        test1.SetCourseTitle("Hehe");
        test1.SetInstructorName("Nope");
        test1.SetLocation("Earth");
        test1.SetClassTime("Who knows");
        test1.SetTerm("This isn't in the assignment");
        test1.PrintInfo();

        TS_ASSERT_EQUALS(test1.GetCourseNumber(), "E3356");
        TS_ASSERT_EQUALS(test1.GetCourseTitle(), "Hehe");
        TS_ASSERT_EQUALS(test1.GetInstructorName(), "Nope");
        TS_ASSERT_EQUALS(test1.GetLocation(), "Earth");
        TS_ASSERT_EQUALS(test1.GetClassTime(), "Who knows");
        TS_ASSERT_EQUALS(test1.GetTerm(), "This isn't in the assignment");
        
    }

};
#endif /* TESTCASES_H */
