#include<iostream>
using namespace std;

int findElement(int Array[],int element){
	bool found=0;
	for(int i;i<10;i++){
		if(Array[i]==element){
			cout<<endl<<"The Element:      "<<element<<"\nExists at Index: "<<i;
			found=1;
		}
	}
	if(found!=1){
		cout<<"Not Found in Array!";
	}
}

int main(){
	
	int Array[10]={10,10,20,12,12,20,10,39,16,39};
	int element;
	
	cout<<"\nEnter Element to find:";
	cin>>element;
	
	findElement(Array,element);
	
	return 0;
	
}
