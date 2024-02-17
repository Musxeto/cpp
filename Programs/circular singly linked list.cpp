#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularSinglyLinkedList {
public:
    Node* head;

    CircularSinglyLinkedList() {
        head = NULL;
    }

    // Insert a new element at the front of the circular singly linked list
    void insert_at_front(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = head;

        if (head != NULL) {
            // Find the last node to make it point to the new front
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        } else {
            // If the list is empty, make the new node point to itself
            newNode->next = newNode;
        }

        head = newNode;
    }

    // Insert a new element at the end of the circular singly linked list
    void insert_at_end(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;

        if (head == NULL) {
            // If the list is empty, make the new node point to itself
            newNode->next = newNode;
            head = newNode;
        } else {
            // Find the last node to make it point to the new end
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert a new element at a specific position in the circular singly linked list
    void insert_at(int position, int newElement) {
        if (position <= 0) {
            cout << "Error: Invalid position for insertion." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = newElement;

        if (position == 1) {
            insert_at_front(newElement);
            return;
        }

        Node* temp = head;
        int counter = 1;

        while (temp->next != head && counter < position - 1) {
            temp = temp->next;
            counter++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete the element at the front of the circular singly linked list
    void delete_at_front() {
        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the front." << endl;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        delete temp;
    }

    // Delete the element at the end of the circular singly linked list
    void delete_at_end() {
        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the end." << endl;
            return;
        }

        Node* temp = head;
        Node* last = head;
        Node* prev = NULL;

        while (last->next != head) {
            prev = last;
            last = last->next;
        }

        if (prev != NULL) {
            prev->next = head;
        } else {
            head = NULL;
        }

        delete temp;
    }

    // Delete the element at a specific position in the circular singly linked list
    void delete_at(int position) {
        if (position <= 0) {
            cout << "Error: Invalid position for deletion." << endl;
            return;
        }

        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the specified position." << endl;
            return;
        }

        if (position == 1) {
            delete_at_front();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int counter = 1;

        while (temp->next != head && counter < position) {
            prev = temp;
            temp = temp->next;
            counter++;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Search for a given element in the circular singly linked list
    void search(int element) {
        Node* temp = head;
        int i = 1;
        bool found = false;
        do {
            if (temp->data == element) {
                cout << " Value " << element << " found at Node: " << i << endl;
                cout << " Address: " << temp << endl;
                found = true;
            }
            temp = temp->next;
            i++;
        } while (temp != head);
        if (!found)
            cout << "Value Not Found!" << endl;
    }

    // Display the elements of the circular singly linked list
    void display() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        do {
            cout << temp->data << "\t";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularSinglyLinkedList myList;
    int choice;

    do {
        // Display the main menu
        cout << "\nMain Menu:" << endl;
        cout << "1. Create a Circular Singly Linked List" << endl;
        cout << "2. Insert at Front" << endl;
        cout << "3. Insert at End" << endl;
        cout << "4. Insert at Position" << endl;
        cout << "5. Delete at Front" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Delete at Position" << endl;
        cout << "8. Search" << endl;
        cout << "9. Display List" << endl;
        cout << "0. Exit" << endl;

        // Get user choice
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Create a Circular Singly Linked List
                int n, element;
                cout << "Enter the number of elements: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter element " << i + 1 << ": ";
                    cin >> element;
                    myList.insert_at_end(element);
                }
                cout << "Circular Singly Linked List created successfully." << endl;
                break;

            case 2:
                // Insert at Front
                cout << "Enter the element to insert at the front: ";
                cin >> element;
                myList.insert_at_front(element);
                cout << "Element inserted at the front." << endl;
                break;

            case 3:
                // Insert at End
                cout << "Enter the element to insert at the end: ";
                cin >> element;
                myList.insert_at_end(element);
                cout << "Element inserted at the end." << endl;
                break;

			case 4:
                // Insert at Position
                int position;
                cout << "Enter the position to insert at: ";
                cin >> position;
                cout << "Enter the element to insert: ";
                cin >> element;
                myList.insert_at(position, element);
                break;

            case 5:
                // Delete at Front
                myList.delete_at_front();
                cout << "Element deleted from the front." << endl;
                break;

            case 6:
                // Delete at End
                myList.delete_at_end();
                cout << "Element deleted from the end." << endl;
                break;

            case 7:
                // Delete at Position
                cout << "Enter the position to delete from: ";
                cin >> position;
                myList.delete_at(position);
                break;

            case 8:
                // Search
                cout << "Enter the element to search for: ";
                cin >> element;
                myList.search(element);
                break;

            case 9:
                // Display List
                myList.display();
                break;

            case 0:
                // Exit
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    return 0;
}

