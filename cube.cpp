#include <iostream>
using namespace std;

int cube(int a)
{
	int c=a*a*a;
	
	return c;
}
int main()
{
	int n;
	cout<<"ENTER A NUMBER TO FIND IT'S CUBE:  ";
	cin>>n;
	
	cout<<"The cube of "<<n<<" is "<<cube(n);
	
	return 0;
}
