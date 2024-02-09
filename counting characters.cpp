#include <iostream>
#include<conio.h>
using namespace std;
int main()
{
	char ch , a=1;
	string text;
	int occurences=0;
	 
	cout<<"ENTER A STRING: ";
	getline(cin , text);
	
	
	cout<<"\nEnter Character to find occurences: ";
	cin>>ch;
	
	for(int i=0;i<text.length();i++)
	{
		if(text[i]==ch)
		{
			occurences++;
		}
	}
	cout<<occurences<<" occurences";

return 0;	
}
