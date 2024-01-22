/*
Write a program that prompts the user for a measurement in meters and then converts it to miles, feet, and inches.
*/
#include <iostream> 

using namespace std; 

int main() {

    //Declaring constants
    const double METERS_PER_MILE = 1609;
    const double METERS_PER_FOOT = 0.305;
    const double METERS_PER_INCH = 0.0254;
    
    //Declaring variables
    double meters;

    //Getting user input
    cout << "Please enter length in meters: ";
    cin >> meters;

    //Convert to miles, feet, and inches
    double miles = meters / METERS_PER_MILE; 
    double feet =  meters / METERS_PER_FOOT;
    double inches = meters / METERS_PER_INCH;

    cout << meters << " meters is equivalent to " << miles << " miles, or " << feet << " feet, or " << inches << " inches." << endl;
    return 0; 
}