/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Use recursion to implement a function int index_of(string s, string t) that returns the starting position of the first substring of the string s that matches t. Return –1 if t is not a substring of s. For example,

    *int n = s.index_of("Mississippi!", "sip"); // Returns 6
    *
    *Hint: This is a bit trickier than the previous exercise, because you need to keep track of how far the match is from the beginning of the sentence. Make that value a parameter of a helper function.
*/

#include <iostream>
#include <string>

using namespace std;

/**
   Attempts to locate substring t within string s.
   @param s a string
   @param t a string
   @param n the number of characters previously matched
   @return offset index of first match; otherwise, -1 if not found
*/

int index_of_helper(string s, string t, int n) {

    cout << s.substr(n, t.length()) << endl;
   
    if (s.substr(n, t.length()) == t) {
        return n;
    } else if ((s.length() - n) < t.length()) {
        return -1;
    } else {
        return index_of_helper(s, t, (n + 1));
    }

}

/**
   Attempts to locate substring t within string s.
   @param s a string
   @param t a string
   @return index of first match; otherwise, -1 if not found
*/

int index_of(string s, string t) {  
    return index_of_helper(s, t, 0);
}

int main() {

    string str1, str2;
    
    cout << "Enter the first string: " << endl;
    getline(cin, str1);
    cout << "Enter the second string: " << endl;
    getline(cin, str2);

    int ss = index_of(str1, str2);

    if (ss >= 0) {
        cout << "The substring " << str2 << " was found at position " << ss << ".\n"; 
    } else {
        cout << "The substring " << str2 << " was not found in " << str1 << ".\n";
    }

    return 0;
}
