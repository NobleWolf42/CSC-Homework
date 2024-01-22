/*
When analyzing data sets, such as data for human heights or for human weights, a common step is to adjust the data. This can be done by normalizing to values between 0 and 1, or throwing away outliers. For this program, adjust the values by subtracting each value from the maximum. The input begins with an integer indicating the number of integers that follow. Assume that the list will always contain between 1 and 20 integers.

Ex: If the input is:

    *5 30 50 10 70 65

the output is:

    *40 20 60 0 5 

For coding simplicity, follow every output value by a space, even the last one.

Your program must define and use the following function:
int GetMaxInt(vector<int> listInts)
*/
#include <iostream>
#include <vector> 
using namespace std;

int GetMaxInt(vector<int> listInts) {
    int max = listInts.at(0);
    for (size_t i = 0; i < listInts.size(); ++i) {
        if (listInts.at(i) > max) {
            max = listInts.at(i);
        }
    }

    return max;
}

int main() {
    
    //Declaring variables
    int N, max;
    vector<int> numbers;

    //Getting user input
    cin >> N;
    numbers.resize(N);

    //Filling vector
    for (size_t i = 0; i < numbers.size(); ++i) {
        cin >> numbers.at(i);
    }

    //Adjusting values
    max = GetMaxInt(numbers);
    for (size_t i = 0; i < numbers.size(); ++i) {
        numbers.at(i) = max - numbers.at(i);
    }

    //Outputting results
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers.at(i) << " ";
    }
    cout << endl;

    return 0;
}