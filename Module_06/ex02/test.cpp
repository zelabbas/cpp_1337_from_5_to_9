#include <iostream>

void modifyValue(int& value) {
    value = 42;
}

void attemptModification(const int& value) {
    // Cast away const to modify the value
    modifyValue(const_cast<int&>(value));
}

int main() {
    const int x = 10;
    std::cout << "Before: " << x << std::endl;
    attemptModification(x);
    std::cout << "After: " << x << std::endl;
    return 0;
}
