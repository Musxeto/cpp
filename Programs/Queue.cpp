#include<iostream>
#include<conio.h>
using namespace std;

class Queue {
public:
    int arr[5];
    int rear = -1;
    int front = -1;

    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (rear == sizeof(arr) - 1) {
            return true;
        } else {
            return false;
        }
    }

	void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        } else if (isEmpty()) {
            rear = front = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else if (front == rear) {
            x = arr[front];
            front = rear = -1;
        } else {
            x = arr[front];
            front++;
        }
        return x;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        else{
        	return rear - front + 1;
		}
        
    }
};

int main() {
	Queue niceYar;
	int choice , element;

    do {
    	system("CLS");

        cout << "\nMain Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check For Empty" << endl;
        cout << "4. Check For Full" << endl;
        cout << "5. Display Queue" << endl;
        cout << "0. Exit" << endl;

        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	
            case 1:
                
                cout << "Enter the element to insert: ";
                cin >> element;
                niceYar.enqueue(element);
                cout << "Element inserted at the front." << endl;
                system("PAUSE");
                break;

            case 2:
            	
                niceYar.dequeue();
                cout << "Element dequeued from the front." << endl;
                system("PAUSE");
                break;
                
            case 3:
				if(niceYar.isEmpty()==true){
					cout<<"Queue is Empty!"<<endl;
				}
				else{
					cout<<"Queue is not Empty!";
				}
				system("PAUSE");
				break;
            
			case 4:
				if(niceYar.isFull()==true){
					cout<<"Queue is Full!"<<endl;
				}
				else{
					cout<<"Queue is not Full!";
				}
				system("PAUSE");
				break;
				
            case 5:
            	
                niceYar.display();
                system("PAUSE");
                break;
                
            case 0:
                
                cout << "Exiting the program." << endl;
                system("PAUSE");
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                system("PAUSE");
        }
    } while (choice != 0);
    
    return 0;
}
//    int getSize() {
//        if (isEmpty()) {
//            return 0;
//        } else {
//            return (rear - front + size) % size + 1;
//        }
//    }
