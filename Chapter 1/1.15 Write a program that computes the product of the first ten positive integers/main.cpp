/*
Write a program that computes the product of the first ten positive integers, 1 × 2 × … × 10, and the sum of the reciprocal of each number. (1/1,1/2,1/3,…) (Use the * symbol, not × for multiplication in C++).

ask the user to enter 10 numbers.

Try writing the program, and check the results against a pocket calculator. The program’s results aren’t likely to be correct.

Then write the numbers as reciprocals of the input numbers, 1/x1, 1/x2, . . ., 1/xn, and run the program again.
*/
#include <iostream>

using namespace std;

int main() {

    //Declaring Variables, the input has to be float so we can divide by them and get decimals
    float num0;
    float num1;
    float num2;
    float num3;
    float num4;
    float num5;
    float num6;
    float num7;
    float num8;
    float num9;
    double multiplied;
    float reciprocals;

    //Getting user input
    cin >> num0;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    cin >> num5;
    cin >> num6;
    cin >> num7;
    cin >> num8;
    cin >> num9;
    cout << endl;
    
    //Multiplying inputs here
    multiplied = num0 * num1 * num2 * num3 * num4 * num5 * num6 * num7 * num8 * num9;
    cout << multiplied << endl;
    
    //Adding the reciprocals here
    reciprocals = 1 / num0 + 1 / num1 + 1 / num2 + 1 / num3 + 1 / num4 + 1 / num5 + 1 / num6 + 1 / num7 + 1 / num8 + 1 / num9;
    cout << reciprocals << endl;
    return 0;
}