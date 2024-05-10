

#include "ApplicationController.h"
#include "Enums.h"  
#include "Customer.h"
#include "Type.h"
#include "Address.h"
#include "Console.h"
#include <iostream>

ApplicationController::ApplicationController() {
    initialize();
}

ApplicationController::~ApplicationController() {
    release();
}

void ApplicationController::loadCustomerTypes() {
    Type* type1 = new Type;
    type1->setTypeId(CLASSIC);
    type1->setTypeDesc("CLASSIC");
    types[CustomerType::CLASSIC] = type1; 
    Type* type2 = new Type;
    type2->setTypeId(SILVER);
    type2->setTypeDesc("SILVER");
    types[CustomerType::SILVER] = type2;  
    Type* type3 = new Type;
    type3->setTypeId(GOLD);
    type3->setTypeDesc("GOLD");
    types[CustomerType::GOLD] = type3;  
}

Customer* ApplicationController::createCustomer(std::string name, int type, std::string addr1, std::string addr2, std::string city, std::string pin) {
    Customer* customer = new Customer;
    customer->setName(name);
    customer->setType(types[static_cast<CustomerType>(type)]); 
    Address* a1 = new Address;
    a1->setAddr1(addr1);
    a1->setAddr2(addr2);
    a1->setCity(city);
    a1->setPin(pin);
    customer->setAddress(a1);
    return customer;
}

void ApplicationController::loadCustomers() {
    Customer* c1 = createCustomer("Aryan", CustomerType::CLASSIC, "128 Laurel St", "Northfolk Avenue", "Springhill", "654123");
    customers.push_back(c1);
    Customer* c2 = createCustomer("Noor", CustomerType::SILVER, "45 Bird St", "Lake in the woods", "Springhill", "654123");
    customers.push_back(c2);
    Customer* c3 = createCustomer("Bhavesh", CustomerType::GOLD, "NA", "NA", "NA", "NA");
    customers.push_back(c3);
    Customer* c4 = createCustomer("Abhijit", CustomerType::CLASSIC, "NA", "NA", "NA", "NA");
    customers.push_back(c4);
    Customer* c5 = createCustomer("Amruta", CustomerType::CLASSIC, "NA", "NA", "NA", "NA");
    customers.push_back(c5);
    Customer* c6 = createCustomer("Shabnum", CustomerType::SILVER, "NA", "NA", "NA", "NA");
    customers.push_back(c6);
}

void ApplicationController::initialize() {
    loadCustomerTypes();
    loadCustomers();
}

void ApplicationController::release() {
    for (int i = 0; i < customers.size(); ++i) {
        delete customers[i];
    }
    for (int i = 1; i < 3; ++i) {
        delete types[static_cast<CustomerType>(i)];  
    }
}

void ApplicationController::execute() {
    for (int i = 0; i < customers.size(); ++i) {
        Console::display(customers[i]);
    }
}
