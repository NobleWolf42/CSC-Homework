/*
Write a program whose inputs are four integers, and whose outputs are the maximum and the minimum of the four values.

Ex: If the input is:

    *12 18 4 9

the output is:

    *Maximum is 18 
    *Minimum is 4

The program must define and call the following two functions. Define a function named MaxNumber that takes four integer parameters and returns an integer representing the maximum of the four integers. Define a function named MinNumber that takes four integer parameters and returns an integer representing the minimum of the four integers.

int MaxNumber(int num1, int num2, int num3, int num4)
int MinNumber(int num1, int num2, int num3, int num4)
*/
#include <iostream>
using namespace std;

int MaxNumber(int num1, int num2, int num3, int num4){
    if (num1 >= num2 && num1 >= num3 && num1 >= num4) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3 && num2 >= num4) {
        return num2;
    } else if (num3 >= num1 && num3 >= num2 && num3 >= num4) {
        return num3;
    } else {
        return num4;
    }
}

int MinNumber(int num1, int num2, int num3, int num4){
    if (num1 <= num2 && num1 <= num3 && num1 <= num4) {
        return num1;
    } else if (num2 <= num1 && num2 <= num3 && num2 <= num4) {
        return num2;
    } else if (num3 <= num1 && num3 <= num2 && num3 <= num4) {
        return num3;
    } else {
        return num4;
    }
}

int main() {
    
    //Declaring variables
    int u1, u2, u3, u4;

    //Getting user input
    cin >> u1 >> u2 >> u3 >> u4;

    //Displaying results
    cout << "Maximum is " << MaxNumber(u1, u2, u3, u4) << endl;
    cout << "Minimum is " << MinNumber(u1, u2, u3, u4) << endl;

    return 0;
}