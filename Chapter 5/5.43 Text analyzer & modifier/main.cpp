/*
1) Prompt the user to enter a string of their choosing. Output the string. (1 pt)

Ex:

    *Enter a sentence or phrase:
    *The only thing we have to fear is fear itself.

    *You entered: The only thing we have to fear is fear itself.

(2) Complete the GetNumOfCharacters() function, which returns the number of characters in the user's string. We encourage you to use a for loop in this function. (2 pts)

(3) In main(), call the GetNumOfCharacters() function and then output the returned result. (1 pt)

(4) Implement the OutputWithoutWhitespace() function. OutputWithoutWhitespace() outputs the string's characters except for whitespace (spaces, tabs). Note: A tab is '\t'. Call the OutputWithoutWhitespace() function in main(). (2 pts)

Ex:

    *Enter a sentence or phrase:
    *The only thing we have to fear is fear itself.

    *You entered: The only thing we have to fear is fear itself.

    *Number of characters: 46
    *String with no whitespace: Theonlythingwehavetofearisfearitself.

*/
#include <iostream>
#include <string>
using namespace std;

//Returns the number of characters in usrStr
int GetNumOfCharacters(const string usrStr) {
    int output = 0;
    for (size_t i = 0; i < usrStr.length(); ++i) {
        output++;
    }
    return output;
}

void OutputWithoutWhitespace(string& uStr) {
    for (size_t i = 0; i < uStr.length(); ++i) {
        if (uStr[i] == ' ' || uStr[i] == '\t') {
            uStr.erase(i, 1);
            i--;
        }
    }
}

int main() {

    //Declaring variables
    string uIn;

    //Getting input
    cout << "Enter a sentence or phrase:" << endl;
    getline(cin, uIn);

    //Outputting results
    cout << endl << "You entered: " << uIn << endl;
    cout << endl << "Number of characters: " << GetNumOfCharacters(uIn) << endl;
    OutputWithoutWhitespace(uIn);
    cout << "String with no whitespace: " << uIn << endl;

    return 0;
}