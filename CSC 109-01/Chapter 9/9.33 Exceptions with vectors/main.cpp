/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Complete a program that reads a vector index as input and outputs the element of a vector of 10 names at the index specified by the input. Use a try block to output the name and a catch block to catch any out_of_range exceptions. When an out_of_range exception is caught, output the message from the exception object and the first element in the vector if the index is negative or the last element if the index is greater than the size of the vector.

Hint: Format the exception outputs using the what() function from the exception object. Do not hard code the exception messages.

Ex: If the input of the program is:

    *5

the program outputs:

    *Jane

Ex: If the input of the program is:

    *12

the program outputs:

    *Exception! vector::_M_range_check: __n (which is 12) >= this->size() (which is 10)
    *The closest name is: Johnny

Ex: If the input of the program is:

    *-2

the program outputs:

    *Exception! vector::_M_range_check: __n (which is 18446744073709551614) >= this->size() (which is 10)
    *The closest name is: Ryley

*/

#include <iostream>
#include <vector>
#include <stdexcept>      // For std::out_of_range
using namespace std;

int main() {
    vector<string> names = { "Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya", "Tyrese", "Johnny" };
    int index;

    cin >> index;
   
    try {
    
        cout << names.at(index) << endl;

    } catch (out_of_range& error) {

        cout << "Exception! " << error.what() << endl;
        if (index > 9) {
            index = 9;
        } else {
            index = 0;
        }
        cout << "The closest name is: " << names.at(index) << endl;

    }

    return 0;
}
