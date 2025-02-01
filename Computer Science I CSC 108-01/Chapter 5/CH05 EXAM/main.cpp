/*
Commas make large integers easier to read. Ex: 145,020 is easier to read than 145020. Write a function that takes an integer, and returns a string representation of that number with commas appropriately inserted. If the input is 145020, the function returns a string "145,020".

TODO:

    *Write a function to convert a single integer digit to a char DigitToChar. Make sure you name your function as DigitToChar. The function takes a single-digit integer and returns a character of the digit. See an ASCII table for the digit character value. (25 points)

    *Write a function integerWithCommas that takes an integer, and returns a string representation of that number with commas appropriately inserted. If the input is 145020, the function returns a string "145,020". You must use DigitToChar in this function in order to get full credit for this problem. Incorrect use of the DigitToChar function will result in a 50% or more deduction from this function. If you don't use DigitToChar at all in this function or you are not using loop in this function, then you won't get any credit for this problem. (45 points)

    *Write five different unit-test cases (assert) for DigitToChar function (10 points)

    *Write five different unit-test cases (assert) for integerWithComma function (10 points)

    *The Zybooks score is for your reference only. The final scores will be based on the above rubrics and manual grading.

If you convert the integer number into a string using the C++ library functions, you will not get any credits for this exam.
*/
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

char DigitToChar(int digit) {
    return digit + 48;
}

string integerWithCommas(int digit) {
    string output = "";
    int count = 0;

    if (digit != 0) {
        while(digit > 0 ) {
            if (count % 3 || count == 0) {
                output.insert(0, 1, DigitToChar(digit % 10));
                count++;
                digit = digit / 10;
            } else {
                output.insert(0, 1, ',');
                output.insert(0, 1, DigitToChar(digit % 10));
                count++;
                digit = digit / 10;
            }
        }
    } else {
        output = DigitToChar(digit);
    }
    return output;
}

int main() {

    //Declaring variables
    int userNum;
    
    //Getting user input
    cin >> userNum;
    
    cout << integerWithCommas(userNum) << endl;

    //Test cases for DigitToChar
    assert(DigitToChar(0) == '0');
    assert(DigitToChar(1) == '1');
    assert(DigitToChar(5) == '5');
    assert(DigitToChar(8) == '8');
    assert(DigitToChar(9) == '9');
    
    //Test cases for IntegerWithCommas
    assert(integerWithCommas(0) == "0");
    assert(integerWithCommas(100000) == "100,000");
    assert(integerWithCommas(999999) == "999,999");
    assert(integerWithCommas(1000000000) == "1,000,000,000");
    assert(integerWithCommas(2147483647) == "2,147,483,647");

    return 0;
}