#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int n){
	int d=2;
	for(d=2;d*d<=n;d++){
		if(n%d==0){
			return 0;   
		}
      }
      return 1;
}
int main() {
	int a;
	int b;
	
	cout<<"1st Number: ";
	cin>>a;
	cout<<"2nd Number: ";
	cin>>b;
	
	
	cout<<"Prime Numbers:"<<endl;;
	for(int i=a;i<=b;i++){
	 if(isPrime(i)){
	 	cout<<i<<endl;
	 }
	}
	
	return 0;
}
