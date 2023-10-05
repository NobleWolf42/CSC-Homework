/*Summary: Given integer values for red, green, and blue, subtract the gray from each value.

Computers represent color by combining the sub-colors red, green, and blue (rgb). Each sub-color's value can range from 0 to 255. Thus (255, 0, 0) is bright red, (130, 0, 130) is a medium purple, (0, 0, 0) is black, (255, 255, 255) is white, and (40, 40, 40) is a dark gray. (130, 50, 130) is a faded purple, due to the (50, 50, 50) gray part. (In other words, equal amounts of red, green, blue yield gray).

Given values for red, green, and blue, remove the gray part.

Ex: If the input is:

    *130 50 130

the output is:

    *80 0 80

Find the smallest value, and then subtract it from all three values, thus removing the gray.
Note: This page (https://www.mathsisfun.com/hexadecimal-decimal-colors.html) converts rgb values into colors.
*/
#include <iostream>
using namespace std;

int main() {

    //Declaring variables
    int c1, c2, c3, lowest;

    //Getting user input
    cin >> c1;
    cin >> c2;
    cin >> c3;

    //Determining grey and setting it to lowest
    if (c1 <= c2 && c1 <= c3) {
        lowest = c1;
    } else if (c2 <= c1 && c2 <= c3) {
        lowest = c2;
    } else {
        lowest = c3;
    }

    //Removing grey
    c1 = c1 - lowest;
    c2 = c2 - lowest;
    c3 = c3 - lowest;

    //Printing result
    cout << c1 << " " << c2 << " " << c3 << endl;

    return 0;
}