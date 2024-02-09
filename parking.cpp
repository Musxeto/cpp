#include <iostream>
#include <string>
using namespace std;

const int MAX_SPOTS = 10;
const int HOURLY_RATE = 10;

void displayParkingStatus(const string* carNames, const int* parkedHours, int size) {
    cout << "Parking Status:\n";
    for (int i = 0; i < size; ++i) {
        if (!carNames[i].empty()) {
            cout << "Spot " << i + 1 << ": Car '" << carNames[i] << "', Hours Parked: " << parkedHours[i] << endl;
        } else {
            cout << "Spot " << i + 1 << ": Empty\n";
        }
    }
    cout << endl;
}

int findAvailableSpot(const string* carNames, int size) {
    for (int i = 0; i < size; ++i) {
        if (carNames[i].empty()) {
            return i;
        }
    }
    return -1;
}

void parkCar(string* carNames, int* parkedHours, int size) {
    int spot = findAvailableSpot(carNames, size);
    if (spot != -1) {
        cout << "Enter the car name: ";
        cin.ignore(); // Ignore newline character left in buffer
        getline(cin, carNames[spot]);
        parkedHours[spot] = 0; // Initialize parked hours to 0
        cout << "Car '" << carNames[spot] << "' parked at spot " << spot + 1 << endl;
    } else {
        cout << "Parking is full. No available spots." << endl;
    }
}

void removeCar(string* carNames, int* parkedHours, int size) {
    int spot;
    cout << "Enter the spot number to remove the car: ";
    cin >> spot;

    if (spot >= 1 && spot <= size && !carNames[spot - 1].empty()) {
        int hoursParked;
        cout << "Enter the number of hours the car has been parked: ";
        cin >> hoursParked;

        parkedHours[spot - 1] = hoursParked;
        int bill = hoursParked * HOURLY_RATE;

        cout << "Car '" << carNames[spot - 1] << "' removed from spot " << spot << endl;
        cout << "Bill for parking: $" << bill << endl;

        carNames[spot - 1] = ""; // Clear the car name
        parkedHours[spot - 1] = 0; // Reset parked hours
    } else {
        cout << "Invalid spot or no car parked at spot " << spot << endl;
    }
}

void systemFunc() {
    system("pause");
    system("cls");
}

int main() {
    string carNames[MAX_SPOTS];
    int parkedHours[MAX_SPOTS] = {0};

    int choice;
    do {
        cout << "1. Park a car\n2. Remove a car\n3. Display parking status\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                parkCar(carNames, parkedHours, MAX_SPOTS);
                systemFunc();
                break;
            case 2:
                removeCar(carNames, parkedHours, MAX_SPOTS);
                systemFunc();
                break;
            case 3:
                displayParkingStatus(carNames, parkedHours, MAX_SPOTS);
                systemFunc();
                break;
            case 4:
                cout << "Exiting program.\n";
                systemFunc();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

