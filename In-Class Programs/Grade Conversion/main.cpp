#include <iostream>
#include <string>
using namespace std;
int main() {
    
    //Declaring variables
    char letter;
    double result;
    
    //Getting user input
    cout << "Please enter a letter grade: ";
    cin >> letter;
    cout << endl;

    //Translating letter to number grade
    if (letter >= 'A' && letter <= 'F') { 
        switch (letter) {
        case 'A':
            result = 4;
            break;
        case 'B':
            result = 3;
            break;
        case 'C':
            result = 2;
            break;
        case 'D':
            result = 1;
            break;
        default:
            result = 0;
            break;
        }
    }
    cout << "Letter Grade of " << letter << " is " << result << " as a number." << endl;
    return 0;
}