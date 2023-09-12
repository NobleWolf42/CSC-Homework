/*
(1) Prompt the user to input an integer, a double, a character, and a string, storing each into separate variables. Then, output those four values on a single line separated by a space. (2 pts) (User Inputs in Bold)

Note: This zyLab outputs a newline after each user-input prompt. For convenience in the examples below, the user's input value is shown on the next line, but such values don't actually appear as output when the program runs.

    *Enter integer:
    *<b>99</b>
    *Enter double:
    *<b>3.77</b>
    *Enter character:
    *<b>z</b>
    *Enter string:
    *<b>Howdy</b>
    *99 3.77 z Howdy

(2) Extend to also output in reverse. (1 pt) (User Inputs in Bold)

    *Enter integer:
    *<b>99</b>
    *Enter double:
    *<b>3.77</b>
    *Enter character:
    *<b>z</b>
    *Enter string:
    *<b>Howdy</b>
    *99 3.77 z Howdy
    *Howdy z 3.77 99

(3) Extend to cast the double to an integer, and output that integer. (2 pts) (User Inputs in Bold)

    *Enter integer:
    *<b>99</b>
    *Enter double:
    *<b>3.77</b>
    *Enter character:
    *<b>z</b>
    *Enter string:
    *<b>Howdy</b>
    *99 3.77 z Howdy
    *99 3.77 z Howdy
    *Howdy z 3.77 99
    *3.77 cast to an integer is 3

*/
#include <iostream>
#include <string>      // Supports use of "string" data type
using namespace std;

int main() {

    //Declaring variables
    int    userInt;
    double userDouble;
    char   userChar;
    string userString;

    //Getting user input
    cout << "Enter integer:" << endl;
    cin  >> userInt;
    cout << "Enter double:" << endl;
    cin  >> userDouble;
    cout << "Enter character:" << endl;
    cin  >> userChar;
    cout << "Enter string:" << endl;
    cin  >> userString;
    
    //Printing variables
    cout << userInt << " " << userDouble <<  " " << userChar <<  " " << userString << endl;
    
    //Printing variables in reverse
    cout << userString <<  " " << userChar <<  " " << userDouble <<  " " << userInt << endl;
    
    //Printing userDouble cast to int
    cout << userDouble << " cast to an integer is " << static_cast<int>(userDouble) << endl;
   return 0;
}