/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "PlaylistNode.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDefaultConstructor() {

        PlaylistNode test1;
        TS_ASSERT_EQUALS(test1.GetID(), "none");
        TS_ASSERT_EQUALS(test1.GetSongName(), "none");
        TS_ASSERT_EQUALS(test1.GetArtistName(), "none");
        TS_ASSERT_EQUALS(test1.GetSongLength(), 0);
        TS_ASSERT_EQUALS(test1.GetNext(), nullptr);
        
    }

    void testNonDefaultConstructor() {

        PlaylistNode test2("Whee", "Hello", "HeHe", 5467);
        TS_ASSERT_EQUALS(test2.GetID(), "Whee");
        TS_ASSERT_EQUALS(test2.GetSongName(), "Hello");
        TS_ASSERT_EQUALS(test2.GetArtistName(), "HeHe");
        TS_ASSERT_EQUALS(test2.GetSongLength(), 5467);
        TS_ASSERT_EQUALS(test2.GetNext(), nullptr);
        
    }

    void testInsertAfter() {

        PlaylistNode* head = new PlaylistNode();
        PlaylistNode* test3 = new PlaylistNode("Whee2", "Hello2", "HeHe2", 425);
        head->InsertAfter(test3);
        TS_ASSERT_EQUALS(head->GetNext()->GetID(), "Whee2");
        TS_ASSERT_DIFFERS(head->GetNext(), nullptr);
        
    }

    void testSetNext() {

        PlaylistNode* head = new PlaylistNode();
        PlaylistNode* test4a = new PlaylistNode("Whee3", "Hello3", "HeHe3", 345);
        PlaylistNode* test4b = new PlaylistNode("Whee4", "Hello4", "HeHe4", 456);
        head->InsertAfter(test4a);
        head->SetNext(test4b);
        test4b->SetNext(test4a);
        TS_ASSERT_EQUALS(head->GetNext()->GetID(), "Whee4");
        TS_ASSERT_DIFFERS(head->GetNext()->GetNext(), nullptr);
        TS_ASSERT_THROWS_NOTHING(test4b->PrintPlaylistNode());
        
    }



};
#endif /* TESTCASES_H */
