/*
(1) Prompt the user to input a wall's height and width. Calculate and output the wall's area. (2 pts) (User Inputs in Bold)

Note: This zyLab outputs a newline after each user-input prompt. For convenience in the examples below, the user's input value is shown on the next line, but such values don't actually appear as output when the program runs.

    *Enter wall height (feet):
    *<b>12.0/<b>
    *Enter wall width (feet):
    *<b>15.0</b>
    *Wall area: 180 square feet

(2) Extend to also calculate and output the amount of paint in gallons needed to paint the wall. Assume a gallon of paint covers 350 square feet. Store this value using a const double variable. (2 pts) (User Inputs in Bold)

    *Enter wall height (feet):
    *<b>12.0/<b>
    *Enter wall width (feet):
    *<b>15.0</b>
    *Wall area: 180 square feet
    *Paint needed: 0.514286 gallons

(3) Extend to also calculate and output the number of 1 gallon cans needed to paint the wall. Hint: Use a math function to round up to the nearest gallon. (2 pts) (User Inputs in Bold)

    *Enter wall height (feet):
    *<b>12.0/<b>
    *Enter wall width (feet):
    *<b>15.0</b>
    *Wall area: 180 square feet
    *Paint needed: 0.514286 gallons
    *Cans needed: 1 can(s)

*/

#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
using namespace std;

int main() {
   double wallHeight;
   double wallWidth;
   double wallArea;
   
   cout << "Enter wall height (feet):" << endl;
   cin  >> wallHeight;
   
   wallWidth = 10.0;               // FIXME (1): Prompt user to input wall's width
   
   // Calculate and output wall area
   wallArea = 0.0;                 // FIXME (1): Calculate the wall's area
   cout << "Wall area: " << endl;  // FIXME (1): Finish the output statement
   
   
   // FIXME (2): Calculate and output the amount of paint in gallons needed to paint the wall

   // FIXME (3): Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer

   return 0;
}
