/*
Write a program that reads a list of integers, and outputs whether the list contains all multiples of 10, no multiples of 10, or mixed values. Define a function named IsVectorMult10 that takes a vector as a parameter, representing the list, and returns a boolean that represents whether the list contains all multiples of ten. Define a function named IsVectorNoMult10 that takes a vector as a parameter, representing the list, and returns a boolean that represents whether the list contains no multiples of ten.

Then, write a main program that takes an integer, representing the size of the list, followed by the list values. The first integer is not in the list.

Ex: If the input is:

    *5 20 40 60 80 100

the output is:

    *Multiples of 10: 20, 40, 60, 80, 100, 
    *Non-multiples of 10: 

Ex: If the input is:

    *5 11 -32 53 -74 95

the output is:

    *Multiples of 10: 
    *Non-multiples of 10: 11, -32, 53, -74, 95, 

Ex: If the input is:

    *5 10 25 30 40 55

the output is:

    *Multiples of 10: 10, 30, 40, 
    *Non-multiples of 10: 25, 55, 

The program must define and call the following two functions. IsVectorMult10 returns multiples of 10 in a vector. IsVectorNoMult10 returns vector of non-multiples of ten.

    *vector<int> IsVectorMult10(vector<int> myVec)
    *vector<int> IsVectorNoMult10(vector<int> myVec)
    *vector<int> getInputVector()
    *void printVector(vector<int> vec)

    - ask the user to enter how many numbers to enter, and use a loop to get the inputs from the user.
    - only iostream, vector, and cassert libraries are allowed for the final exam.
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> IsVectorMult10(vector<int> myVec) {
    vector<int> output;
    for (size_t i = 0; i < myVec.size(); ++i) {
        if ((myVec.at(i) % 10) == 0) {
            output.push_back(myVec.at(i));
        }
    }
    return output;
}

vector<int> IsVectorNoMult10(vector<int> myVec) {
    vector<int> output;
    for (size_t i = 0; i < myVec.size(); ++i) {
        if (myVec.at(i) % 10) {
            output.push_back(myVec.at(i));
        }
    }
    return output;
}

vector<int> getInputVector() {
    int N;
    vector<int> uInt;

    cin >> N;

    uInt.resize(N);

    for (size_t i = 0; i < uInt.size(); ++i) {
        cin >> uInt.at(i);
    }

    return uInt;
}

void printVector(vector<int> vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec.at(i) << ", ";
    }
}

void testVector(vector<int> test, vector<int> result, int numTest) {
    assert(test.size() == numTest);

    for (size_t i = 0; i < test.size(); ++i) {
        assert(test.at(i) == result.at(i));
    }
}

int main() {
    
    //Declaring variables

    //Getting user input
    vector<int> userIn = getInputVector();

    //Sorting user input
    vector<int> is10 = IsVectorMult10(userIn);
    vector<int> not10 = IsVectorNoMult10(userIn);

    //Outputting result
    cout << "Multiples of 10: ";
    printVector(is10);
    cout << endl << "Non-multiples of 10: ";
    printVector(not10);
    cout << endl;

    //Test Cases
    vector<int> test1 = {10,20,30,40,50};
    vector<int> test2 = {11,22,33,44,55};
    vector<int> test3 = {10,22,30,44,50};
    vector<int> test4 = {11,20,33,40,55};
    vector<int> test5 = {-10,20,-33,40,50};
    testVector(IsVectorMult10(test1), {10,20,30,40,50}, 5);
    testVector(IsVectorMult10(test2), {}, 0);
    testVector(IsVectorMult10(test3), {10,30,50}, 3);
    testVector(IsVectorMult10(test4), {20,40}, 2);
    testVector(IsVectorMult10(test5), {-10,20,40,50}, 4);
    testVector(IsVectorNoMult10(test1), {}, 0);
    testVector(IsVectorNoMult10(test2), {11,22,33,44,55}, 5);
    testVector(IsVectorNoMult10(test3), {22,44}, 2);
    testVector(IsVectorNoMult10(test4), {11,33,55}, 3);
    testVector(IsVectorNoMult10(test5), {-33}, 1);

    return 0;
}