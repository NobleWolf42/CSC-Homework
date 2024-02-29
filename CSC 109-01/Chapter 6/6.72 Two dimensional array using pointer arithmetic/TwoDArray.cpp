/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "TwoDArray.h"
#include <sstream>
#include <iostream>
#include <iomanip>

void set_row(double* the_array, int row_num, int col_size, double* row_vals) {
    int rowNum = row_num * col_size;

    for (int col = 0; col < col_size; col++) {
        *(the_array + rowNum + col) =  *(row_vals + col);
    }

} // Stores the array of row_ vals in row

double* get_row(double* the_array, int row_num, int col_size) {
    return the_array + row_num * col_size;
} // Returns the specified row of a two dimensional array

void set_element(double* the_array, int row_num, int col_size, int col_num, double val) {
    *(the_array + (row_num * col_size) + col_num) = val;
} // Sets the specified element

double get_element(double* the_array, int row_num, int col_size, int col_num) {
    return *(the_array + (row_num * col_size) + col_num);
} // Returns the specified element

double sum(double* the_array, int row_size, int col_size) {
    double returnVal = 0;

    for (int i = 0; i < row_size * col_size; ++i) {
        returnVal =  returnVal + *(the_array + i);
    }

    return returnVal;
} // Returns sum of the values in the array

double find_max(double* the_array, int row_size, int col_size) {
    double returnVal = *(the_array + 0 + 0);

    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            int rowNum = row * col_size;
            if (returnVal < *(the_array + rowNum + col)) {
                returnVal = *(the_array + rowNum + col);
            }
        }
    }

    return returnVal;
}  // Returns the largest value in the array

double find_min(double* the_array, int row_size, int col_size) {
    double returnVal = *(the_array + 0 + 0);

    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            int rowNum = row * col_size;
            if (returnVal > *(the_array + rowNum + col)) {
                returnVal = *(the_array + rowNum + col);
            }
        }
    }

    return returnVal;
} // Returns the smallest value in the array

std::string to_string(double* the_array, int row_size, int col_size) {
    std::ostringstream returnVal;
    std::string rowstr;
    returnVal << std::fixed << std::setprecision(2);

    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            int rowNum = row * col_size;
            returnVal << std::setw(10) << *(the_array + rowNum + col);
        }
        returnVal << "\n";
    }

    return returnVal.str();
} // Returns a string representing the matrix.  

// Hint: use ostringstream to create your string and formatting. See Chapter 9.4
// Set width to 10 and use fixed and setprecision to format the output.
