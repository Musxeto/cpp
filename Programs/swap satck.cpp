#include <iostream>
#include <stack>
using namespace std;
void swapStacks(stack<int>& stack1, stack<int>& stack2) {
    stack<int> tempStack;
    while (!stack1.empty()) {
        tempStack.push(stack1.top());
        stack1.pop();
    }
    while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
    }
    while (!tempStack.empty()) {
        stack2.push(tempStack.top());
        tempStack.pop();
    }
}
int main() {
    stack<int> Stack1, Stack2;
    Stack1.push(9);
    Stack1.push(9);
    Stack1.push(9);
    
    Stack2.push(0);
    Stack2.push(0);
    Stack2.push(0);
    swapStacks(Stack1, Stack2);

    cout << "Stack1 after swap: ";
    while (!Stack1.empty()) {
        cout << Stack1.top() << " ";
        Stack1.pop();
    }
    cout << "\nStack2 after swap: ";
    while (!Stack2.empty()) {
        cout << Stack2.top() << " ";
        Stack2.pop();
    }
    return 0;
}

