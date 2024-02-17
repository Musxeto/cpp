//Algorithm: Evaluate Postfix Expression
//Input: A string representing a postfix expression.
//
//1. Initialize an empty stack to store operands.
//2. Create a string stream to tokenize the input expression.
//3. Loop through each token in the input expression:
//   a. Read the next token from the string stream.
//   b. If the token is a digit (i.e., the first character is a digit):
//      i. Convert the token to an integer.
//      ii. Push the integer onto the stack.
//   c. If the token is an operator:
//      i. Pop the top two elements from the stack; these are the operands.
//      ii. Apply the operator to the two operands in the correct order.
//      iii. Push the result back onto the stack.
//4. After processing all tokens, the result is at the top of the stack.
//5. Pop and return the result as the final output.



#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

using namespace std;

int evaluatePostfixExpression(string expression) {
    stack<int> operandStack;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            operandStack.push(stoi(token));  // Convert the token to an integer and push it to the stack
        } else {
            // It's an operator
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            if (token == "+") {
                operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                operandStack.push(operand1 / operand2);
            }
        }
    }

    // The final result is on top of the stack
    return operandStack.top();
}

int main() {
	string expression;
	cout << "Enter a string elements seperated by spaces: ";
    getline(cin, expression);
    
    int result = evaluatePostfixExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}

