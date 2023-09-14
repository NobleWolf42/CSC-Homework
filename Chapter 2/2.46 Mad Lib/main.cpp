/*
Mad Libs are activities that have a person provide various words, which are then used to complete a short story in unexpected (and hopefully funny) ways.

Complete the program to read the needed values from input, that the existing output statement(s) can use to output a short story.

Ex: If the input is:

    *Eric 12 cars Chipotle 

the output is:

    *Eric buys 12 different types of cars at Chipotle.

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string firstName;
    int wholeNumber;
    string pluralNoun;
    string genericLocation;
   
    //Getting user input
    cin >> firstName >> wholeNumber >> pluralNoun >> genericLocation;

    //Printing mad lib
    cout << firstName << " buys " << wholeNumber << " different types of " << pluralNoun << " at " << genericLocation << "." << endl;
    return 0;
}