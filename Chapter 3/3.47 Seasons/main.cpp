/*
Write a program that takes a date as input and outputs the date's season in the northern hemisphere. The input is a string to represent the month and an int to represent the day. Note: End with a newline.

Ex: If the input is:

    *April 11

the output is:

    *Spring

In addition, check if the string and int are valid (an actual month and day).

Ex: If the input is:

    *Blue 65

the output is:

    *Invalid 

The dates for each season in the northern hemisphere are:
Spring: March 20 - June 20
Summer: June 21 - September 21
Autumn: September 22 - December 20
Winter: December 21 - March 19
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    //Declaring variables
    string inputMonth;
    int inputDay;
    
    //Getting user input
    cin >> inputMonth;
    cin >> inputDay;
    
    //Ouput logic
    if (inputMonth == "February") {
        if (inputDay > 29 || inputDay < 1) {
            cout << "Invalid" << endl;
        } else {
            cout << "Winter" << endl;
        }
    } else if (inputMonth == "April" ||  inputMonth == "June" ||  inputMonth == "September" ||  inputMonth == "November") {
        if (inputDay > 30 || inputDay < 1) {
            cout << "Invalid" << endl;
        } else {
            if (inputMonth == "April") {
                cout << "Spring" << endl;
            } else if (inputMonth == "June") {
                if (inputDay > 20) {
                    cout << "Summer" << endl;
                } else {
                    cout << "Spring" << endl;
                }
            } else if (inputMonth == "September") {
                if (inputDay > 21) {
                    cout << "Autumn" << endl;
                } else {
                    cout << "Summer" << endl;
                }
            } else {
                cout << "Autumn" << endl;
            }
        }
    } else if (inputMonth == "January" || inputMonth == "March" || inputMonth == "May" || inputMonth == "July" || inputMonth == "August" || inputMonth == "October" || inputMonth == "December") {
        if (inputDay > 31 || inputDay < 1) {
            cout << "Invalid" << endl;
        } else {
            if (inputMonth == "January") {
                cout << "Winter" << endl;
            } else if (inputMonth == "March") {
                if (inputDay > 19) {
                    cout << "Spring" << endl;
                } else {
                    cout << "Winter" << endl;
                }
            } else if (inputMonth == "May") {
                cout << "Spring" << endl;
            } else if (inputMonth == "July" || inputMonth == "August") {
                cout << "Summer" << endl;
            } else if (inputMonth == "October") {
                cout << "Autumn" << endl;
            } else {
                if (inputDay > 20) {
                    cout << "Winter" << endl;
                } else {
                    cout << "Autumn" << endl;
                }
            }
        }
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}