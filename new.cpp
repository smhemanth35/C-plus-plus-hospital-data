#include <iostream>

int main() {
    // Dynamically allocate memory for an integer using 'new'
    int* ptr = new int;

    // Check if memory allocation was successful
    if (ptr == nullptr) {
        std::cout << "Memory allocation failed!\n";
        return 0; // Exit the program indicating failure
    }

    // Assign a value to the dynamically allocated integer
    *ptr = 42;

    // Print the value
    std::cout << "Dynamically allocated integer value: " << *ptr << std::endl;

    // Don't forget to free the allocated memory using 'delete'
    delete ptr;

    return 0;
}
