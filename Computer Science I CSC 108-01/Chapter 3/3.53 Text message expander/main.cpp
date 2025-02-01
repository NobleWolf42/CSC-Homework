/*
(1) Get a line of text from the user. Output that line. (1 pt)

Ex: (User input in bold)

    *Enter text:
    *<b>IDK how that happened. TTYL. </b>
    *You entered: IDK how that happened. TTYL.

(2) Output the line again, this time expanding common text message abbreviations. (5 pts)

Ex: (User input in bold)

    *Enter text:
    *<b>IDK how that happened. TTYL. </b>
    *You entered: IDK how that happened. TTYL.
    *Expanded: I don't know how that happened. talk to you later.

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
        userInput.replace (userInput.find("BFF"), 3, "best friend forever");
    }
    if (userInput.find("IDK") < 8446744073709551615) {
        userInput.replace (userInput.find("IDK"), 3, "I don't know");
    }
    if (userInput.find("JK") < 8446744073709551615) {
        userInput.replace (userInput.find("JK"), 2, "just kidding");
    }
    if (userInput.find("TMI") < 8446744073709551615) {
        userInput.replace (userInput.find("TMI"), 3, "too much information");
    }
    if (userInput.find("TTYL") < 8446744073709551615) {
        userInput.replace (userInput.find("TTYL"), 4, "talk to you later");
    }
    cout << "Expanded: " << userInput << endl;
    

    return 0;
}