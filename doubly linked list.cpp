#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Insert a new element at the front of the doubly linked list
    void insert_at_front(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Insert a new element at the end of the doubly linked list
    void insert_at_end(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert a new element at a specific position in the doubly linked list
    void insert_at(int position, int newElement) {
        if (position <= 0) {
            cout << "Error: Invalid position for insertion." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = newElement;

        if (position == 1) {
            newNode->next = head;
            newNode->prev = NULL;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        int counter = 1;

        while (temp != NULL && counter < position - 1) {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL) {
            cout << "Error: Invalid position for insertion." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    // Delete the element at the front of the doubly linked list
    void delete_at_front() {
        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the front." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    // Delete the element at the end of the doubly linked list
    void delete_at_end() {
        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the end." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
        } else {
            head = NULL;
        }

        delete temp;
    }

    // Delete the element at a specific position in the doubly linked list
    void delete_at(int position) {
        if (position <= 0) {
            cout << "Error: Invalid position for deletion." << endl;
            return;
        }

        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the specified position." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int counter = 1;

        while (temp != NULL && counter < position) {
            prev = temp;
            temp = temp->next;
            counter++;
        }

        if (temp == NULL) {
            cout << "Error: Invalid position for deletion." << endl;
            return;
        }

        if (prev != NULL) {
            prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = prev;
            }
        } else {
            head = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = NULL;
            }
        }

        delete temp;
    }

    // Search for a given element in the doubly linked list
    void search(int element) {
        Node* temp = head;
        int i = 1;
        bool found = false;
        while (temp != NULL) {
            if (temp->data == element) {
                cout << " Value " << element << " found at Node: " << i << endl;
                cout << " Address: " << temp << endl;
                found = true;
            }
            temp = temp->next;
            i++;
        }
        if (!found)
            cout << "Value Not Found!" << endl;
    }

    // Reverse the doubly linked list
    void reverse_list() {
        Node* current = head;
        Node* temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != NULL) {
            head = temp;
        }
    }

    // Display the elements of the doubly linked list
    void display() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;
    int choice;

    do {
        // Display the main menu
        cout << "\nMain Menu:" << endl;
        cout << "1. Create a Doubly Linked List" << endl;
        cout << "2. Insert at Front" << endl;
        cout << "3. Insert at End" << endl;
        cout << "4. Insert at Position" << endl;
        cout << "5. Delete at Front" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Delete at Position" << endl;
        cout << "8. Search" << endl;
        cout << "9. Reverse List" << endl;
        cout << "10. Display List" << endl;
        cout << "0. Exit" << endl;

        // Get user choice
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Create a Doubly Linked List
                int n, element;
                cout << "Enter the number of elements: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter element " << i + 1 << ": ";
                    cin >> element;
                    myList.insert_at_end(element);
                }
                cout << "Doubly Linked List created successfully." << endl;
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
                // Reverse List
                myList.reverse_list();
                cout << "Doubly Linked List reversed." << endl;
                break;

            case 10:
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


