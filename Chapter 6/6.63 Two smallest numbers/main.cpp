/*
Write a program that reads a list of integers, and outputs the two smallest integers in the list, in ascending order. The input begins with an integer indicating the number of integers that follow.

Ex: If the input is:

    *5
    *10 5 3 21 2

the output is:

    *2 and 3

You can assume that the list of integers will have at least 2 values.

To achieve the above, first read the integers into a vector.

Hint: Make sure to initialize the second smallest and smallest integers properly.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {

    //Declaring variables
    int N, min, otherMoreDifferentMin;
    vector<int> userInt;

    //Getting user input
    cin >> N;

    //Sizing vector
    userInt.resize(N);

    //Filling vector
    for (int i = 0; i < N; ++i) {
        int tempInt;
        cin >> tempInt;
        userInt.at(i) = tempInt;
    }

    //Getting mins
    min = userInt.at(0);
    otherMoreDifferentMin = userInt.at(1);

    for (size_t i = 0; i < userInt.size(); ++i) {
        if (userInt.at(i) < min) {
            otherMoreDifferentMin = min;
            min = userInt.at(i);
        } else if (userInt.at(i) < otherMoreDifferentMin && userInt.at(i) != min) {
            otherMoreDifferentMin = userInt.at(i);
        }
    }

    //Outputting result
    cout << min << " and " << otherMoreDifferentMin << endl;

    return 0;
}