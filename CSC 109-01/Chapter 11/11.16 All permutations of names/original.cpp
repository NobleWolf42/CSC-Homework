/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Write a program that lists all ways people can line up for a photo (all permutations of a list of strings). The program will read a list of one word names into vector nameList (until -1), and use a recursive function to create and output all possible orderings of those names separated by a comma, one ordering per line.

When the input is:

    *Julia Lucas Mia -1

then the output is (must match the below ordering):

    *Julia, Lucas, Mia 
    *Julia, Mia, Lucas 
    *Lucas, Julia, Mia 
    *Lucas, Mia, Julia 
    *Mia, Julia, Lucas 
    *Mia, Lucas, Julia 
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(const vector<string> &permList, const vector<string> &nameList) {

}

int main() {
   vector<string> nameList;
   vector<string> permList;
   string name;

   // TODO: Read a list of names into nameList; stop when -1 is read. Then call recursive function.
   
   return 0;
}
