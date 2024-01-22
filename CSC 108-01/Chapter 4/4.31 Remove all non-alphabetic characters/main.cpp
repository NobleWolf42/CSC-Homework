/*
Write a program that removes all non alpha characters from the given input.

Ex: If the input is:

    *-Hello, 1 world$!

the output is:

    *Helloworld

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
   
    //Declaring variables
    string userInput;
    int i;

    //Getting user input
    getline(cin, userInput);

    //Removing non alpha charters
    for (i = 0; i < userInput.length(); ++i) {
        if (!isalpha(userInput[i])) {
            i --;
        }
    }

    cout << userInput << endl;

    return 0;
}