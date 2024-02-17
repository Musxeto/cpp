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

    void insert_at_front(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = head;

        head = newNode;
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

    void insert_at(int position, int newElement) {
        if (position <= 0) {
            cout << "Error: Invalid position for insertion." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = newElement;

        if (position == 1) {
            newNode->next = head;
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
        temp->next = newNode;
    }

    void delete_at_front() {
        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the front." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

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
        } else {
            head = temp->next;
        }

        delete temp;
    }

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
LinkedList merge_sorted_lists(Node* head1, Node* head2) {
    LinkedList mergedList;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data <= ptr2->data) {
            mergedList.insert_at_end(ptr1->data);
            ptr1 = ptr1->next;
        } else {
            mergedList.insert_at_end(ptr2->data);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        mergedList.insert_at_end(ptr1->data);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        mergedList.insert_at_end(ptr2->data);
        ptr2 = ptr2->next;
    }

    return mergedList;
}


int main() {
    LinkedList MyList1 , MyList2 , MergedList;
    int i = 1;
    while (i < 6) {
        MyList1.insert_at_end(i);
        i++;
    }
    while (i < 11) {
        MyList2.insert_at_end(i);
        i++;
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

