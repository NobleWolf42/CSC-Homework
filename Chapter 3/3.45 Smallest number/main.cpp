/*
Write a program whose inputs are three integers, and whose output is the smallest of the three values.

Ex: If the input is:

    *7 15 3

the output is:

    *3

*/
#include <iostream>
using namespace std;

int main() {
    
    //Declaring variables
    int n1, n2, n3, lowest;

    //Getting user input
    cin >> n1;
    cin >> n2;
    cin >> n3;

    //Finding lowest
    if (n1 <= n2 && n1 <= n3) {
        lowest = n1;
    } else if (n2 <= n1 && n2 <= n3) {
        lowest = n2;
    } else {
        lowest = n3;
    }

    //Printing result
    cout << lowest << endl;

    return 0;
}