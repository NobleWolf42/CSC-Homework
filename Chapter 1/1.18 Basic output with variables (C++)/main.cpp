/*
This zyLab activity prepares a student for a full programming assignment. Warm up exercises are typically simpler and worth fewer points than a full programming assignment, and are well-suited for an in-person scheduled lab meeting or as self-practice.


A variable like userNum can store a value like an integer. Extend the given program to print userNum values as indicated.

(1) Output the user's input. (2 pts) (User Input in Bold)

Note: This zyLab outputs a newline after each user-input prompt. For convenience in the examples below, the user's input value is shown on the next line, but such values don't actually appear as output when the program runs.

    *Enter integer:
    *<b>4</b>
    *You entered: 4

(2) Extend to output the input squared and cubed. Hint: Compute squared as userNum * userNum. (2 pts) (User Input in Bold)

    *Enter integer:
    *<b>4</b>
    *You entered: 4
    *4 squared is 16 
    *And 4 cubed is 64!!

(3) Extend to get a second user input into userNum2. Output sum and product. (1 pt) (User Input in Bold)

    *Enter integer:
    *<b>4</b>
    *You entered: 4
    *4 squared is 16 
    *And 4 cubed is 64!!
    *Enter another integer:
    *<b>5</b>
    *4 + 5 is 9
    *4 * 5 is 20

*/
#include <iostream>
using namespace std;

int main() {

    //Declaring variables
    int userNum0;
    int userNum1;

    //Getting user's first number
    cout << "Enter integer:" << endl;
    cin  >> userNum0;

    //Printing user's first number
    cout << "You entered: " << userNum0 << endl;

    //Printing user's first number squared and cubed
    cout << userNum0 << " squared is " << userNum0 * userNum0 << endl;
    cout << "And " << userNum0 << " cubed is " << userNum0 * userNum0 * userNum0 << "!!" << endl;

    //Getting user's second number
    cout << "Enter another integer:" << endl;
    cin  >> userNum1;

    //Printing user's first and second number added and multiplied together
    cout << userNum0 << " + " << userNum1 << " is " << userNum0 + userNum1 <<  endl;
    cout << userNum0 << " * " << userNum1 << " is " << userNum0 * userNum1 << endl;
    return 0;
}