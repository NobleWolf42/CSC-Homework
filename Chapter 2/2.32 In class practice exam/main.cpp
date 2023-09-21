/*
Write a program that asks the user for the length and width of a rectangle. Then print:
• The area and perimeter of the rectangle
• The length of the diagonal (use the Pythagorean theorem):
• Set all of the output values to two decimal places
*/
#include <iostream> 
#include <cmath> 
#include <iomanip>

using namespace std; 

int main() {

    //Declaring variables
    double height;
    double width;
    double area;
    double perimeter;

    //Getting user input
    cout << "Enter the height of the rectangle: ";
    cin >> height;
    cout << height << endl << "Enter the width of the rectangle: ";
    cin >> width;

    //Finding the area of the rectangle
    area = width * height;

    //Setting all outputs to 2 decimal points
    cout << width << endl << fixed << setprecision(2);
    
    //Printing the area of the rectangle
    cout << "The area of a rectangle with height of " << height << " and width of " << width << " is " << area << "." << endl; 

    //Finding the perimeter
    perimeter = 2 * width + 2 * height;

    //Printing the perimeter of the rectangle
    cout << "The perimeter of a rectangle with height of " << height << " and width of " << width << " is " << perimeter << "." << endl;
  
    //Printing diagonal
    cout << "The diagonal of a rectangle with height of " << height << " and width of " << width << " is " << sqrt(pow(height, 2) + pow(width, 2)) << "." << endl;

    return 0; 
}