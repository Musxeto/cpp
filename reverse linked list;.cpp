#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
public:
    Node* head = NULL;

    LinkedList() {
        head = NULL;
    }

    void insert_at_end(int element) {
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
        newNode->prev = temp;

        return;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }

        cout << endl;
    }
    	void reverse(){
			
			Node* temp = NULL;
			Node* current = head;
			
			if(temp == NULL){
				cout<<"List Existence is just like my relationship(doesn't exist) ----";
				return;
			}
			if(temp->next == NULL){
				return;
			}
			
			while(temp->next!=NULL){
					next = temp->next;
					
					temp->prev->prev = temp;
					temp->next = temp->prev;
					temp->prev = next;
					
					temp = next;
				}
				
				head = temp->prev;
			
		}
};

int main() {
    LinkedList list;

    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(4);
    list.insert_at_end(5);

    cout << "Original List:" << endl;
    list.display();

	cout<<"Reversed List:"<<endl;
	list.reverse();
	list.display();
	
	return 0;
}
