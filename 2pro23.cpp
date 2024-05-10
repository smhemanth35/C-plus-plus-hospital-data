/*Static data Members and Methods of a Class:
Static data members and methods belong to the class rather than instances of the class. 
They are shared among all instances of the class and can be accessed without creating an object.
staticMethod() is a static method declared with the static keyword. Static methods can be called without creating an object of the class.*/

#include <iostream> // Include necessary header file for input-output operations
using namespace std; // Use the std namespace

// Define a class called MyClass
class MyClass {
public:
    // Declare a static integer variable
    static int staticVar;

    // Declare a static method that prints a message
    static void staticMethod() {
        cout << "Static method called." << endl; // Use cout from std namespace
    }
};

// Initialize the static variable staticVar outside the class definition
int MyClass::staticVar = 0;//Static data Members

int main() {
    // Call the static method staticMethod of the MyClass class
    MyClass::staticMethod(); // Output: Static method called.

    // Assign a new value (10) to the static variable staticVar of the MyClass class// we have use :: for Calling Static Methods: and Accessing Static Members:
    MyClass::staticVar = 10;

    // Print the value of the static variable staticVar of the MyClass class
    cout << "Static variable: " << MyClass::staticVar << endl; // Output: Static variable: 10

    return 0;
}
