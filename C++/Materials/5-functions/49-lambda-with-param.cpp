#include <iostream>

int main()
{
    auto print{ [](const std::string& text) {std::cout << text << std::endl;} };

    // викликаємо лямбда-вираз
    print("Hello World!");          // Hello World!
    print("Good bye, World...");    // Good bye, World...
}