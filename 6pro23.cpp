/*Global Variables: Global variables are variables declared outside of any function or class. They have global scope
and can be accessed from any part of the program*/
#include <iostream>

// Global variable declaration
int globalVar = 100;

// Function definition
void func() {
    // Access and print the global variable inside the function
    std::cout << "Global variable inside func(): " << globalVar << std::endl;
}

// Main function
int main() {
    // Access and print the global variable in main
    std:: cout << "Global variable in main(): " << globalVar << std::endl;

    // Call the func() function to demonstrate access to the global variable
    func(); // Output: Global variable inside func(): 100

    return 0;
}
