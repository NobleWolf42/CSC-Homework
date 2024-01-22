/*
Write a program that prompts the user for two integers and then prints

• The sum
• The difference
• The product
• The average
• The distance (absolute value of the difference)
• The maximum (the larger of the two)
• The minimum (the smaller of the two)
*/
#include <iostream>
#include <cstdlib>

using namespace std; 

int main() {

    //Declaring variables
    int a;
    int b;
    int sum;
    int difference;

    //Getting user inputs
    cout << "Please enter the first integer: "; 
    cin >> a; 
    cout << "Please enter the second integer: "; 
    cin >> b; 

    //Finding and Printing sum
    sum = a + b;
    cout << "The sum of " << a << " and " << b << " is " << sum << "." << endl;

    //Finding and Printing difference
    difference = a - b;
    cout << "The difference of " << a << " and " << b << " is " << difference << "." << endl;

    //Printing product
    cout << "The product of " << a << " and " << b << " is " << a * b << "." << endl;

    //Printing average
    cout << "The average of " << a << " and " << b << " is " << static_cast<double>(sum) / 2 << "." << endl;

    //Printing distance
    cout << "The distance between " << a << " and " << b << " is " << abs(difference) << "." << endl;

    //Printing maximum
    cout << "The maximum of " << a << " and " << b << " is " << (abs(difference) + sum) / 2 << "." << endl;

    //Printing minimum
    cout << "The minimum of " << a << " and " << b << " is " << ((abs(difference) * -1) + sum) / 2 << "." << endl;
    return 0; 
}