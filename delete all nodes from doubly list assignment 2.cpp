

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
	// Delete All Nodes From The linked List
	
    void delete_all() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head->next;
        Node* aglaNode = NULL;
        head = NULL;
        
        while (temp != NULL) {
        	
            aglaNode = temp->next;
            delete temp;
            temp = aglaNode;
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
    myList.insert_at_end(12);
    myList.insert_at_end(34);
    myList.insert_at_end(55);
	
	cout << "Original List: ";
	myList.display();
	
	myList.delete_all();
	
	cout << "Empty List: ";
	myList.display();
    return 0;
}
/*
Pseudocode
procedure delete_all():
    if head is NULL:
        output "List is empty."
        return

    temp = head.next
    aglaNode = NULL

    head = NULL

    while temp is not NULL:
        aglaNode = temp.next

        delete temp
        temp = aglaNode

Algorithm:
Check if the list is empty:

If the list is empty (head is NULL), inform that the list is empty and stop.

Initialize pointers:

Set a temporary pointer (temp) to the node after the head.
Initialize another pointer (nextNode) to NULL.

Set head to NULL:

Set the head to NULL, effectively keeping only the head node in the list.

Loop through the remaining nodes and delete each one:

While the temporary pointer (temp) is not NULL:
Save the next node in nextNode to avoid losing the connection.
Delete the current node (temp).
Move to the next node by updating temp with the saved next node (nextNode).
*/

