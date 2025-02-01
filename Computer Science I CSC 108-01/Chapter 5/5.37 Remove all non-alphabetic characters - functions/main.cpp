/*
Write a program that removes all non-alphabetic characters from the given input.

Ex: If the input is:

    *-Hello, 1 world$!

the output is:

    *Helloworld

Your program must define and call the following function that takes a string as a parameter and returns the string without any non-alphabetic characters.
string RemoveNonAlpha(string userString)
*/
#include <iostream>
#include <string>
using namespace std;

string RemoveNonAlpha(string userString) {
    string output;

    for (size_t i = 0; i < userString.length(); ++i) {
        if (isalpha(userString[i])) {
            output += userString[i];
        }
    }

    return output;
}

int main() {
   
    string uIn;

    getline(cin, uIn);

    cout << RemoveNonAlpha(uIn) << endl;

    return 0;
}