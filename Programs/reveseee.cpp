#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Function to add an element to the end of the linked list
    void push_back(int element) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* temp = head;
        if (temp == NULL) {
            return;
        }
        Node* following = NULL;
        Node* previous = NULL;

        while (temp != NULL) {
            following = temp->next;
            temp->next = previous;

            previous = temp;
            temp = following;
        }
    
	    head = previous;
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    // Test the push_back function
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);

    // Display the elements in the linked list
    cout << "Original List:" << endl;
    myList.display();

    // Reverse the linked list
    myList.reverse();

    // Display the elements after reversal
    cout << "After Reverse:" << endl;
    myList.display();

    return 0;
}

