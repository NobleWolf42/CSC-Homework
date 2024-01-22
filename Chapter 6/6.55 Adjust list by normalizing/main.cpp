/*
When analyzing data sets, such as data for human heights or for human weights, a common step is to adjust the data. This adjustment can be done by normalizing to values between 0 and 1, or throwing away outliers.

For this program, adjust the values by dividing all values by the largest value. The input begins with an integer indicating the number of floating-point values that follow.

Output each floating-point value with two digits after the decimal point, which can be achieved by executing
cout << fixed << setprecision(2); once before all other cout statements.

Ex: If the input is:

    *5 30.0 50.0 10.0 100.0 65.0

the output is:

    *0.30 0.50 0.10 1.00 0.65 

The 5 indicates that there are five floating-point values in the list, namely 30.0, 50.0, 10.0, 100.0, and 65.0. 100.0 is the largest value in the list, so each value is divided by 100.0.

For coding simplicity, follow every output value by a space, including the last one.
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {

    //Declaring variables
    int N;
    double biggest;

    //Getting user inputs
    cin >> N;

    //Declaring array
    double dArray[N];

    //Filling array
    for (int i = 0; i < N; ++i) {
        double tempIn;
        cin >> tempIn;
        dArray[i] = tempIn;
        if (tempIn > biggest) {
            biggest = tempIn;
        }
    }

    //Making output two decimal places
    cout << fixed << setprecision(2);

    //Outputting results
    for (int i = 0; i < N; ++i) {
        cout << dArray[i] / biggest << " ";
    }

    cout << endl;

    return 0;
}