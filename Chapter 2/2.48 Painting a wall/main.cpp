/*
Program Specifications Write a program to calculate the cost to paint a wall. Amount of required paint is based on the wall area. Total cost includes paint and sales tax.

Note: This program is designed for incremental development. Complete each step and submit for grading before starting the next step. Only a portion of tests pass after each step but confirm progress.

Step 1 (2 pts). Read from input wall height, wall width, and cost of one paint can (doubles). Calculate and output the wall's area to one decimal place using cout << fixed << setprecision(1); once before all other cout statements. Submit for grading to confirm 1 test passes.

Ex: If the input is:

    *12.0 15.0 29.95

the output is:

    *Wall area: 180.0 sq ft
    
Step 2 (2 pts). Calculate and output the amount of paint needed to three decimal places. One gallon of paint covers 350 square feet. Submit for grading to confirm 2 tests pass.

Ex: If the input is:

    *12.0 15.0 29.95

the output is:

    *Wall area: 180.0 sq ft
    *Paint needed: 0.514 gallons

Step 3 (2 pts). Calculate and output the number of 1 gallon cans needed to paint the wall. Extra paint may be left over. Hint: Use ceil() to round up to the nearest gallon and convert to an integer. Submit for grading to confirm 4 tests pass.

Ex: If the input is:

    *12.0 15.0 29.95

the output is:

    *Wall area: 180.0 sq ft
    *Paint needed: 0.514 gallons
    *Cans needed: 1 can(s)

Step 4 (4 pts). Calculate and output the paint cost, sales tax of 7%, and total cost. Dollar values are output with two decimal places. Submit for grading to confirm all tests pass.

Ex: If the input is:

    *8.0 8.0 49.20

the output is:

    *Wall area: 64.0 sq ft
    *Paint needed: 0.183 gallons
    *Cans needed: 1 can(s)
    *Paint cost: $49.20
    *Sales tax: $3.44
    *Total cost: $52.64

*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    //Declaring variables
    double wallHeight;
    double wallWidth;
    double paintPrice;
    double wallArea;
    double paintGallons;
    double actualCost;
    double actualTax;
    
    //Getting user input
    cin  >> wallHeight >> wallWidth >> paintPrice;
    
    //Finding and Printing the wall area
    wallArea = wallHeight * wallWidth;
    cout << fixed << setprecision(1);
    cout << "Wall area: " << wallArea << " sq ft" << endl;
   
   
    //Finding and Printing the amount of paint needed
    paintGallons = wallArea / 350;
    cout << fixed << setprecision(3);
    cout << "Paint needed: " << paintGallons << " gallons" << endl;

    //Finding and printing the number of paint cans needed
    cout << fixed << setprecision(0);
    cout << "Cans needed: " << ceil(paintGallons) << " can(s)" << endl;

    //Finding and printing costs
    actualCost = ceil(paintGallons) * paintPrice;
    actualTax = (actualCost / 100) * 7;
    cout << fixed << setprecision(2);
    cout << "Paint cost: $" << actualCost << endl;
    cout << "Sales tax: $" << actualTax << endl;
    cout << "Total cost: $" << actualCost + actualTax << endl;
    return 0;
}