#include <iostream>

int main()
{
    auto add = [](auto a, auto b) {return a + b;};
    //auto print = [](const auto& value) {std::cout << value << std::endl; };

    std::cout << add(2, 3) << std::endl;        // 5 - складаємо числа int
    std::cout << add(2.2, 3.4) << std::endl;    // 5.6 - складаємо числа double

    std::string hello{ "hello " };
    std::string world{ "world" };
    std::cout << add(hello, world) << std::endl;    // hello world - складаємо рядки
}