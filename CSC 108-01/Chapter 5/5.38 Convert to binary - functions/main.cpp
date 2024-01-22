/*
Write a program that takes in a positive integer as input, and outputs a string of 1's and 0's representing the integer in binary. For an integer x, the algorithm is:

    *As long as x is greater than 0
    *    Output x % 2 (remainder is either 0 or 1)
    *    x = x / 2

Note: The above algorithm outputs the 0's and 1's in reverse order. You will need to write a second function to reverse the string.

Ex: If the input is:

    *6

the output is:

    *110

The program must define and call the following two functions. Define a function named IntToReverseBinary() that takes an int as a parameter and returns a string of 1's and 0's representing the integer in binary (in reverse). Define a function named StringReverse() that takes a string as a parameter and returns a string representing the input string in reverse.

string IntToReverseBinary(int integerValue)
string StringReverse(string userString)
*/
#include <iostream>
#include <string>
using namespace std;

string StringReverse(string userString) {
    string output;

    for (size_t i = 0; i < userString.length(); ++i) {
        output = userString[i] + output;
    }

    return output;
}

string IntToReverseBinary(int integerValue){
    string output;

    while (integerValue != 0) {
        output += to_string(integerValue % 2);
        integerValue = integerValue / 2;
    }

    return output;
}

int main() {
    
    //Declaring variables
    int uIn;

    //Getting user input
    cin >> uIn;

    cout << StringReverse(IntToReverseBinary(uIn)) << endl;

    return 0;
}