/*
An acronym is a word formed from the initial letters of words in a set phrase. Define a function named CreateAcronym that takes a string parameter and returns the acronym of the string parameter. Append a period (.) after each letter in the acronym. If a word begins with a lower case letter, don't include that letter in the acronym. Then write a main program that reads a phrase from input, calls CreateAcronym() with the input phrase as argument, and outputs the returned acronym. Assume the input has at least one upper case letter.

Ex: If the input is:

    *Institute of Electrical and Electronics Engineers

the output should be:

    *I.E.E.E.

Ex: If the input is:

    *Association for computing MACHINERY

the output should be:

    *A.M.

Although the letters ACHINERY in MACHINERY are upper case, those letters are omitted for being a part of the word MACHINERY.

The program must define and call a function:
string CreateAcronym(string userPhrase)

Hint: Use isupper() to check if a letter is upper case.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string CreateAcronym(string userPhrase) {
    string word = "", output;
    
    for (size_t i = 0; i < userPhrase.length(); ++i) {
        if (userPhrase[i] == ' ' || i == userPhrase.length() - 1) {
            if (isupper(word[0])) {
                output = output + word[0] + ".";
            }
            word = "";
        } else {
            word = word + userPhrase[i];
        }
    }
    return output;
}

int main() {
    
    //Declaring variables
    string uIn;

    //Getting user input
    getline(cin, uIn);

    //Outputting results
    cout << CreateAcronym(uIn) << endl;

    return 0;
}