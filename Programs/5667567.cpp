#include <iostream>
#include <string>
using namespace std;
class Product {
protected:
 string name;
 double price;
 string description;
public:
 Product(const string& name, double price, const string& description)
 : name(name), price(price), description(description) {}
 void displayInfo() {
 cout << "Name: " << name << endl;
 cout << "Price: $" << price << endl;
 cout << "Description: " << description << endl;
 }
};
class PhysicalProduct : public Product {
protected:
 double weight;
 string dimensions;
public:
 PhysicalProduct(const string& name, double price, const string& description, double weight, const 
string& dimensions)
 : Product(name, price, description), weight(weight), dimensions(dimensions) {}
 void displayInfo() {
 Product::displayInfo();
 cout << "Weight: " << weight << " kg" << endl;
 cout << "Dimensions: " << dimensions << endl;
 }
};
class DigitalProduct : public Product {
protected:
 double fileSize;
 string downloadLink;
public:
 DigitalProduct(const string& name, double price, const string& description, double fileSize, const 
string& downloadLink)
 : Product(name, price, description), fileSize(fileSize), downloadLink(downloadLink) {}
 void displayInfo() {
 Product::displayInfo();
 cout << "File Size: " << fileSize << " MB" << endl;
 cout << "Download Link: " << downloadLink << endl;
 }
};
class User {
protected:
 string username;
 string email;
 string password;
public:
 User(const string& username, const string& email, const string& password)
 : username(username), email(email), password(password) {}
 void displayInfo() {
 cout << "Username: " << username << endl;
 cout << "Email: " << email << endl;
 }
};
class Seller : public User {
protected:
 Product* product;
public:
 Seller(const string& username, const string& email, const string& password, Product* product)
 : User(username, email, password), product(product) {}
 void displayInfo() {
 User::displayInfo();
 cout << "Product Details:" << endl;
 product->displayInfo();
 }
};
class Buyer : public User {
public:
 Buyer(const string& username, const string& email, const string& password)
 : User(username, email, password) {}
};
int main() {
 // Create PhysicalProduct object
 PhysicalProduct physicalProduct("Book", 29.99, "A story book", 1.2, "20cm x 15cm");
 // Create DigitalProduct object
 DigitalProduct digitalProduct("Ebook", 19.99, "An electronic book", 5.2, 
"https://example.com/ebook");
 // Create Seller object
 Seller seller("JohnDoe", "john.doe@example.com", "password123", &physicalProduct);
 // Create Buyer object
 Buyer buyer("JaneDoe", "jane.doe@example.com", "password456");
 // Display seller information
 cout << "Seller Information:" << endl;
 seller.displayInfo();
 cout << endl;
 // Display buyer information
 cout << "Buyer Information:" << endl;
 buyer.displayInfo();
 return 0;
}
