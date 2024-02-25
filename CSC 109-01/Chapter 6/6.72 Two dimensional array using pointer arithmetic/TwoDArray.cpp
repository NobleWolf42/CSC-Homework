/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <string>

void set_row(double* the_array, int row_num, int col_size, double* row_vals) {
    int rowNum = row_num * col_size;

    for (int col=0; col<col_size; col++) {
        *(the_array + rowNum + col) =  *(row_vals + col);
    }

} // Stores the array of row_ vals in row

double* get_row(double* the_array, int row_num, int col_size) {
    return the_array + row_num * col_size;
} // Returns the specified row of a two dimensional array

void set_element(double* the_array, int row_num, int col_size, int col_num, double val) {
    *(the_array + row_num + )
} // Sets the specified element

double get_element(double* the_array, int row_num, int col_size, int col_num) {

} // Returns the specified element

double sum(double* the_array, int row_size, int col_size) {

} // Returns sum of the values in the array

double find_max(double* the_array, int row_size, int col_size) {

}  // Returns the largest value in the array

double find_min(double* the_array, int row_size, int col_size) {

} // Returns the smallest value in the array

std::string to_string(double* the_array, int row_size, int col_size) {

} // Returns a string representing the matrix.  

// Hint: use ostringstream to create your string and formatting. See Chapter 9.4
// Set width to 10 and use fixed and setprecision to format the output.