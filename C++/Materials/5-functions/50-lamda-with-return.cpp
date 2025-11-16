#include <iostream>

int main()
{
    auto sum{ [](int a, int b) {return a + b;} };

    // викликаємо лямбда-вираз
    std::cout << sum(10, 23) << std::endl;  // 33

    // присвоюємо його результат змінній
    int result{ sum(1, 4) };
    std::cout << result << std::endl;       // 5
}