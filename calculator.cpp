#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char operation='0';
    double num1, num2;
    
    cout<<"\t\t\t-----\t----------\tW E L C O M E   T O   T H E   C A L C U L A T O R\t----------   -----"<<endl;
    cout<<"PRESS \"+\" FOR ADDTION."<<endl;
    cout<<"PRESS \"-\" FOR SUBTRACTION."<<endl;
    cout<<"PRESS \"*\" FOR MULTIPLICATION."<<endl;
    cout<<"PRESS \"/\" FOR DIVISION."<<endl;
    cout<<"PRESS \"%\" FOR PERCENTAGE."<<endl;
    cout<<"PRESS \"s\" FOR SQUARE."<<endl;
    cout<<"PRESS \"r\" FOR SQUARE ROOT."<<endl;
    cout<<"PRESS \"f\" FOR FACTORIAL."<<endl;
    cout<<"PRESS \"x\" to Exit."<<endl;
    
    while(operation!='x'){
	operation='1';
    
    
    cout << "Enter an operation (+, -,*, /,%,s, r,f) or Press \"x\" to exit: "<<endl;
    enter:
    cin >> operation;
    if (operation != 's' || operation != 'r'||operation!='f'||operation != '/' || operation != '+'||operation!='-'||operation != '*' || operation != '%'||operation!='x'){
       goto Default;
	}
	}
    if (operation=='x'){
    break;
    }
    if (operation == 's' || operation == 'r'||operation=='f') {
        cout << "Enter a number: ";
        cin >> num1;

        if (operation == 's') {
            cout << "Square: " << num1 * num1 << endl;
         }  else if (operation == 'r') {
                 if (num1 < 0) {
                    cout << "Cannot calculate square root of a negative number." << endl;
                    } 
			     else {
                     cout << "Square Root: " << sqrt(num1) << endl;
                      }
                }
        else if(operation=='f'){
        	float factorial=1;
        	if (num1 < 0)
             cout << "Error! Factorial of a negative number doesn't exist.";
            else {
                for(int i = 1; i <= num1; ++i) {
                   factorial *= i;
                }
                cout << "Factorial of " << num1 << " = " << factorial;    
                 }
		 }
    }
	else if(operation=='%'){
		cout<<"Enter total value:";
		cin>>num1;
		cout<<"Enter the Value for which the percentage is required:";
		cin>>num2;
		
		cout<<"Percentage:\t"<<(num2*100)/num1;
	}
	
	 else {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                cout << "Sum: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Difference: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Product: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Quotient: " << num1 / num2 << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                break;
            
            default:
            	Default:
                cout << "Invalid operation. Enter a valid operator:" << endl;
                goto enter;
        }
    }
}
}
}
    cout<<endl<<"\t\t\t T H A N K S   G O O D B Y E ";
    return 0;
}

