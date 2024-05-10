#ifndef CONSOLE_H
#define CONSOLE_H

#include "Customer.h"
#include <iostream>
using namespace std;

class Console {
public:
    static void display(Customer* c);
};

#endif 
