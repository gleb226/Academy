#include "stdafx.h"
#include <iostream>
using namespace std;

// шаблонна функція для типу T
template <class T>
void Display(T t)
{
    cout << "t = " << t << endl;
}

// явно "перевантажена" функція Display() для типу string
void Display(string t)
{
    // вивід типу string виділений окремою функцією
    cout << "t = " << t.c_str() << endl;
}

int main()
{
    int a = 10;
    double d = 3.55;
    string s = "Hello";

    // виклик шаблонної функції
    Display(a); // t = 10
    Display(d); // t = 3.55

    // виклик перевантаженої функції для типу string
    Display("abcd"); // t = abcd
    Display(s); // t = Hello

    return 0;
}