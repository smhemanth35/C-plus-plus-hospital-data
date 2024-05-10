#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Address.h"
#include "Type.h"

class Customer {
private:
    string name;
    Type* type; 
    Address* address;

public:
    Customer();
    Customer(const Customer& customer);
    Customer& operator=(const Customer& customer);
    ~Customer();
    void setName(const string& name);
    string getName() const;
    void setType(Type* type);
    Type* getType() const;
    void setAddress(Address* address);
    Address* getAddress() const;
};

#endif 
