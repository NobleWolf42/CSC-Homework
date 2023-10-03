/*
Write a program that translates a number between 0 and 4 into the closest letter grade. For example, the number 2.8 (which might have been the average of several grades) would be converted to B–. Break ties in favor of the better grade; for example 2.85 should be a B.
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    
    //Declaring variables
    double numGrade;
    string let_grade;

    //Getting user input
    cout << "Enter the number grade: ";
    cin >> numGrade;


    if (numGrade >= 3.85) { 
        let_grade = "A"; 
    } else if (numGrade >= 3.15) { 
        let_grade = "A-"; 
    } else if (numGrade >= 3.00) { 
        let_grade = "B+"; 
    } else if (numGrade >= 2.85) { 
        let_grade = "B";
    } else if (numGrade >= 2.15) {
        let_grade = "B-"; 
    }  else if (numGrade >= 2.00) {
        let_grade = "C+"; 
    }  else if (numGrade >= 1.85) {
        let_grade = "C"; 
    }  else if (numGrade >= 1.15) {
        let_grade = "C-"; 
    }  else if (numGrade >= 1.00) {
        let_grade = "D+"; 
    }  else if (numGrade >= 0.85) {
        let_grade = "D"; 
    }  else if (numGrade >= 0.15) {
        let_grade = "D-"; 
    } else {
        let_grade = "F";
    }
   
    //Printing results
    cout << "The equivalent letter grade is " << let_grade << endl;
    return 0;
}