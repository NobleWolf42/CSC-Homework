/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Write a program that takes in three integers as inputs and outputs the largest value. Use a try block to perform all the statements. Use a catch block to catch any ios_base::failure caused by missing inputs and output the number of inputs read and the largest value. Output "No max" if no inputs are read.

Note: Because inputs are pre-entered when running a program in the zyLabs environment, the system throws the ios_base::failure when inputs are missing. Test the program by running the program in the Develop mode.

Hint: Use a counter to keep track of the number of inputs read and compare the inputs accordingly in the catch block when an exception is caught.

Ex: If the input is:

    *3 7 5

the output is:

    *7

Ex: If the input is:

    *3

the system throws the ios_base::failure and outputs:

    *1 input(s) read:
    *Max is 3

Ex: If no inputs are entered:

    *

the system throws the ios_base::failure and outputs:

    *0 input(s) read:
    *No max

*/

#include <iostream>

using namespace std;

int main() {
    cin.exceptions(ios::failbit); // Allow cin to throw exceptions
    int val1;
    int val2;
    int val3;
    int max;
    int temp, count = 0;
    
    val1 = 0;
    val2 = 0;
    val3 = 0;

    try {      
        
        for (int i = 0; i < 3; i++) {
            cin >> temp;
            count++;

            if (i == 0) {
                val1 = temp;
                max = val1;
            } else if (i == 1) {
                val2 = temp;
                if (max < val2) {
                    max = val2;
                }
            } else {
                val3 = temp;
                if (max < val3) {
                    max = val3;
                }
            }
        }

        cout << max << endl;

    } catch (ios_base::failure& e) {
        cout << count << " input(s) read:" << endl;
        if (count == 0) {
            cout << "No max" << endl;
        } else {
            cout << "Max is " << max << endl;
        }
    }

    return 0;
}
