/*The Math namespace is defined to encapsulate related constants, functions, or variables.
Inside the Math namespace, there is a constant PI representing the value of Pi and a function square to calculate the square of an integer.*/
#include <iostream>

// Define a namespace Math
namespace Math {
    const float PI = 3.14159; // Constant representing PI

    // Function to calculate square of an integer
    int square(int x) {
        return x * x;
    }
}

int main() {
    // Access and print the value of PI from the Math namespace
    std::cout << "PI: " << Math::PI << std::endl; // Output: PI: 3.14159

    // Call the square function from the Math namespace and print the result
    std::cout << "Square of 5: " << Math::square(5) << std::endl; // Output: Square of 5: 25

    return 0;
}
