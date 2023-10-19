/*
Many user-created passwords are simple and easy to guess. Write a program that takes a simple password and makes it stronger by replacing characters using the key below, and by appending "!" to the end of the input string.

i becomes 1
a becomes @
m becomes M
B becomes 8
s becomes $

Ex: If the input is:

    *mypassword

the output is:

    *Myp@$$word!

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
   
    //Declaring variables
    string userInput;
    int i;

    //Getting user input
    cin >> userInput;

    //Modifying user input
    for (i = 0; i < userInput.length(); ++i) {
        switch (userInput[i]) {
            case 'i':
                userInput.replace(i, 1, "1");
                break;
            case 'a':
                userInput.replace(i, 1, "@");
                break;
            case 'm':
                userInput.replace(i, 1, "M");
                break;
            case 'B':
                userInput.replace(i, 1, "8");
                break;
            case 's':
                userInput.replace(i, 1, "$");
                break;        
            default:
                break;
        }
    }

    userInput.append("!");

    cout << userInput << endl;

    return 0;
}