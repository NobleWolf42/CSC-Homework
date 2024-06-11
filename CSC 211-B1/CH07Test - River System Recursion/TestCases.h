/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Rivers.h"
#include <string>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testRivers() {
        list<Rivers*> rs1;
        Rivers* r1 = new Rivers("Missouri",  6.5,  6.5, rs1);
        list<Rivers*> rs2;
        Rivers* r2 = new Rivers("Jefferson", 7.0, 6.2, rs2);
        r1->make_river(r2);
        list<Rivers*> rs3;
        Rivers* r3 = new Rivers("Beaverhead",  6.2, 6.7, rs3);
        r2->make_river(r3);

        list<Rivers*> rs4;
        Rivers* r4 = new Rivers("Bighole",  7.0, 7.5, rs4);
        r2->make_river(r4);

        list<Rivers*> rs5;
        Rivers* r5 = new Rivers("Sun", 7.5, 7.0, rs5);
        r1->make_river(r5);

        list<Rivers*> rs6;
        Rivers* r6 = new Rivers("Yellowstone", 7.0, 7.5, rs6);
        r1->make_river(r6);

        list<Rivers*> rs7;
        Rivers* r7 = new Rivers("Gardner", 7.1, 6.9, rs7);
        r6->make_river(r7);

        list<Rivers*> rs8;
        Rivers* r8 = new Rivers("Shields", 7.9, 8.0, rs8);
        r6->make_river(r8);

        list<Rivers*> rs9;
        Rivers* r9 = new Rivers("Boulder", 8.5, 6.5, rs9);
        r6->make_river(r9);

        list<Rivers*> rs10;
        Rivers* r10 = new Rivers("Madison", 8.0, 8.0, rs10);
        r1->make_river(r10);

        list<Rivers*> rs11;
        Rivers* r11 = new Rivers("Gallatin", 6.8, 7.2, rs11);
        r1->make_river(r11);

        TS_ASSERT_EQUALS(r1->getRiverName(), "Missouri");
        TS_ASSERT_EQUALS(r1->getDo(), 6.5);
        TS_ASSERT_EQUALS(r9->getPh(), 8.5);
        TS_ASSERT_EQUALS(r1->getRivers(), rs1);

        TS_ASSERT_EQUALS(r2->list_acidic_rivers(), "Beaverhead ");
        TS_ASSERT_EQUALS(r1->list_acidic_rivers(), "Missouri Beaverhead Gallatin ");

        TS_ASSERT(r1->unhealthy());

        r3->setPh(7.0);

        TS_ASSERT(!r1->unhealthy());

        TS_ASSERT(r1->find_subsystem("Beaverhead"));
        TS_ASSERT(r1->find_subsystem("Boulder"));
        TS_ASSERT_EQUALS(r1->find_subsystem("Assabet"), NULL);
        
        r2->setRiverName("Assabet");
        
        TS_ASSERT(r1->find_subsystem("Assabet"));
        TS_ASSERT(!r1->bad_numbers(r2));
        
        r2->setDo(5.9);
        
        TS_ASSERT(r1->bad_numbers(r2));
        TS_ASSERT(!r1->bad_numbers(nullptr));

        Rivers* r12 = new Rivers();
        r12 = r1->lower_all_ph();

        list<Rivers*>::const_iterator begin1 = r12->getRivers().begin();
        begin1++;
        begin1++;

        Rivers* test1 = *begin1;
        list<Rivers*>::const_iterator begin2 = test1->getRivers().begin();
        begin2++;
        begin2++;

        Rivers* test2 = *begin2;

        TS_ASSERT_EQUALS(test2->getPh(), r9->getPh() - 0.1);

        r1->print();

    }

};
#endif /* TESTCASES_H */
