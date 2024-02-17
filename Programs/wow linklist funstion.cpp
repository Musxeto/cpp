#include <iostream>
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

    void PrintList() {
        Node* temp = head;
        if (temp != NULL) {
            cout << "The List Contains: " << endl;
            while (temp != NULL) {
                cout << "|Value: " << temp->data << "|";
                cout << "Address: " << temp << "|" << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "THE LIST ENDED!" << endl;
        }
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
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    
};

int main() {
    LinkedList MyList;
    int n, i, value;
    cout << "How many values do you want to enter in the list?" << endl;
    cin >> n;

    for (i = 1; i <= n; i++) {
        cout << "Enter Value for Node " << i << " : ";
        cin >> value;
        MyList.insert_at_front(value);
    }
	cout<<"INSERT VALUE AT END: ";
	cin>>value;
    MyList.insert_at_end(value);
	cout<<endl;
	
    MyList.PrintList();

    return 0;
}

