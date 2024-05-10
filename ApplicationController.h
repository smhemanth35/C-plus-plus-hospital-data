#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include "Customer.h"
#include "Type.h"
#include <vector>
#include <map>

class ApplicationController {
private:
    std::vector<Customer*> customers;
    std::map<int, Type*> types;

    void loadCustomerTypes();
    Customer* createCustomer(std::string name, int type, std::string addr1, std::string addr2, std::string city, std::string pin);
    void loadCustomers();
    void initialize();
    void release();

public:
    ApplicationController();
    ~ApplicationController();
    void execute();
};

#endif
