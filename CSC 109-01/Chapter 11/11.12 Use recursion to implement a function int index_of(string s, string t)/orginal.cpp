/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Use recursion to implement a function int index_of(string s, string t) that returns the starting position of the first substring of the string s that matches t. Return –1 if t is not a substring of s. For example,

    *int n = s.index_of("Mississippi!", "sip"); // Returns 6
    *
    *Hint: This is a bit trickier than the previous exercise, because you need to keep track of how far the match is from the beginning of the sentence. Make that value a parameter of a helper function.
*/#include <iostream>
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
   // TODO
   
   // Hint: Use substring, length and recursion
}

/**
   Attempts to locate substring t within string s.
   @param s a string
   @param t a string
   @return index of first match; otherwise, -1 if not found
*/
int index_of(string s, string t) {  
   // Call the helper function here
}

int main() {  
   
   // Create string variable(s)
   
   // Print Expected, "Enter the first string: "
   // Print Expected, "Enter the second string: "
   
   // Remember to allow users to input

   // Create another varible and set it equal to a function

   /* 
   IF the string is what? then Print Expected, 
   "The substring " (print second string here) " was found at position " (print position here) ".\n" 
   */
   
   /* 
   If the string is NOT then Print Expected, 
   "The substring " (print second string here) " was not found in " (print first string here) ".\n" 
   */

   return 0;
}
