#include<iostream>
using namespace std;

int age(int x[])
{
	int a=0,b=0;
	for(int i=0;i<6;i++)
	{
	a=a+x[i];
	b++;	
	}
	return a/b;	
}

int main()
{
	int a[6];
	
	for(int i=0;i<6;i++)
	{
		cout<<"\nENTER THE AGE OF PERSON "<<i+1<<": ";
		cin>>a[i];
	}
	cout<<"THE AVERAGE AGE IS :"<<age(a)<<"years";
	
	
}
