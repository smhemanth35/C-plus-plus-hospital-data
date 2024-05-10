#include "Console.h"
#include <iostream>


void Console::display(Customer* c) {
    cout << "Customer name : " << c->getName() <<endl;
    cout << "Customer Type : " << c->getType()->getTypeDesc() << endl;
    cout << "Customer Address : ";
    Address* a1 = c->getAddress();
    string addr = a1->getAddr1() + ", " + a1->getAddr2() + ", " + a1->getCity() + ", " + a1->getPin();
    cout << addr << endl << endl;
}
