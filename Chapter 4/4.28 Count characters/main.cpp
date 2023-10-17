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

Case matters.

Ex: If the input is:

    *n Nobody

the output is:

    (0 n's

n is different than N.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    //Declaring variables
    string userStr;
    char userChar;
    int i, count;

    cin >> userChar;
    getline(cin, userStr);

    count = 0;

    for (i = 0; i < userStr.length(); ++i) {
        if (userStr[i] == userChar) {
            count ++;
        }
    }

    if (count == 1) {
        cout << count << " " << userChar << endl;
    } else {
        cout << count << " " << userChar << "'s" << endl;
    }
    return 0;
}