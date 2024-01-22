/*
Given two input integers for an arrow body and arrowhead (respectively), print a right-facing arrow.

Ex: If the input is:

0 1
the output is:

     1
     11
00000111
000001111
00000111
     11
     1
*/
#include <iostream>
using namespace std;

int main() {

    //Declaring variables
    int baseDigit;
    int headDigit;

    //Gets user input
    cin >> baseDigit;
    cin >> headDigit;

    //Prints arrow
    cout << "     " << headDigit << endl;
    cout << "     " << headDigit << headDigit << endl;
    cout << baseDigit << baseDigit << baseDigit << baseDigit << baseDigit << headDigit << headDigit << headDigit << endl;
    cout << baseDigit << baseDigit << baseDigit << baseDigit << baseDigit << headDigit << headDigit << headDigit << headDigit << endl;
    cout << baseDigit << baseDigit << baseDigit << baseDigit << baseDigit << headDigit << headDigit << headDigit << endl;
    cout << "     " << headDigit << headDigit << endl;
    cout << "     " << headDigit << endl;
    return 0;
}