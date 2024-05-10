#include <iostream>

class MyClass {
private:
    int mutableValue; // Mutable data member
public:
    const int constValue; // Const data member

    // Constructor to initialize constValue and mutableValue
    MyClass(int constVal, int mutVal) : constValue(constVal), mutableValue(mutVal) {}

    // Const method that prints constValue and mutableValue
    void printValues() const {
        std::cout << "Const Value: " << constValue << std::endl;
        std::cout << "Mutable Value: " << mutableValue << std::endl;
    }

    // Method to modify mutableValue
    void modifyMutableValue(int newValue) {
        mutableValue = newValue;
    }
};

int main() {
    // Create a const object of MyClass
    const MyClass obj(10, 20);

    // Attempt to modify constValue (Error: const data member cannot be modified)
    // obj.constValue = 30;

    // Access and print constValue and mutableValue using const method
    obj.printValues();

    // Modify mutableValue using a non-const method
   // obj.modifyMutableValue(30);

    // Access and print constValue and modified mutableValue using const method
    obj.printValues();

    return 0;
}
