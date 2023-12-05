/*
Write a program that reads a list of integers, and outputs whether the list contains all multiples of 10, no multiples of 10, or mixed values. Define a function named IsVectorMult10 that takes a vector as a parameter, representing the list, and returns a boolean that represents whether the list contains all multiples of ten. Define a function named IsVectorNoMult10 that takes a vector as a parameter, representing the list, and returns a boolean that represents whether the list contains no multiples of ten.

Then, write a main program that takes an integer, representing the size of the list, followed by the list values. The first integer is not in the list.

Ex: If the input is:

    *5 20 40 60 80 100

the output is:

    *all multiples of 10

Ex: If the input is:

    *5 11 -32 53 -74 95

the output is:

    *no multiples of 10

Ex: If the input is:

    *5 10 25 30 40 55

the output is:

    *mixed values

The program must define and call the following two functions. IsVectorMult10 returns true if all integers in the vector are multiples of 10 and false otherwise. IsVectorNoMult10 returns true if no integers in the vector are multiples of 10 and false otherwise.
bool IsVectorMult10(vector<int> myVec)
bool IsVectorNoMult10(vector<int> myVec)

*/
#include <iostream>
#include <vector>
using namespace std;

bool IsVectorMult10(vector<int> myVec) {
    bool tf = true;
    for (size_t i = 0; i < myVec.size(); ++i) {
        if (myVec.at(i) % 10) {
            tf = false;
        }
    }
    return tf;
}

bool IsVectorNoMult10(vector<int> myVec) {
    bool tf = true;
    for (size_t i = 0; i < myVec.size(); ++i) {
        if ((myVec.at(i) % 10) == 0) {
            tf = false;
        }
    }
    return tf;
}

int main() {
    
    //Declaring variables
    int N;
    vector<int> uInt;

    //Getting user input
    cin >> N;

    uInt.resize(N);

    for (size_t i = 0; i < uInt.size(); ++i) {
        cin >> uInt.at(i);
    }

    if (IsVectorMult10(uInt)) {
        cout << "all multiples of 10" << endl;
    } else if (IsVectorNoMult10(uInt)) {
        cout << "no multiples of 10" << endl;
    } else {
        cout << "mixed values" << endl;
    }

    return 0;
}