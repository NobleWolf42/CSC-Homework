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

void PrintAllPermutations(vector<string> &permList, const vector<string> &nameList);
void recursion(vector<string> &permList, const vector<string> &nameList, size_t i);

void print(vector<string> &permList, size_t i) {
    if (i == permList.size() - 1) {
        cout << permList.at(i) << endl;
    } else {
        cout << permList.at(i) << ", ";
        print(permList, i + 1);
    }
}

void recursion(vector<string> &permList, const vector<string> &nameList, size_t i) {
    
    if (i >= nameList.size()) {
        return;
    }
    
    vector<string> temp;

    temp = nameList;

    permList.push_back(temp[i]);
            
    temp.erase(temp.begin() + i);

    PrintAllPermutations(permList, temp);

    permList.pop_back();
    
    recursion(permList, nameList, i + 1);

}

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(vector<string> &permList, const vector<string> &nameList) {
    
    vector<string> temp;

    if (nameList.size() == 0) {
        print(permList, 0);        
    } else {
        recursion(permList, nameList, 0);
    }
}

void readIn(vector<string> &nameList) {
    string name;
    cin >> name;
    if (name == "-1") {
        return;
    } else {
        nameList.push_back(name);
        readIn(nameList);
    }
}

int main() {
    vector<string> nameList;
    vector<string> permList;

    readIn(nameList);

    PrintAllPermutations(permList, nameList);
    
    return 0;
}
