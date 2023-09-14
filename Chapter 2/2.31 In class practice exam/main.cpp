/*
Write a program that asks the user for the lengths of the sides of a rectangle. Then print:
• The area and perimeter of the rectangle
• The length of the diagonal (use the Pythagorean theorem):
*/
#include <iostream> 
#include <cmath> 

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
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    //Finding the area of the rectangle
    area = width * height;
    
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