/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
If a string has n letters, then the number of permutations is given by the factorial function:

    *n! = 1 x 2 x 3 x ... x n

For example, 3! = 1 x 2 x 3 = 6 and there are six permutations of the three-character string "eat". Implement a recursive factorial function, using the definitions

    *n! = (n - 1)! x n
    *
    *0! = 1

*/

#include <iostream>

using namespace std;

/**
   Calculates factorial recursively.
   @param n the number for which to calculate n!
   @return n!, the factorial of n
*/
int factorial(int n) { 
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int number;
    
    cout << "Enter a number: " << endl;

    cin >> number;
    
    cout << "The factorial of that number is: " << factorial(number) << endl;
    return 0;
}
