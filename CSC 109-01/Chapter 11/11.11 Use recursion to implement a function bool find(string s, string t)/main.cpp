/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Use recursion to implement a function bool find(string s, string t) that tests whether a string t is contained in a string s:

    *bool b = s.find("Mississippi!", "sip"); // Returns true
    *
    *Hint: If the text starts with the string you want to match, then you are done. If not, consider the sentence that you obtain by removing the first character.

*/

#include <iostream>
#include <string>

using namespace std;

/**
   Tests if a string is a subset of another.
   @param s a string
   @param t a string
   @return true if s contains t
*/
bool find(string s, string t) {
    if (s.length() < t.length()) {
        return false;
    } else if (s.substr(0, t.length()) == t) {
        return true;
    } else {
        s = s.substr(1, s.length());
        return find(s, t);
    } 
}

int main() {

    string firstStr, secondStr;
   
    cout << "Enter the first string: ";
    getline(cin, firstStr);

    cout << "Enter the second string: ";
    getline(cin, secondStr);
   
    bool exists = find(firstStr, secondStr);
   
    if (exists) {
        cout << "The substring " << secondStr << " was found in " << firstStr << "." << endl; 
    } else {
        cout << "The substring " << secondStr << " was not found in " << firstStr << "." << endl;
    }
    
    return 0;
}
