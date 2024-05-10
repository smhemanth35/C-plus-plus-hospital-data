#include <iostream>
using namespace std; // Use the std namespace

class Singleton {
private:
    static Singleton* instance; // Static pointer to hold the single instance

    Singleton() {} // Private constructor

public:
    static Singleton* getInstance() {
        // Check if the instance is null (not created yet)
        if (instance == nullptr) {
            // Create a new instance of Singleton if it doesn't exist
            instance = new Singleton();
        }
        // Return the instance
        return instance;
    }
};

// Initialize the static instance pointer to null
Singleton* Singleton::instance = nullptr;

int main() {
    // Get the instance of Singleton using the getInstance() method
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    // Check if obj1 and obj2 point to the same instance
    cout << (obj1 == obj2 ? "Same instance" : "Different instance") << endl; // Output: Same instance

    return 0;
}
