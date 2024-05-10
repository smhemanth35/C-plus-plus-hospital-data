
#include "Type.h"

Type::Type() : typeId(0) {}

void Type::setTypeId(int typeId) {
    this->typeId = typeId;
}

int Type::getTypeId() const {
    return typeId;
}

void Type::setTypeDesc(const string& desc) {
    typeDesc = desc;
}

string Type::getTypeDesc() {
    return typeDesc;
}
