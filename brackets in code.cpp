#include <iostream>
#include <stack>

using namespace std;

bool isValidStatement(string statement) {
    stack<char> brackets;

    for (int i = 0; i < statement.length(); i++) {
        char c = statement[i];

        if (c == '[' || c == '{' || c == '(') {
            brackets.push(c);
        } else if (c == ']' || c == '}' || c == ')') {
            if (brackets.empty()) {
                return false;
            }

            char top = brackets.top();
            brackets.pop();

            if ((c == ']' && top != '[') || (c == '}' && top != '{') || (c == ')' && top != '(')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main() {
    string statement = "[{()}]";
    if (isValidStatement(statement)) {
        cout << "Valid statement" << endl;
    } else {
        cout << "Invalid statement" << endl;
    }

    return 0;
}
