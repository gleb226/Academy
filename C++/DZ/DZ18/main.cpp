#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) denominator = 1;
    }

    void print() {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    Fraction f1, f2;

    cout << "Enter first fraction:\n";
    f1.input();
    cout << "Enter second fraction:\n";
    f2.input();

    cout << "\nFirst fraction: ";
    f1.print();
    cout << "\nSecond fraction: ";
    f2.print();
    cout << "\n";

    return 0;
}
