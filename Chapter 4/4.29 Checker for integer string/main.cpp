/*
Forms often allow a user to enter an integer. Write a program that takes in a string representing an integer as input, and outputs Yes if every character is a digit 0-9.

Ex: If the input is:

    *1995

the output is:

    *Yes

Ex: If the input is:

    *42,000

or

    *1995!

the output is:

    *No

Hint: Use a loop and the isdigit() function (don't forget to include the cctype library).
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string userString;
    int i;
    bool isNumber;
    
    //Getting user input
    cin >> userString;

    isNumber = true;
    for (i = 0; i < userString.length(); ++i) {
        if (!isdigit(userString[i])) {
            isNumber = false;
            i = userString.length();
        }
    }

    if (isNumber) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}