/*
Define a function named SwapValues that takes four integers as parameters and swaps the first with the second, and the third with the fourth values. Then write a main program that reads four integers from input and calls function SwapValues() to swap the input values. The main program then prints the swapped values on a single line separated with spaces and ending with a newline.

The program must define and call the following function:
void SwapValues(int& userVal1, int& userVal2, int& userVal3, int& userVal4)

Ex: If the input is:

    *3 8 2 4

function SwapValues() stores 8, 3, 4, and 2 in userVal1, userVal2, userVal3, and userVal4, respectively. The main program then outputs:

    *8 3 4 2

Function SwapValues() swaps the values referenced by the parameters and does not print any output.
*/
#include <iostream>
using namespace std;

void SwapValues(int& userVal1, int& userVal2, int& userVal3, int& userVal4) {
    cout << userVal2 << " " << userVal1 << " " << userVal4 << " " << userVal3 << endl;
}

int main() {
    
    //Declaring variables
    int uIn1, uIn2, uIn3, uIn4;

    //Getting user inputs
    cin >> uIn1 >> uIn2 >> uIn3 >> uIn4;

    //Running function that outputs the swapped numbers
    SwapValues(uIn1, uIn2, uIn3, uIn4);

    return 0;
}