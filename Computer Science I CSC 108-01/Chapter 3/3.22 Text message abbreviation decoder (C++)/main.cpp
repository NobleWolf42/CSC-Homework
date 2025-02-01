/*
(1) If a user's input string matches a known text message abbreviation, output the unabbreviated form, else output: Unknown. Support two abbreviations: LOL -- laughing out loud, and IDK -- I don't know. (4 pts)

Sample input/output: (User Input in Bold)

    *Input an abbreviation:
    *<b>LOL</b>
    *laughing out loud

(2) Expand to also decode these abbreviations. (3 pts)

    BFF -- best friends forever
    IMHO -- in my humble opinion
    TMI -- too much information
*/
#include <iostream>
#include <string> // Note: This library is needed to use the string type
using namespace std;

int main() {

    //Declaring variables
    string userInput;

    //Getting user input
    cout << "Input an abbreviation:" << endl;
    getline(cin, userInput);

    //Printing result
    if (userInput == "LOL") {
        cout << "laughing out loud" << endl;
    } else if (userInput == "IDK") {
        cout << "I don't know" << endl;
    } else if (userInput == "BFF") {
        cout << "best friends forever" << endl;
    } else if (userInput == "IMHO") {
        cout << "in my humble opinion" << endl;
    } else if (userInput == "TMI") {
        cout << "too much information" << endl;
    } else {
        cout << "Unknown" << endl;
    }


    return 0;
}