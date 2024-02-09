#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};
class LinkedList{
	public:
		Node* head;
		LinkedList(){
			head = NULL;
		}
		
		void PrintList(){
				Node* temp = head;
				if(temp!= NULL){
					cout<<"The List Contains: "<<endl;
					while(temp != NULL){
						cout<<"|Value: "<<temp->data<<"|";
						cout<<"Address: "<<&temp->next<<"|"<<endl;
						temp = temp->next;
					}
					
					cout<<endl;
				}
				else{
					cout<<"THE LIST ENDED!"<<endl;
				}
		}
};

int main(){
		LinkedList MyList;
		
		Node* first = new Node();
		first -> data = 10;
		first -> next = NULL;
		
		MyList.head = first;
		
		Node* second = new Node();
		second -> data = 20;
		second -> next = NULL;
		
		first -> next = second;
		
		Node* third = new Node();
		third -> data = 30;
		third -> next = NULL;
		
		second -> next = third;
		
		Node* fourth = new Node();
		fourth -> data = 40;
		fourth -> next = NULL;
		
		third -> next = fourth;
		
		Node* fifth = new Node();
		fifth -> data = 50;
		fifth -> next = NULL;
		
		fourth -> next = fifth;
		
		MyList.PrintList();
		return 0;
}
