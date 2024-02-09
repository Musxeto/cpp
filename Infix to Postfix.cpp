//Algorithm to Convert Infix Expression to Postfix Notation:
//
//1. Create an empty stack for operators.
//2. Create an empty string for the output (postfix expression).
//3. Scan the infix expression from left to right, one symbol at a time.
//4. For each symbol in the infix expression:
//   a. If the symbol is an operand (a letter, digit, etc.), append it to the output.
//   b. If the symbol is an opening parenthesis '(', push it onto the stack.
//   c. If the symbol is a closing parenthesis ')', pop operators from the stack and append them to the output until an opening parenthesis '(' is encountered. Pop and discard the opening parenthesis.
//   d. If the symbol is an operator (+, -, *, /, etc.):
//      i. While the stack is not empty and the operator at the top of the stack has higher or equal precedence than the current operator, pop the top operator from the stack and append it to the output.
//      ii. Push the current operator onto the stack.
//5. After scanning all symbols in the infix expression, pop any remaining operators from the stack and append them to the output.
//6. The output string now contains the postfix notation.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3; // Exponentiation has higher precedence
    return 0; // For all other characters (operands or parentheses)
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> stack;
    string postfix;

    for (char symbol : infix) {
        if (isalnum(symbol)) {
            postfix += symbol; // Operand, add to the postfix expression
        } else if (symbol == '(') {
            stack.push(symbol); // Left parenthesis, push onto the stack
        } else if (symbol == ')') {
            // Right parenthesis, pop and append operators until a left parenthesis is found
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Pop the left parenthesis
        } else if (symbol == '^') {
            // Exponentiation has right-to-left associativity, so pop and append all '^' operators
            while (!stack.empty() && precedence(symbol) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(symbol);
        } else { // Operator
            while (!stack.empty() && precedence(symbol) <= precedence(stack.top())) {
                postfix += stack.top(); // Pop and add operators with higher precedence
                stack.pop();
            }
            stack.push(symbol); // Push the current operator onto the stack
        }
    }

    // Pop and append remaining operators in the stack to the postfix expression
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    // Read the entire line, including spaces
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix notation: " << postfixExpression << endl;

    return 0;
}


