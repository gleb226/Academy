#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age\n";
    cin >> age;
    if (age > 18)
    {
        cout << "You're eligible for voting";
    }
    else
    {
        cout << "You're not eligible for voting";
    }
}