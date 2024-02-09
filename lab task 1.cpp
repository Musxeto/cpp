#include<iostream>
using namespace std;

int main(){
	int size=10;
	int array[size]={1,2,3,4,5,6,7,8,9,0};
	
	int value;
	int index;
	
	cout<<"Enter the index you want to enter the value in:";
	cin>>index;
	
	while(index<0 || index >=size){
		
		cout<<"\nWronf index! Try Again:";
		cin>>index;
	}
	
	cout<<"Enter the Value:";
	cin>>value;
	
	
	for(int i=size;i>index;i--){
		array[i]=array[i-1];
	}
	array[index]= value;
	
	for(int i=0;i<size-1;i++){
			cout<<array[i]<<",";
	}
	
	
	return 0;
}
