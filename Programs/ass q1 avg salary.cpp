#include<iostream>
using namespace std;
int main()
{
	int array[10] ={2000, 2500, 1500, 3000, 3500, 2800, 2200, 1900, 3200, 2700};
	int avgSalary,i;
	for(int i=0;i<10;i++)
	{
	 avgSalary+=array[i];	
	}
	avgSalary=avgSalary/10;
	cout<<"THE AVG SLARAY IS:"<<avgSalary;
	return 0;
}
