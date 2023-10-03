/*
Write a program that translates a letter grade into a number grade. Letter grades are A, B, C, D, and F, possibly followed by + or –. Their numeric values, are 4, 3, 2, 1, and 0. There is no F+ or F–. A + increases the numeric value by 0.3, a – decreases it by 0.3. However, an A+ has value 4.0.

    *Enter a letter grade: B. <br>
    *The numeric value is 2.7.

*/
#include <iostream>
#include <string>
using namespace std;
int main() {

    //Declaring variables
    string grade, first;
    double result;
    
    //Getting user input
    cout << "Enter your letter grade: ";
    getline(cin, grade);

    //Initializing variables
    first = grade.substr(0, 1);
    result = 0;

    //Assign number for letter grade
    if (first == "A") { 
        result = 4; 
    } else if (first == "B") { 
        result = 3; 
    } else if (first == "C") { 
        result = 2; 
    } else if (first == "D") { 
        result = 1; 
    }
    
    //Handling + or - grades
    if (grade.length() > 1) {
        if (grade.substr(1,1) == "+") {
            result = result + 0.3;
        } else {
            result = result - 0.3;
        }
    }
   
    //Limit result to no more than 4
    if (result > 4.0) {
        result = 4.0;
    }
    
    //Printing output
    cout << "The equivalent number grade is " << result << endl;
    return 0;
}