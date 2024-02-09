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

LinkedList merge_lists(Node* head1, Node* head2) {
    LinkedList mergedList;

    Node* temp = head1;

    while (temp != NULL) {
        mergedList.insert_at_end(temp->data);
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        mergedList.insert_at_end(temp->data);
        temp = temp->next;
    }

    return mergedList;
}

int main() {
    LinkedList MyList1 , MyList2 , MergedList;
    int i = 1;
    for(int i=10;i<=30;i+=10) {
        MyList1.insert_at_end(i);
    }
    for(i=40;i<=60;i+=10) {
        MyList2.insert_at_end(i);
    }
    cout << "Original List 1:" << endl;
    MyList1.display();
	
	cout << "Original List 2:" << endl;
    MyList2.display();
    
    cout<< "Merged List: "<<endl;
    MergedList = merge_lists(MyList1.head , MyList2.head);
	MergedList.display();
    return 0;
}
/*
Algorithm:
Initialize merged list:

Create a new linked list named mergedList.
Merge elements from the first list (head1):

Set a temporary pointer temp to the head of the first list (head1).
While temp is not NULL:
Insert the data of the current node into mergedList.
Move temp to the next node.
Merge elements from the second list (head2):

Set temp to the head of the second list (head2).
While temp is not NULL:
Insert the data of the current node into mergedList.
Move temp to the next node.
Return the merged list.

Pseudocode:
function merge_lists(head1, head2):
    // Step 1
    mergedList = new LinkedList()

    // Step 2
    temp = head1
    while temp is not NULL:
        mergedList.insert_at_end(temp.data)
        temp = temp.next

    // Step 3
    temp = head2
    while temp is not NULL:
        mergedList.insert_at_end(temp.data)
        temp = temp.next

    // Step 4
    return mergedList
*/

