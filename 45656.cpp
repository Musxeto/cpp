#include <iostream>
using namespace std;

class Fraction{
	private:
		double numerator=0;
		double denominator=0;
	public:
		double result;
		Fraction(double n,double d){
			numerator = n;
			denominator = d;
		}
	double Result(){
		return numerator+denominator;
	}
		
};

int main() {
	Fraction f1(9.0,8.0);
	f1.Result();
 
	
	return 0;
}
