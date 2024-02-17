#include<iostream>
using namespace std;
class wrestler
{
  private:
  	int losses;
  	
  public:
   int rank;
   char group; 
   int getdata(int n1);
   void printdata()
   {
   	cout<<"THE RANK OF THE WRESTLER IS:"<<rank;
   	cout<<"\nTHE GROUP OF THE WRESTLER IS:"<<group;
   	cout<<"\nTHE LOSSES OF THE WRESTLER Are:"<<losses<<endl;
   };
 
};
void wrestler :: getdata(int n1)
{
	cout<<"ENTER RANK OF THE LOSSES;";
	cin>>n1;
	losses = n1;
	
}
int main()
{
 wrestler john;
 cout<<"ENTER RANK OF THE WRESTLER;";
	cin>>john.rank;
 cout<<"ENTER Group OF THE WRESTLER;";
	cin>>john.group;	
 john.getdata(4);
 void printdata();
 return 0;
 
}

