#include <iostream>
using namespace std;
int main()
{
	int i,j,n;
	cout<<"enter the size of triangle>>  ";
    cin>>n;
    
    cout<<"The number triangle is;"<<endl;
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=i;j++)
    	{
    	 	cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
