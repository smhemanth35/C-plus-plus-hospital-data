/*Static rata Members and Methods ou a Class: Static data members and methods belong to the class rather than
instances of the class. They are shared among all instances of the class and can be accessed without creating an
object.*/
#include <iostream>

class MyClass {
public:
    static int staticVar; // Static data member
    int normalVar;        // Non-static data member

    // Constructor that initializes normalVar
    MyClass(int val) : normalVar(val) {}

    // Method to display staticVar and normalVar
    void display() {
        std::cout << "Static Variable: " << staticVar << std::endl;
        std::cout << "Normal Variable: " << normalVar << std::endl;
    }
};

// Initializing static variable outside the class definition
int MyClass::staticVar = 0;

int main() {
    MyClass obj1(10); // Creating obj1 with normalVar = 10
    MyClass obj2(20); // Creating obj2 with normalVar = 20

    obj1.display(); // Output: Static Variable: 0, Normal Variable: 10
    obj2.display(); // Output: Static Variable: 0, Normal Variable: 20

    // Modifying static variable
   MyClass::staticVar = 100;

    obj1.display(); // Output: Static Variable: 100, Normal Variable: 10
    obj2.display(); // Output: Static Variable: 100, Normal Variable: 20

    return 0;
}
