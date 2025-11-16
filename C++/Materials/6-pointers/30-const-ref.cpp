#include <iostream>

void printIt(const int& a)
{
    std::cout << a;
}

int main()
{
    int x = 3;
    printIt(x); // неконстантне l-value

    const int y = 4;
    printIt(y); // константне l-value

    printIt(5); // літерал в якості r-value

    printIt(3 + y); // вираз в якості r-value

    return 0;
}