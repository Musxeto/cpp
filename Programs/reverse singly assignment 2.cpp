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
    
	void insert_at_end(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;

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
    
    void reverse_list() {
        Node* current = head;
        Node* previous = NULL;
        Node* following = NULL;

        while (current != NULL) {
            following = current->next;
            current->next = previous;
            previous = current;
            current = following;
        }

        head = previous;
    }
	
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
	LinkedList MyList;
	 
	for(int i=10;i<=30;i+=10){
        MyList.insert_at_end(i);
    }
    cout << "Original List:" << endl;
    MyList.display();
    
    cout << "Reversed List: "<< endl;
    MyList.reverse_list();
    MyList.display();
	
    return 0;
}


/*
Algorithm:
Initialize pointers:

Set current to the head of the list.
Set previous to NULL.
Set following to NULL.
Reverse the list:

While current is not NULL:
Save the next node in following.
Reverse the link by setting current's next to previous.
Move previous to current.
Move current to following.
Update the head:

Set the head of the list to previous.
Pseudocode:

function reverse_list():
    // Step 1
    current = head
    previous = NULL
    following = NULL

    // Step 2
    while current is not NULL:
        following = current.next   
        current.next = previous     
        previous = current          
        current = following        

    Step 3
    head = previous
    
*/

