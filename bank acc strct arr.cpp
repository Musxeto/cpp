#include<iostream>
using namespace std;

struct BankAccount{
	int AccountNumber;
	float Balance;
};

struct Customer{
	string FirstName;
	string LastName;
	BankAccount bankaccount;
};

int main()
{
	int i;
	BankAccount ba[2];
	for(i=0;i<2;i++)
	{
		cout<<"BANK ACC No. "<<i+1<<" :";
		cin>>ba[i].AccountNumber;
		
		cout<<"BANK ACC "<<i+17<<"BALANCE :";
		cin>>ba[i].Balance;
		cout<<"------------------------------------------"<<endl;
	}
	/*bankaccout1.AccountNumber=4565674567;
	bankaccout1.Balance=467537563.46;*/
	
	BankAccount bankaccout2;
	/*bankaccout2.AccountNumber=7657448776;
	bankaccout2.Balance=56738495683.2343454;*/
	struct Customer c[2];
	for(i=0;i<2;i++)
	{
		cout<<"Customer "<<i+1<<" First Name :";
		cin>>c[i].FirstName;
		cout<<"Customer "<<i+1<<" Last Name :";
		cin>>c[i].LastName;
		c[i].bankaccount = ba[i];
		cout<<"------------------------------------------"<<endl;
	}
	for(i=0;i<2;i++)
	{
		cout<<"CUSTOMER "<<i+1<<" INFO:"<<endl;
		cout<<"Customer First Name :"<<c[i].FirstName<<endl;
		cout<<"Customer Last Name :"<<c[i].LastName<<endl;
		cout<<"BANK ACC No. :"<<ba[i].AccountNumber<<endl;
		cout<<"BANK ACC BALANCE :"<<ba[i].Balance<<endl;
		cout<<"------------------------------------------"<<endl;
	}
	return 0;
}
