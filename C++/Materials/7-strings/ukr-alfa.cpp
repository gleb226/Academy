#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char ch = 'º';
    int i = ch;
    cout << ch << " - " << i << endl;
    cin >> ch;
    cout << "new value of ch: " << ch << " - " << i << endl;

    return 0;
}