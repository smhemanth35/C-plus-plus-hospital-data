#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

enum CustomerType {
    CLASSIC = 1,
    SILVER = 2,
    GOLD = 3
};

class Address {
private:
    string addr1;
    string addr2;
    string city;
    string pin;

public:
    void setAddr1(const string& a) { addr1 = a; }
    void setAddr2(const string& a) { addr2 = a; }
    void setCity(const string& c) { city = c; }
    void setPin(const string& p) { pin = p; }

    string getAddr1() const { return addr1; }
    string getAddr2() const { return addr2; }
    string getCity() const { return city; }
    string getPin() const { return pin; }
};

class Type {
private:
    int typeId;
    string typeDesc;

public:
    void setTypeId(int id) { typeId = id; }
    void setTypeDesc(const string& desc) { typeDesc = desc; }

    string getTypeDesc() const { return typeDesc; }
};

class Customer {
private:
    string name;
    Type* type;
    Address* address;

public:
    Customer(const string& n, Type* t, Address* a) : name(n), type(t), address(a) {}

    string getName() const { return name; }
    Type* getType() const { return type; }
    Address* getAddress() const { return address; }
};

class Console {
public:
    static void display(const Customer* c) {
        cout << "Customer name: " << c->getName() << endl;
        cout << "Customer Type: " << c->getType()->getTypeDesc() << endl;
        cout << "Customer Address: " << c->getAddress()->getAddr1() << ", "
             << c->getAddress()->getAddr2() << ", "
             << c->getAddress()->getCity() << ", "
             << c->getAddress()->getPin() << endl;
        cout << endl;
    }
};

class ApplicationController {
private:
    vector<Customer*> customers;
    map<int, Type*> types;

    void loadCustomerTypes() {
        Type* type1 = new Type;
        type1->setTypeId(CLASSIC);
        type1->setTypeDesc("CLASSIC");
        types[CLASSIC] = type1;

        Type* type2 = new Type;
        type2->setTypeId(SILVER);
        type2->setTypeDesc("SILVER");
        types[SILVER] = type2;

        Type* type3 = new Type;
        type3->setTypeId(GOLD);
        type3->setTypeDesc("GOLD");
        types[GOLD] = type3;
    }

    void loadCustomersFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name, typeStr, addr1, addr2, city, pin;
            int type;

            if (getline(iss, name, ',') &&
                getline(iss, typeStr, ',') &&
                getline(iss, addr1, ',') &&
                getline(iss, addr2, ',') &&
                getline(iss, city, ',') &&
                getline(iss, pin))
            {
                if (typeStr == "CLASSIC") type = CLASSIC;
                else if (typeStr == "SILVER") type = SILVER;
                else if (typeStr == "GOLD") type = GOLD;
                else continue; // Skip invalid types

                Address* address = new Address;
                address->setAddr1(addr1);
                address->setAddr2(addr2);
                address->setCity(city);
                address->setPin(pin);

                customers.push_back(new Customer(name, types[type], address));
            }
        }

        file.close();
    }

public:
    ApplicationController() {
        loadCustomerTypes();
        loadCustomersFromFile("C:/Users/smhem/OneDrive/Desktop/cpp_program/customers.txt");
    }

    ~ApplicationController() 
    {
        for (int i = 0; i < customers.size(); ++i) {
            delete customers[i]->getAddress();  // Free address memory
            delete customers[i];  // Free customer memory
        }
        for (int i = 1; i <= GOLD; ++i) {
            delete types[i];  // Free type memory
        }
    }

    void execute() {
        for (int i = 0; i < customers.size(); ++i) {
            Console::display(customers[i]);
        }
    }
};

int main() {
    ApplicationController app;
    app.execute();
    return 0;
}
