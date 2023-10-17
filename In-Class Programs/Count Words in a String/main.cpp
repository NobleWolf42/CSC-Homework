#include <iostream>
#include<string>

using namespace std;

int main () {
    string s;
    char cont;
    int currentPos, wordCount;

    wordCount = 1;
    currentPos = 0;
    while (cont == 'y') {
        cout << "Please enter a string: " << endl;
        cin >> s;
        cout << endl;

        while (s.find(' ') != string::npos) {
            s.replace(s.find(' '), 1, "");
            wordCount ++;
        };

        cout << "Continue? (y/n)" << endl;
        cin >> cont;
        cout << endl;
    };
}