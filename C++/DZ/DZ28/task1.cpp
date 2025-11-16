#include <iostream>
using namespace std;

class Equation {
public:
    virtual void Roots() = 0;

    virtual ~Equation() {
    }
};

class LinearEquation : public Equation {
    double a, b;

public:
    LinearEquation(double _a, double _b) {
        a = _a;
        b = _b;
    }

    void Roots() override {
        if (a == 0) {
            if (b == 0) cout << "Infinite solutions\n";
            else cout << "No solution\n";
        } else {
            cout << "Root: " << -b / a << endl;
        }
    }
};

class QuadraticEquation : public Equation {
    double a, b, c;

public:
    QuadraticEquation(double _a, double _b, double _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    double sqrtApprox(double x) {
        if (x < 0) return -1;
        double r = x;
        for (int i = 0; i < 100; i++) r = 0.5 * (r + x / r);
        return r;
    }

    void Roots() override {
        if (a == 0) {
            LinearEquation(b, c).Roots();
            return;
        }
        double d = b * b - 4 * a * c;
        if (d < 0) cout << "No real roots\n";
        else if (d == 0) cout << "Root: " << -b / (2 * a) << endl;
        else {
            double sd = sqrtApprox(d);
            cout << "Roots: " << (-b + sd) / (2 * a) << " and " << (-b - sd) / (2 * a) << endl;
        }
    }
};

int main() {
    LinearEquation l(2, -4);
    QuadraticEquation q(1, -3, 2);
    l.Roots();
    q.Roots();
    return 0;
}
