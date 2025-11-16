#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter any chracter\n";
    cin >> ch;

    if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
        cout << "It is Alphabet";
    else if (ch >= 48 && ch <= 57)
        cout << "It is Digit";
    else
        cout << "It is Special symbol";
}