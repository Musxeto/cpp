#include<iostream>
using namespace std;

int main(){
	int size=10;
	int array[size]={1,2,3,4,5,6,7,8,9,0};
	
	int value;
	bool isfound=0;
	
	cout<<"Enter the value you want to find the value in:";
	cin>>value;

	
	for(int i=0;i<size;i++){
		if(value==array[i]){
			cout<<" The Value: "<<value<<"\n Exists at Index: "<<i;
			isfound=1;
			break;
		}
	}
	if(isfound==0){
		cout<<"Value Does not Exist in the Array";
	}
	
	
	return 0;
}
