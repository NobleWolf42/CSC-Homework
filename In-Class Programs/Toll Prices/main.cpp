#include <iostream>

using namespace std;

int main () {
    
    //Declaring variables
    int hours;
    double tollAmt;

    //Getting user input
    cout << "Enter Hours:";
    cin >> hours;
    cout << endl;

    //Setting toll amount
    if (hours < 24) {
        if (hours >= 18) {
            tollAmt = 1.55;
        } else if (hours >= 10) {
            tollAmt = 2.35;
        } else if (hours >= 6) {
            tollAmt = 4.65;
        } else {
            tollAmt = 1.55;
        }
        cout << "The toll amount is " << tollAmt << endl;
    } else {
        cout << "Hours must be between 0 and 23!" << endl;
    }

}