#include <iostream>
using namespace std;

int main() {
    // Declare variables to store the two numbers
    int num1, num2;

    // Ask the user to input the first number

    cout << "Enter the first number: ";
    cin >> num1;

    // Ask the user to input the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Add the two numbers and store the result in a variable
    int sum = num1 + num2;

    // Display the result
    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;

    return 0;
}
