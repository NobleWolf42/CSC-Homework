/*
(1) Use getline() to get a line of user input into a string. Output the line. (3 pts)

Ex: (User input in bold)

    *Enter text:
    *<b>IDK if I'll go. It's my BFF's birthday.</b>
    *You entered: IDK if I'll go. It's my BFF's birthday.

(2) Search the string (using find()) for common abbreviations and print a list of each found abbreviation along with its decoded meaning. (3 pts)

Ex: (User input in bold)

    *Enter text:
    *<b>IDK if I'll go. It's my BFF's birthday.</b>
    *You entered: IDK if I'll go. It's my BFF's birthday. 
    *BFF: best friend forever
    *IDK: I don't know

Support these abbreviations:

BFF -- best friend forever
IDK -- I don't know
JK -- just kidding
TMI -- too much information
TTYL -- talk to you later
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    //Declaring variables
    string userInput;

    //Getting user input
    cout << "Enter text:" << endl;
    getline(cin, userInput);

    //Printing result
    cout << "You entered: " << userInput << endl;
    if (userInput.find("BFF") < 8446744073709551615) {
        cout << "BFF: best friend forever" << endl;
    }
    if (userInput.find("IDK") < 8446744073709551615) {
        cout << "IDK: I don't know" << endl;
    }
    if (userInput.find("JK") < 8446744073709551615) {
        cout << "JK: just kidding" << endl;
    }
    if (userInput.find("TMI") < 8446744073709551615) {
        cout << "TMI: too much information" << endl;
    }
    if (userInput.find("TTYL") < 8446744073709551615) {
        cout << "TTYL: talk to you later" << endl;
    }
    

    return 0;
}