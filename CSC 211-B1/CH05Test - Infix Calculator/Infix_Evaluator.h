/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef INFIXEVALUATOR_H
#define INFIXEVALUATOR_H

#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using std::stack;
using std::string;
using std::istringstream;
using std::invalid_argument;
using std::isdigit;

class Infix_Evaluator {

// Public member functions
public:

/** Evaluates a postfix expression.
* @param expression The expression to be evaluated
* @return The value of the expression
* @throws Syntax_Error if a syntax error is detected
*/
    double eval(const string& expression) {
        int matchingParentheses = 0;
        bool prevDigit = false;
        double total = 0;

        // Be sure the stack is empty
        while (!operand_stack.empty()) {
            operand_stack.pop();
        }
        while (!op_stack.empty()) {
            op_stack.pop();
        }

        // Process each token
        for (size_t i = 0; i < expression.length(); i++) {
            if (expression[i] == ' ') {
                continue;
                prevDigit = false;
            } else if (expression[i] == '(') {
                op_stack.push(expression[i]);
                matchingParentheses++;
                prevDigit = false;
            } else if (expression[i] == ')') {
                while (!op_stack.empty() && op_stack.top() != '(') {
                    char op = op_stack.top();
                    op_stack.pop();
                    operand_stack.push(eval_op(op));
                }
                op_stack.pop();

                matchingParentheses--;
                prevDigit = false;
            } else if (isdigit(expression[i])) {
                if (prevDigit) {
                    double temp = operand_stack.top();
                    operand_stack.pop();
                    temp = temp * 10 + (expression[i]-'0');
                    operand_stack.push(temp);
                } else {
                    operand_stack.push(expression[i]-'0');
                }
                prevDigit = true;
            } else if (is_operator(expression[i])) {
                while (!op_stack.empty() && (expression[i] == '+' || expression[i] == '-') && op_stack.top() != '(') {
                    char op = op_stack.top();
                    op_stack.pop();
                    operand_stack.push(eval_op(op));
                }
                op_stack.push(expression[i]);
                prevDigit = false;
            } else {
                throw invalid_argument("Not a valid charter");
            }
        }
        if (matchingParentheses != 0) {
            throw invalid_argument("Not all Parentheses match");
        } else {
            while (!op_stack.empty()) {
                if (operand_stack.empty()) {
                    throw invalid_argument("Operand stack empty");
                }
                char op = op_stack.top();
                op_stack.pop();
                operand_stack.push(eval_op(op));
            }
        }

        if (operand_stack.empty()) {
            throw invalid_argument("Operand stack empty");
        }
        return operand_stack.top();
    }
    
// Private member functions
private:

/** Evaluates the current operator.
* This function pops the two operands off the operand
* stack and applies the operator.
* @param op A character representing the operator
* @throws Syntax_Error if top is attempted on an empty stack
*/
    double eval_op(char op) {
        if (operand_stack.empty()) {
            throw invalid_argument("Stack is empty");
        }
        
        double rhs = operand_stack.top();
        operand_stack.pop();
        
        if (operand_stack.empty()) {
            throw invalid_argument("Stack is empty");
        }

        double lhs = operand_stack.top();
        operand_stack.pop();
        
        double result = 0;

        /**while (!op_stack.empty() && (op_stack.top() == '*' || op_stack.top() == '/') && (op == '+' || op == '-')) {
            char temp = op_stack.top();
            op_stack.pop();
            operand_stack.push(lhs);
            operand_stack.push(eval_op(temp));
            lhs = operand_stack.top();
            operand_stack.pop();
        }**/
        
        switch(op) {
            case '+' :
                result = lhs + rhs;
                break;
            case '-' :
                result = lhs - rhs;
                break;
            case '*' :
                result = lhs * rhs;
                break;
            case '/' :
                if (rhs == 0) {
                    throw invalid_argument("Cannot divide by 0");
                }
                result = lhs / rhs;
                break;
        }
        return result;
    }
/** Determines whether a character is an operator.
@param ch The character to be tested
@return true if the character is an operator
*/
    bool is_operator(char ch) const {
        return OPERATORS.find(ch) != string::npos;
    }
// Data fields
    string OPERATORS = "+-*/";
    stack<double> operand_stack;
    stack<char> op_stack;
};




#endif //CH05INFIXCONVERTFA23_POSTFIX_EVALUATOR_H