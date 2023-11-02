/*
Write a function MaxMagnitude() with three integer parameters that returns the largest magnitude value. Use the function in the main program that takes three integer inputs and outputs the largest magnitude value.

Ex: If the inputs are:

    *5 7 9

function MaxMagnitude() returns and the main program outputs:

    *9

Ex: If the inputs are:

    *-17 -8 -2

function MaxMagnitude() returns and the main program outputs:

    *-17

Note: The function does not just return the largest value, which for -17 -8 -2 would be -2. Though not necessary, you may use the absolute-value built-in math function.

Your program must define and call a function:
int MaxMagnitude(int userVal1, int userVal2, int userVal3)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int MaxMagnitude(int userVal1, int userVal2, int userVal3) {
    int uv1 = abs(userVal1), uv2 = abs(userVal2), uv3 = abs(userVal3);
    if (uv1 > uv2 && uv1 > uv3) {
        return userVal1;
    } else if (uv2 >> uv1 && uv2 > uv3) {
        return userVal2;
    } else {
        return userVal3;
    }
}

int main() {
    
    //Declaring variables
    int uIn1, uIn2, uIn3;

    //Getting user input
    cin >> uIn1 >> uIn2 >> uIn3;

    //Running function
    cout << MaxMagnitude(uIn1, uIn2, uIn3) << endl;

    return 0;
}