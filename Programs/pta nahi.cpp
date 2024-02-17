#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    // You may have other members as needed
};

Node* head = nullptr;

void pop_front() {
    if (head != nullptr) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* firstNode = head;
            head = head->next;
            temp->next = head;
            delete firstNode;
        }
    }
}

void pop_back() {
    if (head != nullptr) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* lastNode = temp->next;
            temp->next = head;
            delete lastNode;
        }
    }
}
void pop_at(int position) {
    if (head == nullptr || position <= 0) {
        // Invalid position or empty list
        return;
    }

    if (position == 1) {
        // Remove the first node if position is 1
        pop_front();
        return;
    }
	int NoOfElements = 0;
    Node* temp = head;
    while(temp!= head){
    	NoOfElements++;
    	temp = temp->next;
	}

    if (temp == nullptr || temp->next == head) {
        // Position exceeds the size of the list
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
// Function to print the elements of the circular linked list
void printList() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    // Example usage
    // Create a circular linked list for testing
    head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head; // Make it circular

    cout << "Original List: ";
    printList();

    // Remove the node at position 2
    pop_at(2);

    cout << "List after pop_at(2): ";
    printList();

    // Cleanup: delete remaining nodes
    while (head != nullptr) {
        pop_front();
    }

    return 0;
}

