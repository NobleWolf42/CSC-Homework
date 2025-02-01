/*
Write a program that reads in three strings and sorts them lexicographically. (User input in bold)

    *Enter three strings: <b>Charlie Able Baker</b>
    *Able
    *Baker
    *Charlie

*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    //Declaring variables
    string input, str1, str2, str3, out1, out2, out3;
    char char1, char2, char3;
    int pos1, pos2;

    //Getting user input
    cout << "Please enter three strings: ";
    getline(cin, input);

    //Splitting string
    pos1 = input.find(' ');
    pos2 = input.find(' ', pos1 + 1);
    str1 = input.substr(0, pos1);
    str2 = input.substr(pos1 + 1, pos2 - pos1 - 1);
    str3 = input.substr(pos2 + 1);
    char1 = str1.at(0);
    char2 = str2.at(0);
    char3 = str3.at(0);

    if (char1 > char2) {
        if (char1 > char3) {
            out1 = str1;
            if (char2 > char3) {
                out2 = str2;
                out3 = str3;
            } else {
                out2 = str3;
                out3 = str2;
            }
        } else {
            out1 = str3;
            out2 = str1;
            out3 = str2;
        }
    } else {
        if (char1 > char3) {
            out1 = str2;
            out2 = str1;
            out3 = str3;
        } else {
            out3 = str1;
            if (char2 > char3) {
                out1 = str2;
                out2 = str3;
            } else {
                out1 = str3;
                out2 = str2;
            }
        }
    }

    //Print results
    cout << endl << out3 << endl << out2 << endl << out1 << endl;
    return 0;
}