/*
Numerous engineering and scientific applications require finding solutions to a set of equations. Ex: 8x + 7y = 38 and 3x - 5y = -1 have a solution x = 3, y = 2. Given integer coefficients of two linear equations with variables x and y, use brute force to find an integer solution for x and y in the range -10 to 10.

Ex: If the input is:

    *8 7 38
    *3 -5 -1

the output is:

    *x = 3, y = 2

Use this brute force approach:

    *For every value of x from -10 to 10
    *   For every value of y from -10 to 10
    *       Check if the current x and y satisfy both equations. If so, output the solution, and finish.

Ex: If no solution is found, output:

    *There is no solution

Assume the two input equations have no more than one solution.

Note: Elegant mathematical techniques exist to solve such linear equations. However, for other kinds of equations or situations, brute force can be handy.
*/
#include <iostream>
using namespace std;

int main() {

    //Declaring variables
    int cx1, cy1, eq1, cx2, cy2, eq2, x, y;
    bool solution;

    //getting user input
    cin >> cx1;
    cin >> cy1;
    cin >> eq1;
    cin >> cx2;
    cin >> cy2;
    cin >> eq2;

    //Brute forcing equation
    solution = false;
    for (x = -10; x < 11; ++x) {
        for (y = -10; y < 11; ++y) {
            if (((cx1 * x) + (cy1 * y) == eq1) && ((cx2 * x) + (cy2 * y) == eq2)) {
                cout << "x = " << x << ", y = " << y << endl;
                x = 11;
                y = 11;
                solution = true;
            }
        }
    }

    if (!solution) {
        cout << "There is no solution" << endl;
    }

    return 0;
}