/*
A common year in the modern Gregorian Calendar consists of 365 days. In reality, Earth takes longer to rotate around the sun. To account for the difference in time, every 4 years, a leap year takes place. A leap year is when a year has 366 days: An extra day, February 29th. The requirements for a given year to be a leap year are:

1) The year must be divisible by 4

2) If the year is a century year (1700, 1800, etc.), the year must be evenly divisible by 400; therefore, both 1700 and 1800 are not leap years

Some example leap years are 1600, 1712, and 2016.

Write a program that takes in a year and determines the number of days in February for that year.

Ex: If the input is:

    *1712

the output is:

    *1712 has 29 days in February.

Ex: If the input is:

    *1913

the output is:

    *1913 has 28 days in February.

Your program must define and call the following function. The function should return the number of days in February for the input year.

int DaysInFeb(int userYear)
*/
#include <iostream>
using namespace std;

int DaysInFeb(int userYear) {
    if (userYear % 400 == 0) {
        return 29;
    } else if (userYear % 4 == 0 && userYear % 100 != 0) {
        return 29;
    } else {
        return 28;
    }
}

int main() {
    
    
    //Declaring variables
    int uIn;

    //Getting user input
    cin >> uIn;

    //Outputting result
    cout << uIn << " has " << DaysInFeb(uIn) << " days in February." << endl;

    return 0;
}