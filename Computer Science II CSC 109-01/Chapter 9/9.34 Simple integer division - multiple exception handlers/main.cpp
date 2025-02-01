/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Write a program that reads integers userNum and divNum as input, and output the quotient (userNum divided by divNum). Use a try block to perform the statements and throw a runtime_error exception with the message "Divide by zero!" when a division by zero happens. Use a catch block to catch any runtime_error caused by dividing by zero and output an exception message. Use another catch block to catch any ios_base::failure caused by invalid input and output an exception message.

Note: ios_base::failure is thrown when a user enters a value of different data type than what is defined in the program. Do not write code to throw ios_base::failure exception in the program.

Ex: If the input of the program is:

    *15 3

the output of the program is:

    *5

Ex: If the input of the program is:

    *10 0

the output of the program is:

Runtime Exception: Divide by zero!

Ex: If the input of the program is:

    *twenty 5

the output of the program is:

    *Input Exception: basic_ios::clear: iostream error

*/

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int userNum;
    int divNum;
    int result;
    cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

    try {
        
        cin >> userNum >> divNum;
        if (divNum == 0) {
            throw(runtime_error("Divide by zero!"));
        }
        result = userNum/divNum;
        cout << result << endl;

    } catch (ios_base::failure& e) {
        cout << "Input Exception: " << e.what() << endl;
    } catch (runtime_error& e) {
         cout << "Runtime Exception: " << e.what() << endl;
    }

    return 0;
}
