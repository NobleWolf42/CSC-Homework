/*
Define a function named SortVector that takes a vector of integers as a parameter. SortVector() modifies the vector parameter by sorting the elements in descending order (highest to lowest). Then write a main program that reads a list of integers from input, stores the integers (starting from the second integer) in a vector, calls SortVector(), and outputs the sorted vector. The first input integer indicates how many numbers are in the list.

Ex: If the input is:

    *5 10 4 39 12 2

the output is:

    *39,12,10,4,2,

For coding simplicity, follow every output value by a comma, including the last one.

Your program must define and call the following function:
void SortVector(vector<int>& myVec)

Hint: Sorting a vector can be done in many ways. You are welcome to look up and use any existing algorithm. Some believe the simplest to code is bubble sort: https://en.wikipedia.org/wiki/Bubble_sort. But you are welcome to try others: https://en.wikipedia.org/wiki/Sorting_algorithm.
*/
#include <iostream>
#include <vector>
using namespace std;

void SortVector(vector<int>& myVec) {
    for (size_t i = 0; i < myVec.size(); ++i) {
        for (size_t j = 0; j < myVec.size() - i; ++j) {
            if (j != myVec.size() - 1) {
                if (myVec.at(j) < myVec.at(j + 1)) {
                    int temp = myVec.at(j);
                    myVec.at(j) = myVec.at(j + 1);
                    myVec.at(j + 1) = temp;
                }
            }
        }
    }
}

int main() {
    
    //Declaring variables
    int N;
    vector<int> numbers;

    //Getting user input
    cin >> N;
    numbers.resize(N);

    //Filling vector
    for (size_t i = 0; i < numbers.size(); ++i) {
        cin >> numbers.at(i);
    }

    //Sorting and outputting vector
    SortVector(numbers);
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers.at(i) << ",";
    }
    cout << endl;

    return 0;
}