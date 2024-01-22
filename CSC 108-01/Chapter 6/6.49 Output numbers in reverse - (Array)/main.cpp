/*
Write a program that reads a list of integers, and outputs those integers in reverse. The input begins with an integer indicating the number of integers that follow. For coding simplicity, follow each output integer by a comma, including the last one.

Ex: If the input is:

    *5 2 4 6 8 10

the output is:

    *10,8,6,4,2,

To achieve the above, first read the integers into an array. Then output the array in reverse.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {

    //Declaring variables
    int N;
    string userInput;
    
    //Getting user input
    cin >> N;

    //Creating array
    int userInts[N];

    //Cutting up user input
    for (int i = 0; i < N; ++i) {
        int tempIn;
        cin >> tempIn;
        userInts[i] = tempIn;
    }

    //Displaying results
    for(int i = N - 1; i > -1; --i) {
        cout << userInts[i] << ",";
    }
    
    cout << endl;

    return 0;
}