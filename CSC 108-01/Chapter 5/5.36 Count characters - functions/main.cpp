/*
Write a program whose input is a character and a string, and whose output indicates the number of times the character appears in the string. The output should include the input character and use the plural form, n's, if the number of times the characters appears is not exactly 1.

Ex: If the input is:

    *n Monday

the output is:

    *1 n

Ex: If the input is:

    *z Today is Monday

the output is:

    *0 z's

Ex: If the input is:

    *n It's a sunny day

the output is:

    *2 n's

Case matters. n is different than N.
Ex: If the input is:

    *n Nobody

the output is:

    *0 n's

The program must define and call the following function that takes the input string and character as parameters, and returns the number of times the input character appears in the input string.
int CalcNumCharacters(string userString, char userChar)
*/
#include <iostream>
#include <string>
using namespace std;

int CalcNumCharacters(string userString, char userChar) {
    int count = 0;
    
    for (size_t i = 0; i < userString.length(); ++i) {
        if (userString[i] == userChar) {
            count++;
        }
    }
    return count;
}

int main() {
    
    //Declaring variables
    int a;
    char uC;
    string uS;

    //Getting user input
    cin >> uC;
    getline(cin, uS);

    //Running function and outputting results
    a = CalcNumCharacters(uS, uC);
    if (a = 1) {
        cout << CalcNumCharacters(uS, uC) << " " << uC << endl;
    } else {
        cout << CalcNumCharacters(uS, uC) << " " << uC << "'s" << endl;
    }

    return 0;
}