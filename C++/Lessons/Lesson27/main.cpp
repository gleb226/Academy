#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
    int a, b;
public:
    Fraction(int x, int y) {
        if (y == 0) throw runtime_error("invalid denominator");
        a = x; b = y;
    }
    void print() {
        cout << a << "/" << b << endl;
    }
};

int main() {
    int n, d;
    cout << "Enter the numerator: ";
    cin >> n;
    cout << "Enter the denominator: ";
    cin >> d;
    try {
        Fraction f(n, d);
        f.print();
    } catch (exception e) {
        cout << "Your fraction has an invalid denominator." << endl;
    }
}

