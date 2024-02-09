#include<iostream>
using namespace std;
int LinearSearch(int arr[],int n,int x){
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			return i;
		}
		return -1;
	}
}
int main(){
	int n;
	cout<<"\n   Enter the Size of Array";
	cin>>n;
	
	int A[n],e,i,index;
	cout<<"\n	Enter Values of the Array:";
	
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<"\nEnter the Element to be Found:";
	cin>>e;
	
	index=LinearSearch(A,n,e);
	
	if(index==-1){
		cout<<"not found\n";
	}
	else{
		cout<<"Found at Index:"<<index;
	}
	return 0;
}
