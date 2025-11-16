#include <iostream>
using namespace std;

int main()
{
    float p;
    cout << "Enter your percent\n";
    cin >> p;

    if (p >= 60)
        cout << "First division";
    else if (p >= 45)
        cout << "Second division";
    else if (p >= 33)
        cout << "Third division";
    else
        cout << "Fail";
}