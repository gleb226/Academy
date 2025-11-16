#include <iostream>

int main()
{
    int n{ 10 };
    auto increment = [=]() mutable {
        n++;    // збільшуємо значення зовнішньої змінної n
        std::cout << "n inside lambda: " << n << std::endl;
        };
    increment();
    std::cout << "n outside lambda: " << n << std::endl;
}