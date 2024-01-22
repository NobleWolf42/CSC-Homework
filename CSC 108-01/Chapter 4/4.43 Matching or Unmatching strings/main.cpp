/*
Write a program that compares two strings given as input. Ask the users whether they want to run matching or unmatching two strings. if the users select matching, output the number of characters that match in each string position and the matching string. Otherwise, output the number of unmatched characters and unmatched string. The output should use the correct verb (match vs matches) according to the character count.

Ex: If the input is:

    *crash crush

the output is:

    *4 characters match - crsh

Ex: If the input is:

    *cat catnip

the output is:

    *3 characters match - cat

Ex: If the input is:

    *mall saw

the output is:

    *1 character matches - a

Ex: If the input is:

    *apple orange

the output is:

    *0 characters match

Ex: If the input is:

    *crash crush

the output is:

    *4 characters match - a u

Ex: If the input is:

    *cat catnip

the output is:

    *3 characters unmatched - nip

Ex: If the input is:

    *mall saw

the output is:

    *1 character matches - mll sw

Ex: If the input is:

    *apple orange

the output is:

    *0 characters match - apple orange

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring variables
    string toMatch, word1, word2, result = "";
    int match = 0, i = 0;

    //Getting user input
    cin >> toMatch;
    cin >> word1;
    cin >> word2;

    if (toMatch == "match") {
        //Checking for matching letters
        while (i < word1.length() && i < word2.length()) {
            if (word1[i] == word2[i]) {
                match++;
                result += word1[i];
            }
            i++;
        }

        if (match == 1) {
            cout << match << " character matches - " << result << endl;
        } else if (match == 0) {
            cout << match << " characters match" << endl;
        }else {
            cout << match << " characters match - " << result << endl;
        }
    } else {
        while (i < word1.length() || i < word2.length()) {
            if (word1[i] != word2[i]) {
                match++;
                result += word1[i];
                result += word2[i];
            }
            i++;
        }

        if (match == 1) {
            cout << match << " character unmatched - " << result << endl;
        } else if (match == 0) {
            cout << match << " characters unmatched" << endl;
        } else if (result == "") {
            cout << match << " characters match - " << word1 << " " << word2 << endl;
        } else {
            cout << match << " characters unmatched - " << result << endl;
        }
    }

    return 0;
}