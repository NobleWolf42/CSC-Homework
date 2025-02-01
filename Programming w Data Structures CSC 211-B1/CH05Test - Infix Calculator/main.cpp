/*
Author: Ben Carpenter
Copyright: 2024

Assignment:

You must evaluate an infix expression directly. To do so you need two stacks: one to contain operators and the other to contain operands. When an operand is encountered, it is pushed onto the operand stack. When an operator is encountered, you must push to the operator stack or evaluate it immediately depending the precedent of the operators. The top two operands are popped off the operand stack, the operation is performed, and the result is pushed back onto the operand stack. Write a program to evaluate infix expressions directly using this combined algorithm.  You must use the method as described to get full credit for this exam.  Use newCxxtest framework to test your program and submit your Infix_Evaluator.h, Infix_Evaluator.cpp, and newCxxTest.h to Web-CAT server for grading.

Your program must be able to handle the following operators:

+-* /()

Infix evaluator header file

Test cases:

4 * 7 == 28

4 * ( 7 + 2 ) == 36

( 4 * 7 ) - 20 == 8

3 + ( ( 4 * 7 ) / 2 ) = 17

Grading rubrics: 

+,-, *,/ 10 points each; write 4 test cases using different combination of the operators, +,-,*,/.  Total of 4 test cases.

() 50 points; write two test cases with parenthesis using one of the examples above.  Total of 2 test cases.

You must pass my instructor's test to get full credit for the exam.  Only submit syntax error-free code to Web-CAT.  If your program does not compile, you won't get any credits for the exam.

For the toolbar, press ALT+F10 (PC) or ALT+FN+F10 (Mac).
*/

#include <iostream>
#include <string>
#include "Infix_Evaluator.h"

using namespace std;

int main() {
    Infix_Evaluator infix;
    cout <<
         "Enter expressions to be converted, or press Return when done\n";
    string expression;
    while (getline(cin, expression)) {
        if (expression == "") break;
        try {
            int result = infix.eval(expression);
            cout << "== " << result << endl;
        } catch (invalid_argument const& e) {
            cout << "Syntax Error: " << e.what() << endl;
        }
        cout << "Enter next expression: ";
    }
}