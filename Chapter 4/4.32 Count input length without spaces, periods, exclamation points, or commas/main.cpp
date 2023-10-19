/*
Given a line of text as input, output the number of characters excluding spaces, periods, exclamation points, or commas.

Ex: If the input is:

    *Listen, Mr. Jones, calm down.

the output is:

    *21

Note: Account for all characters that aren't spaces, periods, exclamation points, or commas (Ex: "r", "2", "?").
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string userText;
    int charCount, i;
    
    //Getting user input
    getline(cin, userText);

    charCount = 0;
    for (i = 0; i < userText.length(); ++i) {
        switch (userText[i]) {
            case ' ':
            case '.':
            case '!':
            case ',':
                break;
            default:
                charCount ++;
                break;
        }
    }

    cout << charCount << endl;;

    return 0;
}