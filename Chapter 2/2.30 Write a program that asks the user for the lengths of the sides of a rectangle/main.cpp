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
    double perimeter;
    double diagonal;

    //Getting user input
    cout << "Enter the height of the rectangle: ";
    cin >> height;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    //Finding area
    double area = height * width;

    //Printing area
    cout << "The area of a rectangle with height of " << height << " and width of " << width << " is " << area << "." << endl; 

    //Finding perimeter
    perimeter = 2 * height + 2 * width;

    //Printing perimeter
    cout << "The perimeter of a rectangle with height of " << height << " and width of " << width << " is " << perimeter << "." << endl;

    //Finding diagonal
    diagonal = sqrt(height * height + width * width); 
    
    //Printing diagonal
    cout << "The diagonal of a rectangle with height of " << height << " and width of " << width << " is " << diagonal << "." << endl;
    return 0; 
}