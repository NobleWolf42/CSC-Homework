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