/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TWODARRAY_H
#define TWODARRAY_H
#include <string>

void set_row( double *the_array , int row_num, int col_size, double *row_vals);

double* get_row(double *the_array, int row_num, int col_size);

void set_element( double *the_array, int row_num, int col_size, int col_num, double val);

double get_element(double *the_array, int row_num, int col_size, int col_num);

double sum(double *the_array, int row_size, int col_size);

double find_max(double *the_array, int row_size, int col_size);

double find_min(double *the_array, int row_size, int col_size);

std::string to_string(double *the_array, int row_size, int col_size);


#endif /* TWODARRAY_H */

