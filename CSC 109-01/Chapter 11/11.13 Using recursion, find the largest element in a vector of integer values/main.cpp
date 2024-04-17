/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Using recursion, find the largest element in a vector of integer values.

    *int maximum(vector<int> values)
    *
    *Hint: Find the largest element in the subset containing all but the last element. Then compare that maximum to the value of the last element. 

For example,

    *How many numbers do you want to enter? 4
    *The number you entered is: 4
    *The number you entered is: -4
    *The number you entered is: 14
    *The number you entered is: 8
    *The maximum is: 14

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
   Find the maximum value in a vector.
   @param values  a vector of values
   @return the maximum value
*/

int maximum(vector<int> values) {
    
    if (values.size() == 2) {
        return max(values.at(0), values.at(1));
    } else {
        int temp = values.back();
        values.pop_back();
        return max(maximum(values), temp);
    }
}

int main() {
    
    int count, addN;
    vector<int> uVal;
    
    cout << "How many numbers do you want to enter? " << endl;

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> addN;
        cout << "The number you entered is: " << addN << endl;
        uVal.push_back(addN);
    }
    
    cout << "The maximum is: " << maximum(uVal) <<  "\n";
    
    return 0;
}
