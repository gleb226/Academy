#include <iostream>

int main()
{
    // the hello variable represents a lambda expression 
    auto hello{ []() { std::cout << "Hello" << std::endl; } };

    // через змінну викликаємо лямбда-вираз
    hello();    // Hello
    hello();    // Hello
}