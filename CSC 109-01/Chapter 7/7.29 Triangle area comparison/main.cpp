/*
Copyright 2024
Author: Ben Carpenter

Assignment:
Given class Triangle (in files Triangle.h and Triangle.cpp), complete main() to read and set the base and height of triangle1 and of triangle2, determine which triangle's area is smaller, and output that triangle's info, making use of Triangle's relevant member functions.

Ex: If the input is:

    *3.0 4.0
    *4.0 5.0

where 3.0 is triangle1's base, 4.0 is triangle1's height, 4.0 is triangle2's base, and 5.0 is triangle2's height, the output is:

    *Triangle with smaller area:
    *Base: 3.00
    *Height: 4.00
    *Area: 6.00
*/

#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
    Triangle triangle1;
    Triangle triangle2;
    double tb, th;

    //Taking user input for triangle 1
    cin >> tb >> th;

    //Setting base and height for triangle 1
    triangle1.SetBase(tb);
    triangle1.SetHeight(th);

    //Taking user input for triangle 2
    cin >> tb >> th;

    //Setting base and height for triangle 1
    triangle2.SetBase(tb);
    triangle2.SetHeight(th);
       
    cout << "Triangle with smaller area:" << endl;

    //Outputting smaller triangle
    if (triangle1.GetArea() < triangle2.GetArea()) {
        triangle1.PrintInfo();
    } else {
        triangle2.PrintInfo();
    }
   
    return 0;
}
