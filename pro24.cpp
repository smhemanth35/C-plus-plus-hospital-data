// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
enum 
{
    CLASSIC, SILVER, GOLD
};
 
class Address{
    string addr1;  
    string addr2;
    string city;
    string pin;
public:
    Address() : addr1("NA"), addr2("NA"), city("NA"), pin("NA") { }
    string getAddr1() const { return addr1; }
    void setAddr1(const string& addr1) { this->addr1 = addr1;  } 
    string getAddr2() const { return addr2; }
    void setAddr2(const string& addr2) { this->addr2 = addr2;  }
    string getCity() const { return city; }
    void setCity(const string& city) { this->city = city;  }   
    string getPin() const { return pin; }
    void setPin(const string& pin) { this->pin = pin;  }   
};
 
class Type
{
    int typeId;
    string typeDesc;
public:
    Type() : typeId(0) { }
    void setTypeId(int typeId)
    {
        this->typeId = typeId;    
    }
    int getTypeId() const
    {
        return typeId;
    }
    void setTypeDesc(const string& desc)
    {
        this->typeDesc = desc;
    }
    string getTypeDesc()
    {
        return typeDesc;
    }
};
 
class Customer
{
    string name;
    Type* type;             // Shared Aggregation
    Address* address;
public:
    Customer() : type(NULL) 
    { 
        // null object
        address = new Address;
    }
    Customer(const Customer& customer) : name(customer.name)
    {
        this->type = customer.type;
        this->address = new Address;
        address->setAddr1(customer.address->getAddr1());
        address->setAddr2(customer.address->getAddr2());
        address->setCity(customer.address->getCity());
        address->setPin(customer.address->getPin());
    }
    Customer& operator=(const Customer& customer) 
    {
        if(this == &customer)
            return *this;
        this->~Customer();
        name = customer.name;
        this->type = customer.type;
        this->address = new Address;
        address->setAddr1(customer.address->getAddr1());
        address->setAddr2(customer.address->getAddr2());
        address->setCity(customer.address->getCity());
        address->setPin(customer.address->getPin());
        return *this;
    }
    ~Customer() 
    { 
        delete address;
    }
    void setName(const string& name)
    {
        this->name = name;
    }
    string getName() const
    {
        return name;
    }
    void setType(Type* type)
    {
        this->type = type;
    }
    Type* getType() const
    {
        return type;
    }
    void setAddress(Address* address)
    {
        this->address = address;
    }
    Address* getAddress() const
    {
        return address;
    }
};
 
class Console
{
public:
    static void display(Customer* c)
    {
        cout<<"Customer name : "<<c->getName()<<endl;
        cout<<"Customer Type : "<<c->getType()->getTypeDesc()<<endl;
        cout<<"Customer Address : ";
        Address* a1 = c->getAddress();
        string addr = a1->getAddr1() + ", " + a1->getAddr2() + ", " + a1->getCity() + ", " + a1->getPin();
        cout<<addr<<endl<<endl;
    }
};
 
class ApplicationController
{
    vector<Customer*> customers;
    map<int,Type*> types;
    void loadCustomerTypes()
    {
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
    Customer* createCustomer(string name,int type,string addr1,string addr2,string city,string pin)
    {
        Customer* customer = new Customer;
        customer->setName(name);
        customer->setType(types[type]);
        Address* a1 = new Address;
        a1->setAddr1(addr1);
        a1->setAddr2(addr2);
        a1->setCity(city);
        a1->setPin(pin);
        customer->setAddress(a1);
        return customer;
    }
    void loadCustomers()
    {
        Customer* c1 = createCustomer("Aryan",CLASSIC,
                        "128 Laurel St","Northfolk Avenue",
                        "Springhill","654123");
        customers.push_back(c1);
        Customer* c2 = createCustomer("Noor",SILVER,
                        "45 Bird St","Lake in the woods",
                        "Springhill","654123");
        customers.push_back(c2);
        Customer* c3 = createCustomer("Bhavesh",GOLD,"NA","NA","NA","NA");
        customers.push_back(c3);
        Customer* c4 = createCustomer("Abhijit",CLASSIC,"NA","NA","NA","NA");
        customers.push_back(c4);
        Customer* c5 = createCustomer("Amruta",CLASSIC,"NA","NA","NA","NA");
        customers.push_back(c5);
        Customer* c6 = createCustomer("Shabnum",SILVER,"NA","NA","NA","NA");
        customers.push_back(c6);
    }
    void initialize() {
        loadCustomerTypes();
        loadCustomers();
    }
    void release()
    {
        for(int i=0;i<customers.size();++i)
        {
            delete customers[i];
        }
        for(int i=1;i<3;++i)
        {
            delete types[i];
        }
    }
public:
    ApplicationController() {
        initialize();
    }
    ~ApplicationController() {
        release();
    }
    void execute()
    {
        for(int i=0;i<customers.size();++i)
        {
            Console::display(customers[i]);
        }
    }
};
 
int main() {
    ApplicationController* controller = new ApplicationController;
    controller->execute();
    delete controller;
 
    return 0;
}