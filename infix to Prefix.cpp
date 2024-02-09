#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
    	return 3;
    return 0; // For all other characters (operands or parentheses)
}

// Function to reverse a string
string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(const string& infix) {
    stack<char> stack;
    string prefix;
    
    // Reverse the infix expression
    string reversedInfix = reverseString(infix);

    for (char symbol : reversedInfix) {
        if (isalnum(symbol)) {
            prefix += symbol; // Operand, add to the prefix expression
        }
        else if (symbol == ')') {
            stack.push(symbol); // Right parenthesis, push onto the stack
        }
        else if (symbol == '(') {
            // Left parenthesis, pop and append operators until a right parenthesis is found
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            stack.pop(); // Pop the right parenthesis
        }
        // If the current symbol is '^' and is equal to the top of the stack, add it to the prefix expression
		else if (symbol == '^' && !stack.empty() && symbol == stack.top()) {
		    prefix += symbol;
		}

        else { // Operator
            while (!stack.empty() && precedence(symbol) < precedence(stack.top())) {
                prefix += stack.top(); // Pop and add operators with higher precedence
                stack.pop();
            }
            stack.push(symbol); // Push the current operator onto the stack
        }
    }
    
    // Pop and append remaining operators in the stack to the prefix expression
    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }
    
    // Reverse the final prefix expression to get the correct order
    return reverseString(prefix);
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    // Read the entire line, including spaces
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix notation: " << prefixExpression << endl;

    return 0;
}

