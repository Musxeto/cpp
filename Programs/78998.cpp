#include <iostream>
using namespace std;

string result;
class String{
	public:
		string s;
	
		String(string a){
			s=a;
		}
		void displayString(){
			cout<<"String is:"<<s<<endl;
		}
};
string operator+(String s1 , String s2){
	return s1.s+s2.s;
}

int main() {
	String s1("lil");
	s1.displayString();
	String s2("Mus");
	s2.displayString();
	
	result=s1+s2;
	cout<<"After Adding the Strings it became:\n"<<result;
	return 0;
}
