#include <iostream>
using namespace std;

int main()
{
    float p;
    cout << "Enter your percent\n";
    cin >> p;
    if (p <= 100 && p >= 80)
        cout << "First class";
    if (p < 80 && p >= 65)
        cout << "Second class upper";
    if (p < 65 && p >= 55)
        cout << "Second class lower";
    if (p < 55 && p >= 45)
        cout << "Pass";
    if (p < 45)
        cout << "Fail";
}