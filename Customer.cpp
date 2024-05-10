#include "Customer.h"

Customer::Customer() : type(nullptr) {
    address = new Address;
}

Customer::Customer(const Customer& customer) : name(customer.name) {
    this->type = customer.type;
    this->address = new Address;
    address->setAddr1(customer.address->getAddr1());
    address->setAddr2(customer.address->getAddr2());
    address->setCity(customer.address->getCity());
    address->setPin(customer.address->getPin());
}

Customer& Customer::operator=(const Customer& customer) {
    if (this == &customer)
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

Customer::~Customer() {
    delete address;
}

void Customer::setName(const string& name) { this->name = name; }
string Customer::getName() const { return name; }
void Customer::setType(Type* type) { this->type = type; }
Type* Customer::getType() const { return type; }
void Customer::setAddress(Address* address) { this->address = address; }
Address* Customer::getAddress() const { return address; }
