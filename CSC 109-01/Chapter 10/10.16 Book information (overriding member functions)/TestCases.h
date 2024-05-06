/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Encyclopedia.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testConstruction() {

        Encyclopedia test1;
        
        test1.SetTitle("Test1");
        test1.SetAuthor("Wheee");
        test1.SetPublisher("Penguin");
        test1.SetPublicationDate("2015");
        test1.SetEdition("5th");
        test1.SetNumPages(586);
        test1.SetNumVolumes(8);
        test1.PrintInfo();

        TS_ASSERT_EQUALS(test1.GetTitle(), "Test1");
        TS_ASSERT_EQUALS(test1.GetAuthor(), "Wheee");
        TS_ASSERT_EQUALS(test1.GetPublisher(), "Penguin");
        TS_ASSERT_EQUALS(test1.GetPublicationDate(), "2015");
        TS_ASSERT_EQUALS(test1.GetEdition(), "5th");
        TS_ASSERT_EQUALS(test1.GetNumPages(), 586);
        TS_ASSERT_EQUALS(test1.GetNumVolumes(), 8);
        
    }

};
#endif /* TESTCASES_H */
