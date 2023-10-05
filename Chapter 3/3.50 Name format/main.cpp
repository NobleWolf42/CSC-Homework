/*
Many documents use a specific format for a person's name. Write a program whose input is:

firstName middleName lastName

and whose output is:

lastName, firstInitial.middleInitial.

Ex: If the input is:

    *Pat Silly Doe

the output is:

    *Doe, P.S.

If the input has the form: firstName lastName

the output is:

lastName, firstInitial.

Ex: If the input is:

    *Julia Clark

the output is:

    *Clark, J.

*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    //Declaring variables
    string userInput, firstName, middleName, lastName;
    int pos1, pos2;
    char firstInital, middleInital;

    //Getting user input
    getline(cin, userInput);

    //Splitting up userInput
    pos1 = userInput.find(' ');
    pos2 = userInput.find(' ', pos1 + 1);
    firstName = userInput.substr(0, pos1);
    middleName = userInput.substr(pos1 + 1, pos2);
    lastName = userInput.substr(pos2 + 1);
    firstInital = firstName[0];
    middleInital = middleName[0];

    //Printing results
    if (pos2 < 1) {
        lastName = middleName;
        cout << lastName << ", " << firstInital << "." << endl;
    } else {
        cout << lastName << ", " << firstInital << "." << middleInital << "." << endl;
    }

    return 0;
}