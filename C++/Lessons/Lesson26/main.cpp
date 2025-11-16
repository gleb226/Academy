#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int b = 1;
    int c = add(2, b);
    std::cout << c << "\n";
    return 0;
}
