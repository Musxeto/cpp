#include <iostream>
using namespace std;
int main()
{
	int i,j,k,n=4,m;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<"  ";
		}
		for(int k=i,m=1;k<=n;k++,m++)
		{
			cout<<m<<" ";
		}
		cout<<endl;
	}
}
