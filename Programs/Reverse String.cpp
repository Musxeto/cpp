#include <iostream>
#include <stack>

using namespace std;

string reverseString(const string& input) {
    stack<char> charStack;

    for (int i = 0; i < input.length(); i++) {
        charStack.push(input[i]);
    }

    string reversedString;

    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

int main() {
    string input = "nul";
    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}

