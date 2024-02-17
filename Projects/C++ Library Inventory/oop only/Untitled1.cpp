#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <conio.h>
using namespace std;

const int MAX_USERS = 100;
const int MAX_BOOKS = 100;

class User {
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

class LibrarySystem {
private:
    User users[MAX_USERS];
    Book books[MAX_BOOKS];
    int userCount;
    int bookCount;

public:
    LibrarySystem() : userCount(0), bookCount(0) {}

    User registration() {
        User newuser;
        cout << "WELCOME NEW USER!!!";
        cout << "\nEnter Username(case sensitive): ";
        getline(cin, newuser.username);
        cout << "Enter Password(case sensitive): ";
        getline(cin, newuser.password);
        cout << "ACCOUNT REGISTERED!!!\n";
        return newuser;
    }

    void saveUsersToFile() {
        ofstream outFile("users.txt");
        if (!outFile) {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (int i = 0; i < userCount; ++i) {
            const User& user = users[i];
            outFile << user.username << "," << user.password << "\n";
        }

        outFile.close();
    }

    void loadUsersFromFile() {
        ifstream inFile("users.txt");
        if (!inFile) {
            cout << "File doesn't exist or couldn't be opened." << endl;
            return;
        }

        userCount = 0;
        string line;
        while (getline(inFile, line) && userCount < MAX_USERS) {
            User& user = users[userCount++];
            stringstream ss(line);

            getline(ss, user.username, ',');
            getline(ss, user.password, ',');
        }

        inFile.close();
    }

    Book addBook() {
        Book newbook;
        cout << "\nEnter Name of the New Book:";
        getline(cin, newbook.name);

        cout << "\nEnter ID of the New Book(case sensitive):";
        getline(cin, newbook.ID);

        cout << "\nEnter Writer of the New Book:";
        getline(cin, newbook.writer);

        cout << "\nEnter Genre of the New Book:";
        getline(cin, newbook.genre);
        cin.ignore();

        return newbook;
    }

    void viewBook() {
        for (int i = 0; i < bookCount; i++) {
            cout << "Name: " << books[i].name << endl;
            cout << "Writer: " << books[i].writer << endl;
            cout << "Genre: " << books[i].genre << endl;
            cout << "ID: " << books[i].ID << endl;
        }
        getch();
    }

    void saveBooksToFile() {
        ofstream outfile("books.txt");
        if (!outfile.is_open()) {
            cout << "ERROR OPENING File";
        } else {
            for (int i = 0; i < bookCount; i++) {
                const Book& theBook = books[i];
                outfile << theBook.name << "," << theBook.writer << "," << theBook.genre << "," << theBook.ID << "\n";
            }
            outfile.close();
        }
    }

    void loadBooksFromFile() {
        ifstream infile("books.txt");
        if (!infile.is_open()) {
            cout << "ERROR OPENING File";
        } else {
            bookCount = 0;
            string line;
            while (getline(infile, line) && bookCount < MAX_BOOKS) {
                Book& theBook = books[bookCount++];
                stringstream ss(line);

                getline(ss, theBook.name, ',');
                getline(ss, theBook.writer, ',');
                getline(ss, theBook.genre, ',');
                getline(ss, theBook.ID, ',');
            }
        }
        infile.close();
    }

    void findBookByName() {
        int choice;  // Declare 'choice' here
        string namefind;
        cout << "Enter Name:";
        getline(cin, namefind);

        for (int i = 0; i < namefind.length(); i++) {
            namefind[i] = toupper(namefind[i]);
        }

        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            string bookName = books[i].name;
            for (int j = 0; j < bookName.length(); j++) {
                bookName[j] = toupper(bookName[j]);
            }

            if (bookName == namefind) {
                system("CLS");
                cout << "BOOK FOUND!!!" << endl;
                cout << "NAME: " << books[i].name << endl;
                cout << "WRITER: " << books[i].writer << endl;
                cout << "GENRE: " << books[i].genre << endl;
                cout << "ID: " << books[i].ID << endl;
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
                findBookByName();
            } else if (choice == 0) {
                system("CLS");

            } else {
                cout << "INVALID CHOICE!" << endl;
                cout << "Returning to Menu!!!" << endl;
            }
        }
    }

    bool findUser(string loginUsername, string loginPassword) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].username == loginUsername && users[i].password == loginPassword) {
                return true;
            }
        }
        return false;
    }

    void findBookById() {
        int choice;  // Declare 'choice' here
        string IDfind;
        cout << "ENTER ID: ";
        getline(cin, IDfind);

        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (IDfind == books[i].ID) {
                system("CLS");
                cout << "BOOK FOUND!!!" << endl;
                cout << "NAME: " << books[i].name << endl;
                cout << "WRITER: " << books[i].writer << endl;
                cout << "GENRE: " << books[i].genre << endl;
                cout << "ID: " << books[i].ID << endl;
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
                findBookById();
            } else if (choice == 0) {
                system("CLS");

            } else {
                cout << "INVALID CHOICE!" << endl;
                cout << "Returning to Menu!!!" << endl;
            }
        }
    }

    void mainMenu() {
    string uzername;
    string pass;
    int choice = 0;
    bool loggedIn = false;
    char aisehi;

    // Declare 'newuser' outside the switch
    User newuser;

    while (true) {
        system("CLS");
        cout << "------------------------------------------------------\n";
        cout << "WELCOME!!" << endl;
        cout << "1. Login" << endl;
        cout << "2. SignUp" << endl;
        cout << "3. Exit" << endl;
        cout << "---------------------------------------------------\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore();
        loadUsersFromFile();

        switch (choice) {
            case 1:
                system("CLS");
                cout << "LOGIN!!!";
                cout << "\nEnter Username(case sensitive): ";
                getline(cin, uzername);
                cout << "\nEnter Password(case sensitive): ";
                getline(cin, pass);
                cin.ignore();
                if (findUser(uzername, pass)) {
                    cout << "LOGGED IN SUCCESSFULLY!" << endl;
                    loggedIn = true;
                } else {
                    cout << "Invalid Username or Password!!!";
                    cout << "Any Key To Continue";
                    aisehi = getch();
                }
                break;
            case 2:
                system("CLS");
                newuser = registration();
                users[userCount++] = newuser;
                saveUsersToFile();
                cout << "PRESS ANY KEY TO CONTINUE:";
                aisehi = getch();
                break;
            case 3:
                system("CLS");
                cout << "Thanks For Using This Tool" << endl;
                return;
            default:
                system("CLS");
                cout << "Invalid :(" << endl;
                break;
        }

        if (loggedIn) {
            while (true) {
                    system("CLS");
                    cout << "\t\t\t---BOOK INVENTORY---";
                    cout << "\n1. VIEW BOOKS";
                    cout << "\n2. ADD BOOKS";
                    cout << "\n3. FIND BOOKS ";
                    cout << "\n4.EXIT";
                    cout << "\n Enter Choice>> ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice) {
                    case 1:
                        system("CLS");
                        viewBook();
                        break;
                    case 2:
                        system("CLS");
                        books[bookCount++] = addBook();
                        saveBooksToFile();
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
                            findBookById();
                            break;
                        case 2:
                            system("CLS");
                            findBookByName();
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
                        cout << "\nExiting!!!";
                        return;
                    default:
                        cout << "\nInvalid Choice!!!";
                    }
                }
            }
        }
    }
};

int main() {
    LibrarySystem library;
    library.mainMenu();
    return 0;
}

