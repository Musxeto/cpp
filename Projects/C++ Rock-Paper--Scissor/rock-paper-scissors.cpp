#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>

using namespace std;

string computerchoice(){
	
	srand(static_cast<unsigned int>(time(NULL)));
    int random = rand() % 3 + 1;
	if(random==1){
		return "Rock";
	}
	else if(random==2){
		return "Paper";
	}
	else if(random==3){
		return "Scissors";
	}
}
void compare(string user,string computer){
	
	if(user=="Rock"){
		if(computer=="Rock"){
			cout<<"TIE!!!";
		}
		else if(computer=="Paper"){
			cout<<"YOU LOST!!!!";
		}
		else if(computer=="Scissors"){
			cout<<"YOU WON!!!";
		}
	}
	else if(user=="Paper"){
		if(computer=="Rock"){
			cout<<"YOU WON!!!";
		}
		else if(computer=="Paper"){
			cout<<"TIE!!!";
		}
		else if(computer=="Scissors"){
			cout<<"YOU LOST!!!!";
		}
		
	}
	else if(user=="Scissors"){
		if(computer=="Rock"){
			cout<<"YOU LOST!!!!";
		}
		else if(computer=="Paper"){
			cout<<"YOU WON!!!";
		}
		else if(computer=="Scissors"){
			cout<<"TIE!!!";
		}
	}
}

int main() {
	string computer;
	string user="0";
	int choose;
	char choice='y';
	system("CLS");
	cout<<"READY TO PLAY??\n";
	cout<<"y:YES!\nn:NO!\n";
	cin>>choice;
	while(choice=='y'||choice=='Y'){
	
    computer=computerchoice();
	do{
		system("CLS");
		cout<<"YOUR CHOICE!?\n";
		cout<<"1:ROCK\n2:PAPER\n3:SCISSORS\nEnter Choice>>:";
		cin>> choose;
	
		if(choose==1){
			user= "Rock";
		}
		else if(choose==2){
			user= "Paper";
		}
		else if(choose==3){
			user= "Scissors";
		}
		else{
			system("CLS");
			cout<<"INVALID CHOICE!!";
			user="0";
			cout<<"PRESS ANY KEY TO CONTINUE";
			getch();
		}
		
    }while(user=="0");
	system("CLS");
	cout<<"YOUR CHOICE:\t\tCOMPUTER'S CHOICE:\n";
	cout<<"\t  "<<user<<"\t\t\t  "<<computer<<endl;
	
	compare(user,computer);
	getch();
	system("CLS");
	cout<< "PLAY AGAIN!?\n";
	cout<<"y:YES!\nn:NO!\n";
	cin>>choice;
    }
    system("CLS");
    cout<<"THANKS FOR PLAYING!!!";
	return 0;
}

