#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
    string addr1;
    string addr2;
    string city;
    string pin;

public:
    Address();
    string getAddr1() const;
    void setAddr1(const string& addr1);
    string getAddr2() const;
    void setAddr2(const string& addr2);
    string getCity() const;
    void setCity(const string& city);
    string getPin() const;
    void setPin(const string& pin);
};

#endif
