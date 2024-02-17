#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to display the contents of the stack
void displayStack(const stack<char>& s) {
    stack<char> temp = s;
    cout << "Stack: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

bool isBalanced(const string& str) {
    stack<char> parenthesesStack;

    // Traverse the given string from left to right
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        // Display the stack at each iteration
        displayStack(parenthesesStack);

        // If the character is an opening parenthesis, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            parenthesesStack.push(ch);
        } 
        // If the character is a closing parenthesis
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty (no matching opening parenthesis)
            if (parenthesesStack.empty()) {
                return false;  // Unbalanced - closing parenthesis with no matching opening parenthesis
            }

            // Pop the top element from the stack
            char top = parenthesesStack.top();
            parenthesesStack.pop();

            // Check if the popped element is the corresponding opening parenthesis
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // Unbalanced - mismatched opening and closing parentheses
            }
        }
    }

    // Display the stack after traversing the entire string
    displayStack(parenthesesStack);

    // Check if there are any unmatched opening parentheses left in the stack
    return parenthesesStack.empty();
}

int main() {
    // Example usage:
    string expression = "(Skibidi Fortnite)";
    if (isBalanced(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are unbalanced." << endl;
    }

    return 0;
}

