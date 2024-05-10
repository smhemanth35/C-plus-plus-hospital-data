#include "Address.h"

Address::Address() : addr1("NA"), addr2("NA"), city("NA"), pin("NA") {}

string Address::getAddr1() const {
    return addr1;
}

void Address::setAddr1(const string& addr1) {
    this->addr1 = addr1;
    
}

string Address::getAddr2() const {
    return addr2;
}

void Address::setAddr2(const string& addr2) {
    this->addr2 = addr2;
}

string Address::getCity() const {
    return city;
}

void Address::setCity(const string& city) {
    this->city = city;
}

string Address::getPin() const {
    return pin;
}

void Address::setPin(const string& pin) {
    this->pin = pin;
}
