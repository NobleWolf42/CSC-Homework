/*
Write a program that prints all solutions to the quadratic equation ax bx c 2 + += 0. Read in a, b, c and use the quadratic formula. If the discriminant is negative, display a message stating that there are no solutions.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {  
      
    //Declaring variables
    int a, b, c, insideQuad;
    
    //Getting user input
    cout << "For the quadratic equation a  *x * x + b * x + c = 0, enter values for a: ";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout <<  "c:";
    cin >> c;

    //calculate the inside of the quadratic(b^2 - 4 * a * c) and set to variable
    insideQuad = pow(b, 2) - (4 * a * c);

    if (insideQuad < 0) {
        cout << "There are no real solutions." << endl;
    } else if (a == 0) {
        cout << "There are no real solutions." << endl;
    } else if (insideQuad == 0) {
        cout << (-b + sqrt(insideQuad)) / 2 << endl;    
    } else {
        cout << "The solutions are " << (-b + sqrt(insideQuad)) / 2 << " and " << (-b - sqrt(insideQuad)) / 2 << "." << endl;
    } 
    return 0;
}