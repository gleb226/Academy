#include <iostream>
#include <functional>   // для std::function

class Sum
{
public:
    int operator()(int a, int b) { return a + b; }
};

int subtract(int a, int b) { return a - b; }

int main()
{
    std::function<int(int, int)> operation;

    operation = Sum{};  // operation представляє об'єкт-функцію Sum
    std::cout << operation(10, 6) << std::endl;     // 16

    operation = subtract;  // operation представляє функцію subtract
    std::cout << operation(10, 6) << std::endl;     // 4

    auto multiply = [](int a, int b) {return a * b;};
    operation = multiply;  // operation представляє лямбда-вираз multiply
    std::cout << operation(10, 6) << std::endl;     // 60
}