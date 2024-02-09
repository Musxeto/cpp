#include<iostream>
#include<queue>
using namespace std;
int main(){
	priority_queue <int> q;
	q.push(100);
	q.push(3);
	q.push(300);
	q.push(40);
	q.push(500);
	cout<<"Top: "<<q.top()<<endl;
	q.pop();
	cout<<"Top: "<<q.top()<<endl;
	return 0;
}
