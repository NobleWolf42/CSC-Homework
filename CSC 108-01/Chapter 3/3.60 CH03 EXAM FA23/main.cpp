/*
A user is asked to type a caption for a photo in a web form's text field. If the caption didn't end with a punctuation mark (. ! ?), a period should automatically be added. A common error is to end with a comma, which should be replaced by a period. Another common error is to end with two periods, which should be changed to one period (however, ending with three periods (or more) indicates ellipses so should be kept as is). The corrected caption is output.

If the input is "I like pie", the output is "I like pie." If the input is "I like pie!", the output remains "I like pie!" If the input is "Coming soon…", the output remains "Coming soon…"

Hints:

    Start by checking for ! or ? which don't require any action.

    Then check for , which requires the simple action of replacing by a period.

    Then check for two ending periods (making sure the caption is at least 2 characters long). If found, check for three ending periods (making sure the caption is at least 3 characters long), in which case no action is required. Otherwise, remove the last period.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string userInput;
    int strLen;

    //Getting user input
    getline(cin, userInput);
    
    //Setting length of string
    strLen = userInput.length() - 1;
    
    //Modifying input
    if (userInput[strLen] == '?') {
        cout << userInput << endl;
    } else if (userInput[strLen] == '!') {
        cout << userInput << endl;
    } else if (userInput[strLen] == '.') {
        if (userInput[strLen - 1] == '.' && userInput[strLen - 2] != '.') {
            userInput.replace (strLen - 1, 2, ".");
            cout << userInput << endl;
        } else {
            cout << userInput << endl;
        }
    } else {
        cout << userInput << "." << endl;
    };



    /* Change the punctuation according to the instruction above */

    return 0;
}