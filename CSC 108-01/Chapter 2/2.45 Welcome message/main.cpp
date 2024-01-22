/*
Write a program that takes a first name as the input, and outputs a welcome message to that name.

Ex: If the input is:

Pat
the output is:

Hey Pat!
Welcome to zyBooks!
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string userName;
    
    //Getting user input
    cin >> userName;

    //Printing welcome message
    cout << "Hey " << userName << "!" << endl << "Welcome to zyBooks!" << endl;
   return 0;
}