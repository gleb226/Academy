#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter any alphabet\n";
    cin >> ch;
    if (ch >= 65 && ch <= 97)
        cout << (char)(ch + 32);
    else
        cout << (char)(ch - 32);
}