#include <iostream>

int main() {
    // Constant data
    const int constantValue = 10;
    // constantValue = 20; // Error: Attempting to modify a const variable

    std::cout << "Constant Value: " << constantValue << std::endl;

    // Constant pointer to const data
    const int* ptr1 = &constantValue;
    // *ptr1 = 30; // Error: Attempting to modify const data through const pointer

    std::cout << "Value pointed by const pointer: " << *ptr1 << std::endl;

    // Mutable pointer to const data
    int value = 100;
    const int* ptr2 = &value; // Pointer is const, data is not
    // *ptr2 = 200; // Error: Attempting to modify const data through const pointer
    value = 200; // Valid: Data can be modified directly

    std::cout << "Updated value: " << value << std::endl;
    std::cout << "Value pointed by const pointer after modification: " << *ptr2 << std::endl;

    return 0;
}
