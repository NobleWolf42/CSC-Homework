/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Write a function that merges two sorted dynamic allocated array (DAA), producing a new sorted DAA. Keep an index into each DAA, indicating how much of it has been processed already. Each time, append the smallest unprocessed element from either DAA, then advance the index. For example,

    *if array a is
    *
    *1 4 9 16
    *
    *and array b is
    *
    *4 7 9 9 11
    *
    *then merge_sorted returns a new DAA,
    *
    *1 4 4 7 9 9 9 11 16

int* merge_sorted(int* a, int n, int* b, int m)

Note: you must use dynamically allocated array (DAA) to get credits for this problem.
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Write a Swap function that swap first and second value
 * @param xp a pointer to the first value
 * @param yp a pointer to the second value
 * No return value
 */
 
 /**
 * Write BubbleSort function: sort the DAA in place
 * @param x is a dynamic allocated array (DAA)
 * @param n DAA size
 * No return
 * Note: Look up a bubule sort algorithm that use swap function
 * Note: use the swap function to swap values as described in the bubble sort algorithm.
 * 
 */
 

/**
 * Write a GetUserValues function to ask user to enter number of inputs and return a new DAA
 * @param numValues number of inputs
 * @return a dynamic allocated array
 * Note: the parameter is the number of inputs that the user will enter
 */
 
 /**
 * MergeSorted function: merge two sorted DAA and return a new sort DAA
 * @param a first DAA
 * @param n first DAA size
 * @param b second DAA
 * @param m second DAA size
 * @return a merged sorted DAA
 */
 
 
/**
 * PrintArray function: to print a DAA
 * @param arr DAA to be printed
 * @param size size of DAA
 * No return
 */
 

int main() { // Begin Main

    // Vectors and variable
    int n, m;
    //
    cout << "Enter the first list of inputs begins with an integer indicating the number of integers that follow: " << endl;
    cin >> n;
    
    //TODO: Call GetUserValues to fill up the first DAA using n as the size for the array
    
    cout "Print array1: " << endl;
    PrintArray(a1, n);
    
    cout << "Enter the second list of inputs begins with an integer indicating the number of integers that follow: " << endl;
    cin >> m;
    cout "Print array2: " << endl;
    PrintArray(a2, m);
    
    //TODO: Call GetUserValues to fill up the second DAA using m as the size for the array
    
    // TODO: call bubble sort function to sort the two DAA individually.
    
    // TODO: merge two sorted array
    // Note: merge sort function returns a merge DAA array
    
    
    // Print results
    cout << "Result of merge sort of a1 and a2 is " << endl;
    PrintArray(a1, n);  // print the first DAA
    PrintArray(a2, m);  // print the second DAA
    PrintArray(c, k);   // print the merged DAA
    cout << endl;

    return 0;
} // End Main
