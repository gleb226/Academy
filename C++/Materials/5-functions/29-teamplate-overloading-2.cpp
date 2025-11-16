#include "stdafx.h"
#include <iostream>
using namespace std;

// шаблонна функція Max() для типу T,
// яка повертає максимум між двома значеннями value1, value2
template <typename T>
T Max(T value1, T value2)
{
    if (value1 > value2) return value1;
    return value2;
}

// "перевантажена" шаблонна функція Max()
// знаходить максимум між трьома значеннями value1, value2, value3
template <class T>
T Max(T value1, T value2, T value3)
{
    T max = value1;
    if (max < value2) max = value2;
    if (max < value3) max = value3;
    return max;
}

// "перевантажена" шаблонна функція Max()
// максимум між чотирма значеннями
template <typename T>
T Max(T value1, T value2, T value3, T value4)
{
    T max = value1;
    if (max < value2) max = value2;
    if (max < value3) max = value3;
    if (max < value4) max = value4;
    return max;
}

int main()
{
    // демонстрація використання "перевантаженої" шаблонної функції Max()
    int i;
    double d;
    bool b;
    char c;

    // для типу int
    i = Max(8, 11); // i = 11
    i = Max(9, 13, 14); // i = 14
    i = Max(8, 10, 4, -3); // i = 10

    // для типу double
    d = Max(3.5, 1.2); // d = 3.5
    d = Max(1.3, -9.20, 100.33); // d = 100.33
    d = Max(-39.5, 8.82, 1.23); // d = 8.82

    // для типу bool
    b = Max(true, false); // b = 1

    // для типу char
    c = Max('C', 'F'); // c = 'F'
    c = Max('F', 'H', 'G'); // c = 'H'
    c = Max('M', 'A', 'X', 'W'); // c = 'X'

    return 0;
}