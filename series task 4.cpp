#include<iostream>
using namespace std;
int sum(int n){
	int sum=0;
	for(int i=0;i<=n;i++){
		sum+=i;
	}
	return sum;	
}
int sum1(int n){
	int sum=(n*(n+1))/2;
	return sum;
}
int main(){
	int n=1321313;
	
	cout<<"\nThe Sum is :"<<sum(n);
	return 0;
}

