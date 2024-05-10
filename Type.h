// Type.h
#ifndef TYPE_H
#define TYPE_H

#include <string>
using namespace std;

class Type {
    int typeId;
    string typeDesc;

public:
    Type();
    void setTypeId(int typeId);
    int getTypeId() const;
    void setTypeDesc(const string& desc);
    string getTypeDesc();
};

#endif
