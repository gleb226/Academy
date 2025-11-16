#include <iostream>

int main()
{
    int n{ 10 };
    auto add = [=](int x) { std::cout << x + n << std::endl; };
    add(4); // 14
}