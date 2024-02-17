#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <conio.h>

using namespace std;

class Car {
public:
    string carType;
    string model;
    int price;
    bool available;
    time_t rentalStartTime;
    double rentalDuration;
    bool isRentedByDays;

    Car() : carType(""), model(""), price(0), available(true), rentalStartTime(0), isRentedByDays(false) {}

    Car(string type, string m, int p) : carType(type), model(m), price(p), available(true), rentalStartTime(0), isRentedByDays(false) {}

    void setRentalStartTime(time_t startTime) {
        rentalStartTime = startTime;
    }

    double getRentalDurationInHours() const {
        if (rentalStartTime == 0) {
            return 0.0;
        }
        time_t currentTime;
        time(&currentTime);
        return difftime(currentTime, rentalStartTime) / 3600.0;
    }

    double calculateRentalCost() const {
        if (isRentedByDays) {
            return ((rentalDuration * price*24)-(rentalDuration * price*24)*0.3);
        } else {
            return rentalDuration * (price);
        }
    }
};

class User {
public:
    string username;
    string password;
};

class Customer {
public:
    string name;
    string contact;
    string ID;
};

void viewCars(const vector<Car>& cars, bool availability) {
    cout << "List of Cars:\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].available == availability) {
            const Car& car = cars[i];

            cout << "Type: " << car.carType << "\n";
            cout << "Model: " << car.model << "\n";
            cout << "Price Per Day: $" << car.price << "\n";
            cout << "Availability: " << (car.available ? "Available" : "Rented") << "\n";
            cout << "Rental Start Time: " << ctime(&car.rentalStartTime); 
            cout << "--------------------------------\n";
        }
    }
}

User registration() {
    User newUser;
    cout << "WELCOME NEW USER!!!" << endl;
    cout << "Enter Username (case sensitive): ";
    getline(cin, newUser.username);
    cout << "Enter Password (case sensitive): ";
    getline(cin, newUser.password);
    cout << "ACCOUNT REGISTERED!!!" << endl;
    return newUser;
}

bool findUser(const vector<User>& users, const string& loginUsername, const string& loginPassword) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].username == loginUsername && users[i].password == loginPassword) {
            return true;
        }
    }
    return false;
}

Car addCar() {
    string type, model;
    int price;

    cout << "Enter Car Type: ";
    getline(cin, type);
    cout << "Enter Model: ";
    getline(cin, model);
    cout << "Enter Price Per Day: ";
    cin >> price;
    cin.ignore();

    Car newCar(type, model, price);
    return newCar;
}

Car* findCar(vector<Car>& cars, bool availableOnly) {
    string typeFind;
    cout << "Enter Type: ";
    getline(cin, typeFind);

    for (int i = 0; i < typeFind.length(); i++) {
        typeFind[i] = toupper(typeFind[i]);
    }

    for (int i = 0; i < cars.size(); i++) {
        if ((!availableOnly || cars[i].available) && cars[i].carType == typeFind) {
            system("CLS");
            cout << "CAR FOUND!!!" << endl;
            cout << "Car Type: " << cars[i].carType << endl;
            cout << "Model: " << cars[i].model << endl;
            cout << "Price: $" << cars[i].price << endl;
            return &cars[i];
        }
    }

    system("CLS");
    cout << "Car Not Found or not available!" << endl;
    return nullptr;
}

void saveToFile(const vector<Car>& cars) {
    ofstream outFile("cars.txt");
    if (!outFile) {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    for (int i = 0; i < cars.size(); i++) {
        const Car& thisCar = cars[i];
        outFile << thisCar.carType << "," << thisCar.model << "," << thisCar.price << "," << thisCar.available << "," << thisCar.rentalStartTime << "," << thisCar.isRentedByDays << "\n";
    }
    outFile.close();
}

void loadFromFile(vector<Car>& cars) {
    ifstream inFile("cars.txt");
    if (!inFile) {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    cars.clear();
    string line;

    while (getline(inFile, line)) {
        Car car;
        stringstream ss(line);
        string pStr, aStr, tStr, dStr;

        getline(ss, car.carType, ',');
        getline(ss, car.model, ',');
        getline(ss, pStr, ',');
        getline(ss, aStr, ',');
        getline(ss, tStr, ',');
        getline(ss, dStr, ',');

        stringstream pStream(pStr);
        stringstream aStream(aStr);
        stringstream tStream(tStr);
        stringstream dStream(dStr);

        pStream >> car.price;
        aStream >> car.available;
        tStream >> car.rentalStartTime;
        dStream >> car.isRentedByDays;

        cars.push_back(car);
    }
    inFile.close();
}

void saveUsersToFile(const vector<User>& users) {
    ofstream outFile("users.txt");
    if (!outFile) {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }
    for (const User& user : users) {
        outFile << user.username << "," << user.password << "\n";
    }
    outFile.close();
}

void loadUsersFromFile(vector<User>& users) {
    ifstream inFile("users.txt");
    if (!inFile) {
        cout << "ERROR OPENING FILE" << endl;
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

int main() {
    vector<Car> cars;
    vector<User> users;
    vector<Customer> customers;
    bool exit = false;
    int choice;
    bool loggedIn = false;
    char aisehi;
    string username, password;

    loadUsersFromFile(users);

    while (true) {
        system("CLS");
        loadFromFile(cars);
        cout << "------------------------------------------------------\n";
        cout << "WELCOME!!" << endl;
        cout << "1. Login" << endl;
        cout << "2. SignUp" << endl;
        cout << "3. Exit" << endl;
        cout << "---------------------------------------------------\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore();
        loadFromFile(cars);

        switch (choice) {

        case 1:

            system("CLS");
            cout << "LOGIN!!!" << endl;
            cout << "\nEnter Username (case sensitive): ";
            cin >> username;
            cout << "\nEnter Password (case sensitive): ";
            cin >> password;
            cin.ignore();
            if (findUser(users, username, password)) {
                cout << "LOGGED IN SUCCESSFULLY!" << endl;
                loggedIn = true;
            }
            else {
                cout << "Invalid Username or Password!!!" << endl;
                cout << "Any Key To Continue";
                aisehi = getch();
            }
            break;

        case 2: {
            system("CLS");
            User newUser = registration();
            users.push_back(newUser);
            saveUsersToFile(users);
            saveToFile(cars); 
            cout << "PRESS ANY KEY TO CONTINUE:";
            aisehi = getch();
            break;
        }

        case 3:
            system("CLS");
            cout << "Thanks For Using This Tool" << endl;
            return 0;

        default:
            system("CLS");
            cout << "Invalid :(" << endl;
            break;

        }

        if (loggedIn) {

            while (true) {
                loadFromFile(cars);
                cout << "---------------------------------------------------\n";
                cout << "Main Menu:\n";
                cout << "---------------------------------------------------\n";
                cout << "0. ADD CAR\n";
                cout << "1. View Available Cars\n";
                cout << "2. View Rented Cars\n";
                cout << "3. Rent Car\n";
                cout << "4. Return Car\n";
                cout << "5. Exit\n";
                cout << "---------------------------------------------------\n";
                cout << "\nEnter Choice: ";

                int choice;
                cin >> choice;
                cin.ignore();

                switch (choice) {
                case 0: {
                    system("CLS");
                    Car newCar = addCar();
                    cars.push_back(newCar);
                    saveToFile(cars);
                    break;
                }

                case 1: {
                    system("CLS");
                    viewCars(cars, true);
                    break;
                }
                case 2: {
                    system("CLS");
                    viewCars(cars, false);
                    break;
                }

                case 3: {
                    system("CLS");
                    cout << "Available Cars:\n";
                    viewCars(cars, true);
                    Car* selectedCar = findCar(cars, true);

                    if (selectedCar) {
                        selectedCar->available = false;

                        cout << "Enter rental preference (D for days, H for hours): ";
                        char rentalPreference;
                        cin >> rentalPreference;

                        if (rentalPreference == 'D' || rentalPreference == 'd') {
                            selectedCar->isRentedByDays = true;
                            cout << "Enter rental duration (in days): ";
                            double days;
                            cin >> days;
                            selectedCar->rentalDuration = days;
                        } else if (rentalPreference == 'H' || rentalPreference == 'h') {
                            selectedCar->isRentedByDays = false;
                            cout << "Enter rental duration (in hours): ";
                            double hours;
                            cin >> hours;
                            selectedCar->rentalDuration = hours;
                        } else {
                            cout << "Invalid rental preference. Please choose 'D' for days or 'H' for hours.\n";
                            selectedCar->available = true; 
                            getch();
                            break;
                        }

                        selectedCar->setRentalStartTime(time(nullptr));
                        cout << "Car rented successfully!\n";

                        double totalCharge = selectedCar->calculateRentalCost();

                       
                        if (selectedCar->isRentedByDays) {
                        }

                        cout << "Total Charge: $" << totalCharge << endl;

                        saveToFile(cars);
                        getch();
                    } else {
                        cout << "Car not found or not available for rent.\n";
                    }
                    break;
                }

               case 4: {
    					system("CLS");
    					cout << "Rented Cars:\n";
   						viewCars(cars, false);
    					Car* selectedCar = findCar(cars, false);
    
    					if (selectedCar) {
       						double rentalDuration = selectedCar->getRentalDurationInHours();
        					double totalCharge = rentalDuration * selectedCar->price;
        					selectedCar->setRentalStartTime(0);
        					selectedCar->available = true;

        					cout << "Car returned successfully!\n";
        					cout << "Total Charge: $" << totalCharge << endl;
        					saveToFile(cars);
        					getch();
    					} 
						else {
        					cout << "Car not found or not available for return.\n";
    						}
    					break;
					}
                case 5: {
                    cout << "EXITING!!!" << endl;
                    saveToFile(cars);
                    return 0;
                }

                default: {
                    cout << "INVALID CHOICE\n";
                    break;
                }
                }
            }
        }
    }
    return 0;
}

