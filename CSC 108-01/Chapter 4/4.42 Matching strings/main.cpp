/*
Write a program that compares two strings given as input. Output the number of characters that match in each string position. The output should use the correct verb (match vs matches) according to the character count.

Ex: If the input is:

    *crash crush

the output is:

    *4 characters match

Ex: If the input is:

    *cat catnip

the output is:

    *3 characters match

Ex: If the input is:

    *mall saw

the output is:

    *1 character matches

Ex: If the input is:

    *apple orange

the output is:

    *0 characters match

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string word1, word2;
    int match = 0, i = 0;

    //Getting user input
    cin >> word1;
    cin >> word2;

    //Checking for matching letters
    while (i < word1.length() && i < word2.length()) {
        if (word1[i] == word2[i]) {
            match++;
        }

        i++;
    }

    if (match == 1) {
        cout << match << " character matches" << endl;
    } else {
        cout << match << " characters match" << endl;
    }

    return 0;
}