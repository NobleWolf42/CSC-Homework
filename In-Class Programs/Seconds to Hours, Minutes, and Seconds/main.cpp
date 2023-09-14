/*
Make a program that takes a user input of seconds and outputs it in HH:MM:SS form.
*/
#include <iostream>

using namespace std;

int main() {

    //Declaring variables
    int secs, minuets, hours;

    //Getting us inputs
    cout << "Please enter time in seconds: ";
    cin >> secs;

    //Finding time
    hours = secs / 3600;
    secs = secs % 3600;
    minuets = secs / 60;
    secs = secs % 60;

    //Printing time
    cout << "Time is " << hours << ":" << minuets << ":" << secs << endl;
}