#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

using namespace std;

const double GST_RATE = 0.13;
const double DISCOUNT = 0.15;
bool insufficient=1;
bool back=1;
string 	activeUser="unknown";

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
class StockItems {
public:
    string name;
    int quantity;
    double price;
    int id;

    string getName() {
        return name;
    }
    int getQuantity() {
        return quantity;
    }
    double getPrice() {
        return price;
    }
    int getID() {
        return id;
    }
};



StockItems addItem() {
    StockItems stockitem;

    cout << "Enter Name: ";
    getline(cin, stockitem.name);
    cout << "Enter Quantity(only numeric values): ";
    cin >> stockitem.quantity;
    
    cin.ignore();
    
    cout << "Enter Price(only numeric values): ";
    cin >> stockitem.price;
    cout << "Enter ID(only numeric values): ";
    cin >> stockitem.id;
    cin.ignore();
    return stockitem;
}

void viewItems(const vector<StockItems>& items) {
    cout << "List of Stock Items:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        const StockItems& stockitem = items[i];
        cout << "\n ---------------==>\n \n";
        cout << "Name: " << stockitem.name << "\n"; 
      	cout << "ID: " << stockitem.id << "\n";
        cout << "Quantity: " << stockitem.quantity << "\n"; 
        cout << "Price: $"  << fixed << setprecision(2) << stockitem.price << "\n"; 
    }
}

StockItems* findItem(vector<StockItems>& stockitem, int updateID) {
    for (size_t i = 0; i < stockitem.size(); ++i) {
        if (stockitem[i].id == updateID) {
            return &stockitem[i];
        }
    }
    return NULL;
}
bool findUser(vector<User>& users, string loginUsername, string loginPassword) {
    
	for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].username == loginUsername && users[i].password == loginPassword) {
        	activeUser=loginUsername;
            return 1;
        }
    }
    return 0;
}

void updateItems(vector<StockItems>& stockitems) {
    int updateID;
    cout << "Enter ID of the Item you want to Update(only numeric Values): ";
    cin >> updateID;
    cin.ignore();
    StockItems* itemToBeUpdated = findItem(stockitems, updateID);

    if (itemToBeUpdated) {
        cout << "Item Found:\n";
        cout << "ID: " << itemToBeUpdated->id << endl;
        cout << "Name: " << itemToBeUpdated->name << endl;
        cout << "Quantity: " << itemToBeUpdated->quantity << endl;
        cout << "Price: " << itemToBeUpdated->price << endl;

        char control;
        cout << "Press 'Y' to update or any key to Exit: ";
        cin >> control;
        cin.ignore();

        if (control == 'Y' || control == 'y') {
            string newName;
            int newQuantity;
            double newPrice;

            cout << "Enter new name: ";
            getline(cin, newName);
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            cout << "Enter new price: ";
            cin >> newPrice;

            itemToBeUpdated->name = newName;
            itemToBeUpdated->quantity = newQuantity;
            itemToBeUpdated->price = newPrice;

            cout << "Item updated successfully!\n";
        }
    }  else {
        cout << "Item Not Found!!! Returning to the Main Menu." << endl;
    }
}

class BillItems {
public:
    string name;
    int quantity;
    int id;
    double price;
    double total;
};

double calculateBill(vector<BillItems>& billItems, vector<StockItems>& stockItems) {
    double totalBill = 0.0;

    for (size_t i = 0; i < billItems.size(); i++) {
        StockItems* itemToBeBilled = findItem(stockItems, billItems[i].id);

        if (itemToBeBilled) {
            double itemTotal = billItems[i].quantity * itemToBeBilled->price;
            totalBill += itemTotal;
        } else {
            cout << "StockItem not found for ID: " << billItems[i].id << endl;
        }
    }

    return totalBill;
}
void updateStockAfterPurchase(vector<StockItems>& stockitems, const vector<BillItems>& purchasedItems) {
    for (size_t i = 0; i < purchasedItems.size(); i++) {
        const BillItems& purchasedItem = purchasedItems[i];
        StockItems* itemInStock = findItem(stockitems, purchasedItem.id);

        if (itemInStock) {
            if (itemInStock->quantity >= purchasedItem.quantity) {
                itemInStock->quantity -= purchasedItem.quantity;
            } else {
                cout << "Insufficient stock for item " << itemInStock->name << endl;
                insufficient=0;
            }
        } else {
            cout << "StockItem not found for ID: " << purchasedItem.id << endl;
        }
    }
}
void saveItemsToFile(const vector<StockItems>& items) {
    ofstream outFile("stock.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (size_t i = 0; i < items.size(); ++i) {
        const StockItems& item = items[i];
        outFile << item.name << "," << item.quantity << "," << item.price << "," << item.id << "\n";
    }

    outFile.close();
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

void loadItemsFromFile(vector<StockItems>& items) {
    ifstream inFile("stock.txt");
    if (!inFile) {
        cout << "File doesn't exist or couldn't be opened." << endl;
        return ;
    }

    items.clear();
    string line;
    while (getline(inFile, line)) {
        StockItems item;
        stringstream ss(line);
        
        getline(ss, item.name, ',');
        string quantityStr, priceStr, idStr;
        getline(ss, quantityStr, ',');
        getline(ss, priceStr, ',');
        getline(ss, idStr, ',');
        
        stringstream quantityStream(quantityStr);
        stringstream priceStream(priceStr);
        stringstream idStream(idStr);
        
        quantityStream >> item.quantity;
        priceStream >> item.price;
        idStream >> item.id;
        
        items.push_back(item);
    }

    inFile.close();
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


int main() {
	
	vector<User> users;
    vector<StockItems> stockitems;
    vector<BillItems> billItems;
    int choice;
    int age;
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
	
    while (exit==0) {
    	choice=0;
        cout << "---------------------------------------------------\n";
        cout << "Main Menu:\t" << endl;
        cout << "---------------------------------------------------\n";
        cout << "1. Add Items" << endl;
        cout << "2. Update Stock" << endl;
        cout << "3. View Stock" << endl;
        cout << "4. Calculate Bill" << endl;
        cout << "5. Logout" << endl;

        cout << "---------------------------------------------------\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore();
        loadItemsFromFile(stockitems);
        
        switch (choice) {
        	

        case 1:
        	system("CLS");
            do {
                int back = 1;
                cout << "---------------------------------------------------\n";
                StockItems newItem = addItem();
                stockitems.push_back(newItem);
                cout << endl;
                cout << "---------------------------------------------------\n";
                cout << "0. Main Menu" << endl;
                cout << "1. Add Another Item" << endl;

                cout << "Enter Choice:";
                cin >> back;

                cin.ignore();
            } while (back != 0);
            system("CLS");
            break;

        case 2:
        	system("CLS");
            do {
                back = 1;
                updateItems(stockitems);
                cout << endl;

                cout << "0. Main Menu" << endl;
                cout << "1. Update Other Item";
                saveItemsToFile(stockitems);

                cout << "\nEnter Choice:";
                cin >> back;
                cin.ignore();

            } while (back !=0);
            system("CLS");
            break;

        case 3:
        	system("CLS");
            viewItems(stockitems);
            break;

        case 4:
        	system("CLS");
            if (stockitems.empty()) {
                cout << "No items available in stock.\n";
            } else {
                cout << "Available Stock Items:\n";
                viewItems(stockitems);

                
                int numItems=0;
                

                vector<BillItems> selectedBillItems;
                cout << "---------------------------------------------------\n";
                cout << "ENTER THE CUSTOMER'S AGE:";
                cin >> age;
                int i=1;

                do {
                	
                    int selectedID, selectedQuantity;
                    cout << "Enter ID of item " << i  << ": ";
                    cin >> selectedID;
                    
                    cout << "Enter quantity(carefully enter the quantity or else bill won't be calculated) of item " << i  << ": ";
                    cin >> selectedQuantity;

                    BillItems billItem;
                    billItem.id = selectedID;
                    billItem.quantity = selectedQuantity;
                    selectedBillItems.push_back(billItem);
                    ++i;
                    cout<<"1. Add More Items to Cart"<<endl;
                    cout<<"0. End Shopping\n";
					cin>>numItems;
					cin.ignore();
					 
                }while(numItems==1);
                
                system("CLS");

                double totalBill = calculateBill(selectedBillItems, stockitems);
                double totalGST = totalBill * GST_RATE;
                cout << "\nSelected Items:\n";
                for (int i = 0; i < selectedBillItems.size(); ++i) {
                    const BillItems& billItem = selectedBillItems[i];
                    StockItems* item = findItem(stockitems, billItem.id);
                    updateStockAfterPurchase(stockitems, selectedBillItems);
                    saveItemsToFile(stockitems);
                    
					if(item){
					
                    if(insufficient==1)
                    {
                    
                    cout << "Item: " << item->name << "\n";
                    cout << "Quantity: " << billItem.quantity << "\n";
                    cout << "Price per unit: $" << item->price << "\n";
                    cout << "Total: $" << (item->price * billItem.quantity) << "\n";
                    cout << "---------------------------------------------------\n";
					}
					else{
						cout << "Item not found for ID: " << billItem.id << endl;
						break;
					}
				}
				}
                if(insufficient==1){
				
                    cout << "TOTAL Bill:                     $" << totalBill-totalGST << endl;
                    cout << "TOTAL G.S.T:                    $" << totalGST << endl;
                
                 if (age <= 15 || age >= 50){
                    cout << "Discount applied:               $" << (totalBill - totalGST) * DISCOUNT << endl;
                    cout << "---------------------------------------------------\n";
                    cout << "TOTAL PAYABLE BILL:             $"  << (totalBill-((totalBill - totalGST) * DISCOUNT ))<< endl;
                 }
                 else{
                    cout << "---------------------------------------------------\n";
                    cout << "TOTAL PAYABLE BILL:             $" << totalBill<< endl;
				 }
				 cout<<"(BILL CALCULATED BY: "<<activeUser<<")\n";
                saveItemsToFile(stockitems);
            }
            cout<<"\n\n\n1.Main Menu\n";
            cout<<"0.Exit\n";
            cin>>back;
            cin.ignore();
            
            if(back==1){
            	break;
			}
			else{
			   system("CLS");
               cout << "Thanks For Using This Tool" << endl;
               return 0;
		}
        }
            break;
        case 5:
        	system("CLS");
            cout << "Thanks For Using This Tool" << endl;
            cout<<"Logging Out!!!";
            exit=1;
            break;;

        default:
        	system("CLS");
            cout << "Invalid Choice :(" << endl;
            break;
        }
        saveUsersToFile(users);
    }
    saveUsersToFile(users);
  }
  saveUsersToFile(users);
}
    return 0;
}

