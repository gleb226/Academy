#include <iostream>
using namespace std;

int main()
{
    float a1, a2, a3;
    cout << "Enter first angle\n";
    cin >> a1;
    cout << "Enter second angle\n";
    cin >> a2;
    cout << "Enter third angle\n";
    cin >> a3;
    if ((a1 + a2 + a3) == 180)
    {
        cout << "Triangle is valid";
    }
    else
    {
        cout << "Triangle is not valid";
    }
}