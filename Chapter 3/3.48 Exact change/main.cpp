/*
Write a program with total change amount as an integer input, and output the change using the fewest coins, one coin type per line. The coin types are Dollars, Quarters, Dimes, Nickels, and Pennies. Use singular and plural coin names as appropriate, like 1 Penny vs. 2 Pennies.

Ex: If the input is:

    *0 

(or less than 0), the output is:

    *No change 

Ex: If the input is:

    *45

the output is:

    *1 Quarter
    *2 Dimes

*/
#include <iostream>
using namespace std;

int main() {

    //Declaring variables
    int change, dollars, quarters, dimes, nickles;

    //Getting user input
    cin >> change;

    //Stopping program if change is < 1
    if (change < 1) {
        cout << "No change" << endl;
        return 0;
    }

    //Getting value of coins
    dollars = change / 100;
    change = change % 100;
    quarters = change / 25;
    change = change % 25;
    dimes = change / 10;
    change = change % 10;
    nickles = change / 5;
    change = change % 5;

    //Outputting dollars
    if (dollars == 1) {
        cout << dollars << " Dollar" << endl;
    } else if (dollars > 1) {
        cout << dollars << " Dollars" << endl;
    }

    //Outputting quarters
    if (quarters == 1) {
        cout << quarters << " Quarter" << endl;
    } else if (quarters > 1) {
        cout << quarters << " Quarters" << endl;
    }

    //Outputting dimes
    if (dimes == 1) {
        cout << dimes << " Dime" << endl;
    } else if (dimes > 1) {
        cout << dimes << " Dimes" << endl;
    }

    //Outputting nickles
    if (nickles) {
        cout << nickles << " Nickel" << endl;
    }


    //Outputting pennies
    if (change == 1) {
        cout << change << " Penny" << endl;
    } else if (change > 1) {
        cout << change << " Pennies" << endl;
    }

    return 0;
}