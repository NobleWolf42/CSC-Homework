/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Infix_Evaluator.h"
#include <string>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void test1() {
        Infix_Evaluator infix;

        TS_ASSERT_THROWS_ANYTHING(infix.eval("5*10+8+3/0*5-2*4-12"));
        TS_ASSERT_THROWS_ANYTHING(infix.eval(" "));
        TS_ASSERT_THROWS_ANYTHING(infix.eval("(5+6"));
        TS_ASSERT_THROWS_ANYTHING(infix.eval("5+"));
        TS_ASSERT_THROWS_ANYTHING(infix.eval("+"));
        TS_ASSERT_THROWS_ANYTHING(infix.eval("5++7"));
        TS_ASSERT_THROWS_ANYTHING(infix.eval("G"));
        TS_ASSERT_EQUALS(infix.eval("5*10+8+   3*5- 2*4-12  "), (5*10+8+3*5-2*4-12));
        TS_ASSERT_EQUALS(infix.eval("5*10+(8+   3*5)-( 2*4-12 )"), (5*10+(8+3*5)-(2*4-12)));
        TS_ASSERT_EQUALS(infix.eval("5*10+(8+   3*5)*( 2*4-12 )"), (5*10+(8+3*5)*(2*4-12)));
        TS_ASSERT_EQUALS(infix.eval("5*10+(8+3*5)*(2*4-12/6)"), (5*10+(8+3*5)*(2*4-12/6)));
        TS_ASSERT_EQUALS(infix.eval("5*10+8+3*2*4-12/6"), (5*10+8+3*2*4-12/6));
        TS_ASSERT_EQUALS(infix.eval("5*10+8*2*4-12/6"), (5*10+8*2*4-12/6));
        TS_ASSERT_EQUALS(infix.eval("5*2*4-12/6"), (5*2*4-12/6));

    }

};
#endif /* TESTCASES_H */
