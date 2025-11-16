#include <iostream>

void doOperation(int a, int b, int (*op)(int, int))
{
    std::cout << op(a, b) << std::endl;
}

int main()
{
    auto sum{ [](int a, int b) {return a + b;} };
    auto subtract{ [](int a, int b) {return a - b;} };

    doOperation(10, 4, sum);          // 14
    doOperation(10, 4, subtract);     // 6
}