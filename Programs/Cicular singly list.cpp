#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class linkedList{
	public:
		Node* head;
		linkedList(){
			head=NULL;
		}
		void insert_at_head(int val)
        {
            Node*newnode=new Node();
            newnode->data=val;
            if (head==NULL)
            {
                head=newnode;
                newnode->next=head;
            }
            else 
            {
                newnode->next=head;
                Node*temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                head=newnode;
                temp->next=head;
            }
        }
        void insert_at_last(int val)
        {
            Node *newnode=new Node;
            newnode->data=val;
            if (head==NULL)
            {
                head=newnode;
                newnode->next=head;
            }
            else 
            {
                Node*temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                newnode->next=head;
                temp->next=newnode;
                
            }
        }
        void insert_at_index(int val,int index)
        {
            int count=0;
            Node*newnode=new Node();
            newnode->data=val;
            Node*temp=head;
            if (temp!=NULL)
            {
              count++;
              temp=temp->next;  
            }
            while(temp!=head)
            {
                count++;
                temp=temp->next;
            }
            if (index<1||index>count)
            {
                cout <<"invalid position\n";
            }
            else if (head==NULL&&index==1)
            {
                head=newnode;
                newnode->next=head;
            }
            else 
            {
                int i=1;
                Node * t=head;
                Node * p=t->next;
                while (i!=index-1)
                {
                    t=t->next;
                    p=p->next;
                    i++;
                }
                t->next=newnode;
                newnode->next=p;
                
            }
        }
        void deleteHead()
        {
            if(head->next==head&&head!=NULL)
            head=NULL;
            else
            {
                Node*temp=head;
                Node*nodetodel=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                head=head->next;
                temp->next=head;
                delete nodetodel;
            }
        
        }
        void delete_last()
        {
            if (head->next==head)
            head=NULL;
            else
            {
                Node*temp=head;
                while(temp->next->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=head;
                delete temp->next;
            }
        }
        void deleteatpos(int pos)
        {
            Node*ptr=head;
           Node*nodetodelete=ptr->next ;
           Node*temp=head;
           int noofcount=0;
           if(temp!=NULL)
           {
               noofcount++;
               temp=temp->next;
           }
           while(temp!=head)
           {
               noofcount ++;
               temp=temp->next;
           }
           if(noofcount==1&&pos==1)
           {
               head=NULL;
           }
           else if(pos<1||pos>noofcount)
           {
               cout <<"invqlid position\n";
           }
           else 
           {
               int i=1;
               
               while(i<pos-1)
               {
                  ptr=ptr->next;
                  nodetodelete=nodetodelete->next; 
                  i++;
               }
               ptr->next=nodetodelete->next;
               delete nodetodelete;
           }
           
        }
		void display(){
			if(head==NULL){
				cout<<"Empty Linked List!\n";
			}
			else{
				Node* temp=head;
                int i=1;
			//cout<<"The linked list contains: \n";
                cout <<i<<": Element: "<<temp->data<<" head\n";
                temp=temp->next;
                i++;
				while (temp!=head)
                {
					cout <<i<<": Element: "<<temp->data<<"\n";
                    i++;
					temp=temp->next;
				}
			}
		}
};
int main(){
	linkedList L1;
	Node*first=new Node();
    Node*second=new Node();
    Node*third=new Node();
    Node*fourth=new Node();
    first->data=5;
    second->data=6;
    third->data=7;
    fourth->data=8;
    L1.head=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=first;
    cout<<"original linked list\n";
    L1.display();
    cout <<"after insert 4 at head\n";
    L1.insert_at_head(4);
    L1.display();
    cout <<"after insert 3 at last\n";
    L1.insert_at_last(3);
	L1.display();
    int value=20;
    int index=5;
    cout <<"after insert "<<value <<" at index "<<index<<endl;
    L1.insert_at_index(value,index);
    L1.display();
    cout <<"after deleting head node\n";
    L1.deleteHead();
    L1.display();
    cout <<"after deleting last Node\n";
    L1.delete_last();
    L1.display();
    cout <<"after deleting node at position 3\n";
    L1.deleteatpos(3);
    L1.display();
    return 0;
}

