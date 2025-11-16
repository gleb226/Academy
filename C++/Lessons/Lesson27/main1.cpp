#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidDimensionException : exception {
public:
    const char* what() { return "invalid dimension"; }
};

class Rectangle {
    double w, h;
public:
    Rectangle(double a, double b) {
        if (a <= 0 || b <= 0) throw InvalidDimensionException();
        w = a; h = b;
    }
    double area() { return w*h; }
};

int main() {
    try {
        Rectangle r1(5,3);
        cout << "area: " << r1.area() << endl;
        Rectangle r2(0,4);
    } catch (InvalidDimensionException e) {
        cout << "error: " << e.what() << endl;
    }
}