/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Extend the functionality of cout by implementing a friend function in Number.cpp that overloads the insertion operator. The overloaded insertion operator returns an output stream containing a string representation of a Number object. The string should be in the format "The value is yourNum", where yourNum is the value of the integer instance field of the Number class.

Hint: the declaration of the friend function is provided in Number.h.

Ex: if the value of yourNum is 723, then the output is:

    *The value is 723

*/

#include "Number.h"
#include <iostream>
using namespace std;

int main() {
   int input;
   cin >> input;
   
	Number num = Number(input);
	cout << num;

	return 0;
}
