/*
Given three floating-point numbers x, y, and z, output x to the power of z, x to the power of (y to the power of z), the absolute value of y, and the square root of (xy to the power of z).

Ex: If the input is:

    *5.0 6.5 3.2

the output is:

    *172.466 1.29951e+279 6.5 262.43

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    //Declaring variables
    double x;
    double y;
    double z;

    //Getting user inputs
    cin >> x >> y >> z;

    //Finding and printing powers, absolute vales, and square roots
    cout << pow(x, z) << " " << pow(x, pow(y, z)) << " " << abs(y) << " " << sqrt(pow(x * y, z)) << endl;
    return 0;
}