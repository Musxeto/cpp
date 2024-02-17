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
    
	void search_and_delete(int element) {
    if (head == NULL) {
        cout << "Error: List is empty." << endl;
        return;
    }

    Node* temp = head;
    int position = 1;
    bool found = false;

    
    while (temp != NULL) {
        if (temp->data == element) {
            cout << " Value " << element << " found at Node: " << position << endl;
            found = true;
            delete_at_position(position);
            break; 
        }
        temp = temp->next;
        position++;
    }

    if (!found)
        cout << "Value Not Found!" << endl;
}

		void delete_at_position(int position) {
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
	
	myList.search_and_delete();
	
	cout << "List After search_and_delete(): ";
	myList.display();
    return 0;
}

/*
Psuedocode:
procedure search_and_delete(element):
    if head is NULL:
        output "Error: List is empty."
        return

    temp = head
    position = 1
    found = false

    while temp is not NULL:
        if temp.data is equal to element:
            output "Value", element, "found at Node:", position
            found = true
            delete_at_position(position)
            exit loop

        temp = temp.next
        position = position + 1

    if not found:
        output "Value Not Found!"

procedure delete_at_position(position):
    if position is less than or equal to 0:
        output "Error: Invalid position for deletion."
        return

    if head is NULL:
        output "Error: List is empty. Cannot delete from the specified position."
        return

    temp = head
    prev = NULL
    counter = 1

    while temp is not NULL and counter is less than position:
        prev = temp
        temp = temp.next
        counter = counter + 1

    if temp is NULL:
        output "Error: Invalid position for deletion."
        return

    if prev is not NULL:
        prev.next = temp.next
        if temp.next is not NULL:
            temp.next.prev = prev
    else:
        head = temp.next
        if temp.next is not NULL:
            temp.next.prev = NULL

    delete temp
    
Algotrithm:

Check if the list is empty:

If the head is NULL, output an error message indicating that the list is empty and return.
Initialize pointers and variables:

Set a temporary pointer (temp) to the head.
Initialize a variable (position) to 1 to keep track of the node position.
Initialize a boolean variable (found) to false, indicating whether the element is found.
Search for the element:

While the temporary pointer (temp) is not NULL:
If the data in the current node is equal to the target element:
Output a message indicating the value is found at the current position.
Set found to true.
Call the delete_at_position procedure with the current position.
Exit the loop.
Handle not found case:

If the element is not found (found is false), output a message indicating that the value was not found.
delete_at_position Procedure:
Validate position:

Check if the specified position is less than or equal to 0.
If true, output an error message about an invalid position for deletion and return.
Check if the list is empty:

If the head is NULL, output an error message indicating that the list is empty and return.
Initialize pointers and variables:

Set a temporary pointer (temp) to the head.
Initialize a pointer (prev) to NULL to keep track of the previous node.
Initialize a counter (counter) to 1 to keep track of the current position.
Traverse to the specified position:

While the temporary pointer (temp) is not NULL and the counter is less than the specified position:
Update the prev pointer to the current node.
Move to the next node by updating temp.
Increment the counter.
Handle invalid position:

If the temporary pointer (temp) is NULL after traversal, output an error message about an invalid position for deletion and return.
Update pointers to bypass the node at the specified position:

If prev is not NULL, update its next pointer to skip the current node.
If the next node after the current node is not NULL, update its prev pointer to skip the current node.
Update head if necessary:

If prev is NULL, update the head to the next node after the current node.
Delete the node:

Delete the current node (temp).
*/

