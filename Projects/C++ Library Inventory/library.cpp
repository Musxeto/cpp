#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <conio.h>
using namespace std;

int choice;
class User{
	public:
		string username;
		string password;
		
		string getUsername() {
        return username;
        }
        string getPassword() {
        return password;
        }
};
User registration() {
    User newuser;
    cout<<"WELCOME NEW USER!!!";
	cout << "Enter Username(case sensitive): ";
    getline(cin, newuser.username);
    cout << "Enter Password(case sensitive: ";
    getline(cin, newuser.password);
    cout<<"ACCOUNT REGISTERED!!!\n";
    return newuser;
}
void saveUsersToFile(const vector<User>& users) {
    ofstream outFile("users.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (size_t i = 0; i < users.size(); ++i) {
        const User& user = users[i];
        outFile << user.username << "," << user.password << "\n";
    }

    outFile.close();
}
void loadUsersFromFile(vector<User>& users) {
    ifstream inFile("users.txt");
    if (!inFile) {
        cout << "File doesn't exist or couldn't be opened." << endl;
        return;
    }

    users.clear();
    string line;
    while (getline(inFile, line)) {
        User user;
        stringstream ss(line);
        
        getline(ss, user.username, ',');
        getline(ss, user.password, ',');
        
        users.push_back(user);
    }
    inFile.close();
}
class Book {
public:
    string name;
    string ID;
    string writer;
    string genre;

    void getBook() {
        cout << "Name : " << name << endl;
        cout << "ID : " << ID << endl;
        cout << "Writer : " << writer << endl;
        cout << "Genre : " << genre << endl;
    }
};

class LentBook : public Book {
public:
    string lenderName;
    string lenderAge;
    string lenderID;
};

Book addBook() {
    Book newbook;
    cout << "\nEnter Name of the New Book:";
    getline(cin,newbook.name);
    
    cout << "\nEnter ID of the New Book(case sensitive):";
    getline(cin,newbook.ID);
    
    cout << "\nEnter Writer of the New Book:";
    getline(cin,newbook.writer);
    
    cout << "\nEnter Genre of the New Book:";
    getline(cin,newbook.genre);
    cin.ignore();

    return newbook;
}

void viewBook(vector<Book>& book) {
    for (size_t i = 0; i < book.size(); i++) {
        cout << "Name: " << book[i].name << endl;
        cout << "Writer: " << book[i].writer << endl;
        cout << "Genre: " << book[i].genre << endl;
        cout << "ID: " << book[i].ID << endl;
    }
    getch();
}


void saveBooksToFile(vector<Book>& book) {
    ofstream outfile("books.txt");
    if (!outfile.is_open()) {
        cout << "ERROR OPENING File";
    } else {
        for (size_t i = 0; i < book.size(); i++) {
            const Book& books = book[i];
            outfile << books.name << "," << books.writer << "," << books.genre << "," << books.ID << "\n";
        }
        outfile.close(); 
    }
}
void loadBooksFromFile(vector<Book>&book){
	ifstream infile("books.txt");
	if (!infile.is_open()) {
        cout << "ERROR OPENING File";
    } 
	else {
		book.clear();
        string line;
         while(getline(infile,line)){
         	Book thebooks;
         	stringstream ss(line);
         	
         	getline(ss,thebooks.name,',');
         	getline(ss,thebooks.writer,',');
         	getline(ss,thebooks.genre,',');
         	getline(ss,thebooks.ID,',');
         	
         	book.push_back(thebooks);
		 }
	
	}
    infile.close();
}
void findBookByName(vector<Book>& book) {
    string namefind;
    cout << "Enter Name:";
    getline(cin, namefind);

    for (size_t i = 0; i < namefind.length(); i++) {
        namefind[i] = toupper(namefind[i]);
    }

    bool found = false;
    for (size_t i = 0; i < book.size(); i++) {
        string bookName = book[i].name;
        for (size_t j = 0; j < bookName.length(); j++) {
            bookName[j] = toupper(bookName[j]);
        }

        if (bookName == namefind) {
            system("CLS");
            cout << "BOOK FOUND!!!" << endl;
            cout << "NAME: " << book[i].name << endl;
            cout << "WRITER: " << book[i].writer << endl;
            cout << "GENRE: " << book[i].genre << endl;
            cout << "ID: " << book[i].ID << endl;
            found = true;
            getch();
            break; 
        }
    }

    if (!found) {
        system("CLS");
        cout << "Book Not Found!" << endl;
        cout << "Try Again?" << endl;
        cout << "1. Yes" << endl;
        cout << "0. NO" << endl;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            system("CLS");
            findBookByName(book);
        } else if (choice == 0) {
            system("CLS");
            
        } else {
            cout << "INVALID CHOICE!" << endl;
            cout << "Returning to Menu!!!" << endl;
        }
    }
}

bool findUser(vector<User>& users, string loginUsername, string loginPassword) {
    
	for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].username == loginUsername && users[i].password == loginPassword) {
            return 1;
        }
    }
    return 0;
}
void findBookById(vector<Book> &book){
	string IDfind;
	cout<<"ENTER ID>> ";
	getline(cin,IDfind);
	
	    bool found = false;
    for (size_t i = 0; i < book.size(); i++) {
        
        if (IDfind == book[i].ID) {
            system("CLS");
            cout << "BOOK FOUND!!!" << endl;
            cout << "NAME: " << book[i].name << endl;
            cout << "WRITER: " << book[i].writer << endl;
            cout << "GENRE: " << book[i].genre << endl;
            cout << "ID: " << book[i].ID << endl;
            found = true;
            getch();
            break; 
        }
    }

    if (!found) {
        system("CLS");
        cout << "Book Not Found!" << endl;
        cout << "Try Again?" << endl;
        cout << "1. Yes" << endl;
        cout << "0. NO" << endl;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            system("CLS");
            findBookById(book);
        } else if (choice == 0) {
            system("CLS");
            
        } else {
            cout << "INVALID CHOICE!" << endl;
            cout << "Returning to Menu!!!" << endl;
        }
    }
}
int main() {
		vector<User> users;
    vector<Book> book;
    loadBooksFromFile(book);
    int choice=0;
    bool exit=0;
    bool loggedIn=0;
    char aisehi;
    string uzername,pass;
    while (true){
    	system("CLS");
    	loadUsersFromFile(users);
    	cout<<"------------------------------------------------------\n";
    	cout<<"WELCOME!!"<<endl;
    	cout << "1. Login" << endl;
        cout << "2. SignUp" << endl;
        cout << "3. Exit" << endl;
        cout << "---------------------------------------------------\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore();
        loadUsersFromFile(users);
        
        switch(choice){
        	
        	case 1:
        	
        		system("CLS");
        		cout<<"LOGIN!!!";
        		cout<<"\nEnter Username(case senstive): ";
        		cin>>uzername;
        		cout<<"\nEnter Password(case senstive): ";
        		cin>>pass;
        		cin.ignore();
        		if(findUser(users,uzername,pass)){
        			cout<<"LOGGED IN SUCCESSFULLY!"<<endl;
        			loggedIn=1;
				}
				else{
					cout<<"Invalid Username or Password!!!";
					cout<<"Any Key To Continue";
					aisehi=getch();
				}
        		break;
        	case 2:
        		{
				
        		system("CLS");
        		User newuser=registration();
        		users.push_back(newuser);
        		saveUsersToFile(users);
        		cout<<"PRESS ANY KEY TO CONTINUE:";
        		aisehi=getch();
        		break;
        	}
        	case 3:
        		system("CLS");
        		cout << "Thanks For Using This Tool" << endl;
        		return 0;
        		break;
        	default:
        	system("CLS");
            cout << "Invalid :(" << endl;
            break;
        		
		}
	if(loggedIn==1){
	

    
    while(exit==0){
    	system("CLS");
    	cout<<"\t\t\t---BOOK INVENTORY---";
        cout<<"\n1. VIEW B00KS";
        cout<<"\n2. ADD BOOKS";
        cout<<"\n3. FIND BOOKS ";
        cout<<"\n4.EXIT";
        cout<<"\n Enter Choice>> ";
        cin>>choice;
        cin.ignore();
    
    switch(choice){
    	case 1:
    		system("CLS");
    		viewBook(book);
    		break;
    	case 2:
    		system("CLS");
    		book.push_back(addBook());
    		saveBooksToFile(book);
			break;
		case 3:
    system("CLS");
    cout << "1. SEARCH BY ID!" << endl;
    cout << "2. SEARCH BY NAME!" << endl;
    cout << "Enter Choice => ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            system("CLS");
            findBookById(book);
            break;
        case 2:
            system("CLS");
            findBookByName(book);
            break;
        default:
            system("CLS");
            cout << "INVALID CHOICE!!" << endl;
            getch();
            break;
    }
    break; 

			
		case 4:
			system("CLS");
		    cout<<"\nExting!!!";
            exit=1;
			return 0;
		default:
		    cout<<"\nInvalid Choice!!!";	
	}
	}
}
}
    return 0;
}

