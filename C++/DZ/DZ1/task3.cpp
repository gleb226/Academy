#include <iostream>
using namespace std;

int main() {
    double v, t, a, S;

    cout << "Enter initial velocity (v): ";
    cin >> v;

    cout << "Enter time (t): ";
    cin >> t;

    cout << "Enter acceleration (a): ";
    cin >> a;

    S = v * t + (a * t * t) / 2;

    cout << "The distance traveled (S) is: " << S << endl;

    return 0;
}