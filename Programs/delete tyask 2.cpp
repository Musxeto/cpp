#include<iostream>
using namespace std;

int main(){
	int x=1;
	int size=10;
	int array[size]={1,2,3,4,5,6,7,8,9,0};
	int del[size];
	int value;
	int index;
	char choice='0';
	bool noindex=0;
	
	while(true){
		cout<<"\nEnter the index you want to delete the value in:";
		cin>>index;
	
		while(index<0 || index >=size){
			for(int i=0;i<x;i++){
			if(index==del[i]){
				cout<<"Already Del"
				noindex=1;
			}
			}
			if(noindex=1){
				cout<<"\nWronf index! Try Again:";
			cin>>index;
			}
			else{
				break;
			}
		}
		
			for(int i=index;i<size;i++){
		array[i]=array[i+1];
	
	}
	array[size]= 0;
	
	for(int i=0;i<size-x;i++){
			cout<<array[i]<<",";
	}
	
	choice='0';
	
	while(choice!='n' && choice!='y'){
		cout<<"\nDo you Want to Delete another item??(y/n):";
		cin>>choice;
		del[x-1]=index;
		x++;
		system("CLS");
		if(choice!='n' && choice!='y'){
			cout<<"\nInvalid Choice!";
		}
	}
	if(choice=='n'){
		break;
	}
	
	}
	
	cout<<"Allah Hafiz";
	return 0;
}
