/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
You must use pointer arithmetic for this homework.  If you use array syntax, such as a[1][2], you won't get any credit for your submission.  You must include eight cxxtest cases with your assignment using pointers and submit them to Web-CAT. 

Belows are the function declarations using pointers.  Please use the exact name and format as it shows here.  If you change the name or the parameters of the function, it will not compile on Web-CAT.

Write a collection of functions that operates on a two-dimensional array. The main function should provide calls to each of the functions and display the results. The functions should have the following declarations:

    1. Name your header file as TwoDArray.h.  Include the following functions declaration in your header file.

    2. Name your implementation file as TwoDArray.cpp.

    3. The two-dimensional array stores double values.

// *thearray is a two dimensional array; rownum is the row number to be replaced ; colsize is column size; rowvals is the new the row void setrow(double *thearray , int rownum, int colsize, double *rowvals); // Stores the array of row vals in row

// return a row of two-dimensional array by row number. double* getrow(double *thearray, int rownum, int colsize); // Returns the specified row from a two-dimensional array

// set a value in a two-dimensional array by row and column number void setelement( double *thearray, int rownum, int colsize, int col_num, double val); // Sets the specified element

// return a value from a two-dimensional array by row and column number. double getelement(double *thearray, int rownum, int colsize, int col_num); // Returns the specified element

double sum(double *thearray, int rowsize, int col_size); // Returns sum of the values in the array

double findmax(double *thearray, int rowsize, int colsize);  // Returns the largest value in the array

double findmin(double *thearray, int rowsize, int colsize); // Returns the smallest value in the array

string tostring(double *thearray, int rowsize, int colsize); // Returns a string representing the two-dimensional array. Set the width to 10 spaces. Use fixed and setprecision to 2 to format your output.

    *Create a two-dimensional array and test the above function.  I will use a different two-dimensional array to test your code.
    *
    *     11.00      2.00      3.00      4.00      5.00      6.00      7.00
    *     10.00      9.00      8.00      7.00      6.00      5.00      4.00
    *     12.00     11.00     11.00     11.00     11.00     31.00     11.00
    *      5.00      5.00      5.00      5.00      5.00      5.00      5.00
    *     12.00      3.00      4.00      9.00      8.00      7.00      6.00
    *     12.00      3.00      4.00      9.00      8.00      7.00      6.00

For this homework assignment, don't use c++ class for this assignment.
*/

#include <iostream>
#include <string>
#include <sstream>  // don't remove this line; use for ostringstream
#include <iomanip>      // use std::setw to set the width for each number
#include "TwoDArray.h"

using namespace std;

int main() {
    int r = 6, c = 7;
    double* the_array = new double[r*c]{
        11,2,3,4,5,6,7,10,9,8,7,6,5,4,12,11,11,11,11,31,11,5,5,5,5,5,5,5,12,3,4,9,8,7,6,12,3,4,9,8,7,6

    };
   
    /*row_vals[0] = 11;
    row_vals[1] = 2;
    row_vals[2] = 3;
    row_vals[3] = 4;
    row_vals[4] = 5;
    row_vals[5] = 6;
    row_vals[6] = 7;
    set_row(the_array, 0, 7, row_vals);
    
    row_vals[0] = 10;
    row_vals[1] = 9;
    row_vals[2] = 8;
    row_vals[3] = 7;
    row_vals[4] = 6;
    row_vals[5] = 5;
    row_vals[6] = 4;
    set_row(the_array, 1, 7, row_vals);
    
    row_vals[0] = 12;
    row_vals[1] = 11;
    row_vals[2] = 11;
    row_vals[3] = 11;
    row_vals[4] = 11;
    row_vals[5] = 31;
    row_vals[6] = 11;
    set_row(the_array, 2, 7, row_vals);
    
    row_vals[0] = 5;
    row_vals[1] = 5;
    row_vals[2] = 5;
    row_vals[3] = 5;
    row_vals[4] = 5;
    row_vals[5] = 5;
    row_vals[6] = 5;
    set_row(the_array, 3, 7, row_vals);
    
    row_vals[0] = 12;
    row_vals[1] = 3;
    row_vals[2] = 4;
    row_vals[3] = 9;
    row_vals[4] = 8;
    row_vals[5] = 7;
    row_vals[6] = 6;
    set_row(the_array, 4, 7, row_vals);

    row_vals[0] = 12;
    row_vals[1] = 3;
    row_vals[2] = 4;
    row_vals[3] = 9;
    row_vals[4] = 8;
    row_vals[5] = 7;
    row_vals[6] = 6;
    set_row(the_array, 5, 7, row_vals);*/

    cout << to_string(the_array, 6, 7) << endl;
   
}
