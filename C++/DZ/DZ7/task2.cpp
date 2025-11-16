#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// int main()
// {
//     int x, y;
//     cout << "Enter first integer: ";
//     cin >> x;
//
//     cout << "Enter second integer: ";
//     cin >> y;
//
//     cout << "GCD: " << gcd(x, y) << "\n";
//
//     return 0;
// }
