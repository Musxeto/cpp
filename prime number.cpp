#include<iostream>
using namespace std;
int main()
{
	int p=1,n,d=2;
	cout<<"ENTER A NUMBER TO CHECK WHETHER OR NOT IT'S A PRIME NUMBER>>  ";
	cin>>n;
	
	while(d<=n/2)
	{
		if(n%d==0)
		{
			p=0;
		}
		d++;
	}

	if(p==1)
	cout<<n<<" is a prime number";
	else
	cout<<n<<" is not prime number";
	
	return 0;
}
