#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie", "David", "Emma"};

    // Sort the names
    sort(names.begin(), names.end());

    // Print the sorted names
    cout << "Sorted names:\n";
    for (string name : names) {
        cout << name << "\n";
    }

    return 0;
}
