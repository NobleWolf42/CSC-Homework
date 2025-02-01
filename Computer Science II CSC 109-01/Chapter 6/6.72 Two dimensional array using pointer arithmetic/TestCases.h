/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
#include "TwoDArray.h"

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testSetAndGetRow() {
        int r = 6, c = 7;
        double* the_array = new double[r*c];
        double* row0 = new double[c]{11,2,3,4,5,6,7};
        double* row1 = new double[c]{10,9,8,7,6,5,4};
        double* row2 = new double[c]{12,11,11,11,11,31,11};
        double* row3 = new double[c]{5,5,5,5,5,5,5};
        double* row4 = new double[c]{12,3,4,9,8,7,6};
        double* row5 = new double[c]{12,3,4,9,8,7,6};
        double* pulledRow;

        set_row(the_array, 0, 7, row0);
        set_row(the_array, 1, 7, row1);
        set_row(the_array, 2, 7, row2);
        set_row(the_array, 3, 7, row3);
        set_row(the_array, 4, 7, row4);
        set_row(the_array, 5, 7, row5);

        pulledRow = get_row(the_array, 3, 7);

        TS_ASSERT_EQUALS(*(pulledRow), *(row3));
    

    }

    void testSetAndGetElement() {
        int r = 6, c = 7;
        double* the_array = new double[r*c];
        double* row0 = new double[c]{11,2,3,4,5,6,7};
        double* row1 = new double[c]{10,9,8,7,6,5,4};
        double* row2 = new double[c]{12,11,11,11,11,31,11};
        double* row3 = new double[c]{5,5,5,5,5,5,5};
        double* row4 = new double[c]{12,3,4,9,8,7,6};
        double* row5 = new double[c]{12,3,4,9,8,7,6};

        set_row(the_array, 0, 7, row0);
        set_row(the_array, 1, 7, row1);
        set_row(the_array, 2, 7, row2);
        set_row(the_array, 3, 7, row3);
        set_row(the_array, 4, 7, row4);
        set_row(the_array, 5, 7, row5);

        set_element(the_array, 1, 7, 3, 55.00);

        TS_ASSERT_EQUALS(get_element(the_array, 1, 7, 3), 55.00);


    }

    void testSum() {
        int r = 6, c = 7;
        double* the_array = new double[r*c];
        double* row0 = new double[c]{11,2,3,4,5,6,7};
        double* row1 = new double[c]{10,9,8,7,6,5,4};
        double* row2 = new double[c]{12,11,11,11,11,31,11};
        double* row3 = new double[c]{5,5,5,5,5,5,5};
        double* row4 = new double[c]{12,3,4,9,8,7,6};
        double* row5 = new double[c]{12,3,4,9,8,7,6};

        set_row(the_array, 0, 7, row0);
        set_row(the_array, 1, 7, row1);
        set_row(the_array, 2, 7, row2);
        set_row(the_array, 3, 7, row3);
        set_row(the_array, 4, 7, row4);
        set_row(the_array, 5, 7, row5);

        TS_ASSERT_EQUALS(sum(the_array, 6, 7), 318.00);

    }

    void testMaxAndMin() {
        int r = 6, c = 7;
        double* the_array = new double[r*c];
        double* row0 = new double[c]{11,2,3,4,5,6,7};
        double* row1 = new double[c]{10,9,8,7,6,5,4};
        double* row2 = new double[c]{12,11,11,11,11,31,11};
        double* row3 = new double[c]{5,5,5,5,5,5,5};
        double* row4 = new double[c]{12,3,4,9,8,7,6};
        double* row5 = new double[c]{12,3,4,9,8,7,6};

        set_row(the_array, 0, 7, row0);
        set_row(the_array, 1, 7, row1);
        set_row(the_array, 2, 7, row2);
        set_row(the_array, 3, 7, row3);
        set_row(the_array, 4, 7, row4);
        set_row(the_array, 5, 7, row5);

        TS_ASSERT_EQUALS(find_max(the_array, 6, 7), 31.00);
        TS_ASSERT_EQUALS(find_min(the_array, 6, 7), 2.00);

    }

    void testString() {
        int r = 6, c = 7;
        double* the_array = new double[r*c];
        double* row0 = new double[c]{11,2,3,4,5,6,7};
        double* row1 = new double[c]{10,9,8,7,6,5,4};
        double* row2 = new double[c]{12,11,11,11,11,31,11};
        double* row3 = new double[c]{5,5,5,5,5,5,5};
        double* row4 = new double[c]{12,3,4,9,8,7,6};
        double* row5 = new double[c]{12,3,4,9,8,7,6};

        set_row(the_array, 0, 7, row0);
        set_row(the_array, 1, 7, row1);
        set_row(the_array, 2, 7, row2);
        set_row(the_array, 3, 7, row3);
        set_row(the_array, 4, 7, row4);
        set_row(the_array, 5, 7, row5);

        TS_ASSERT_EQUALS(to_string(the_array, 6, 7), "     11.00      2.00      3.00      4.00      5.00      6.00      7.00\n     10.00      9.00      8.00      7.00      6.00      5.00      4.00\n     12.00     11.00     11.00     11.00     11.00     31.00     11.00\n      5.00      5.00      5.00      5.00      5.00      5.00      5.00\n     12.00      3.00      4.00      9.00      8.00      7.00      6.00\n     12.00      3.00      4.00      9.00      8.00      7.00      6.00\n");


    }

};
#endif /* TESTCASES_H */
