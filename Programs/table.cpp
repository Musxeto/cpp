#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter a number to write it's table'\t";
	cin>>n;
	
	for(int i=1;i<=10;i++)
	{
		cout<<n<<"*"<<i<<"="<<i*n<<endl;
		for(int j=1;j<=5;j++)
		{
			cout<<"_";
		}
		cout<<endl;
	}
	return 0;
}
