#include "stdafx.h"
#include <iostream>
using namespace std;

// Шаблонна функція, що повертає суму двох величин типу TT
template <class TT>
TT Add(TT t1, TT t2)
{
    return t1 + t2;
}

int main()
{
    // Використання шаблонної функції Add
    // 1. Для типу double
    double d1 = 3.85, d2 = 2.50;
    double d3;

    d3 = Add(d1, d2); // d3 = 6.35

    // 2. Для типу int
    int i1 = 25;
    int i2 = 13;
    int i3;
    i3 = Add(i1, i2); // i3 = 38

    // 3. Для типу string
    string s1 = "abc";
    string s2 = "def";
    string s3 = Add(s1, s2); // s3 = "abcdef"

    cout << s3.c_str() << endl;

    return 0;
}