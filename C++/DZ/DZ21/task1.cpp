#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int a = numerator, b = denominator;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        numerator /= a;
        denominator /= a;
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) denominator = 1;
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(3, 4);

    Fraction c = a + b;
    Fraction d = a - b;
    Fraction e = a * b;
    Fraction f = a / b;

    c.display();
    d.display();
    e.display();
    f.display();

    return 0;
}
