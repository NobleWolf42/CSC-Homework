/*
This program will take three inputs: a, b, and c. It will the use those inputs to calculate the quadratic formula
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    //Declaring variables
    double a;
    double b;
    double c;
    double negativeB;
    double squareValue;
    double denominator;

    //Getting user input
    cout << "This will calculate the values for a quadratic equation." << endl << endl << "Please enter the value for a: ";
    cin >> a;
    cout << "Please enter the value for b: ";
    cin >> b;
    cout << "Please enter the value for c: ";
    cin >> c;
    cout << endl;

    //Finding the values for the quadratic formula
    negativeB = -1 * b;
    squareValue = sqrt(pow(b, 2) - 4 * a * c);
    denominator = 2 * a;

    //Error catching
    if(pow(b, 2) - 4 * a * c < 0) {
        cout << "Cannot have imaginary numbers!";
        return 0;
    }
    if(c == 0) {
        cout << "Cannot divide by 0!";
        return 0;
    }

    //Printing results
    cout << "The + result is: " << (negativeB + squareValue) / denominator << endl;
    cout << "The - result is: " << (negativeB - squareValue) / denominator << endl;
    return 0;
}