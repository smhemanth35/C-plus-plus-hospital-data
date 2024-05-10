#include <iostream>
using namespace std;

void func() {
    static int count = 0;
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    func(); // Output: Count: 1
    func(); // Output: Count: 2
    return 0;
}
