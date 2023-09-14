/*
Giving change. Implement a program that directs a cashier how to give change. The program has two inputs: the amount due and the amount received from the customer. It should compute the difference, and compute the dollars, quarters, dimes, nickels, and pennies that the customer should receive in return.
Hint: First transform the difference into an integer balance, denominated in pennies. Then compute the whole dollar amount. Subtract it from the balance. Compute the number of quarters needed. Repeat for dimes and nickels. Display the remaining pennies. You can also use modulo in this problem.
(50 points)
Ask the user to enter the inputs:
Please enter the amount due: 2.30
Please enter the amount paid: 3.00

Produce the output similar to the following:
The change due to the customer is 0 dollars, 2 quarters, 2 dimes, 0 nickels, and 0 pennies.

    *Rubric:
        *cout – 5 each
        *cin – 5 each
        *type – 5 each
        *Correct value for dollar, quarter, dime, nickel, pennies - 5 each
        *final output – 10
        *Wrong formula - -5 each

*/
#include <iostream>

using namespace std;

int main() {

    //Declaring variables
    double amountDue;
    double amountPaid;
    int changeDollar;
    int changeQuarters;
    int changeDimes;
    int changeNickels;
    int changePennies;

    //Getting user inputs
    cout << "Please enter the amount due: ";
    cin >> amountDue;
    cout << endl << "Please enter the amount paid: ";
    cin >> amountPaid;
    cout << endl;

    //Finding the change values

    //Printing change due
    cout << "The change due to the customer is " << changeDollar << " dollars, " << changeQuarters << " quarters, " << changeDimes << " dimes, " << changeNickels << " nickels, and " << changePennies << " pennies." << endl;
    return 0;
}