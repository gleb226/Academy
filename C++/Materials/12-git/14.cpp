#include <iostream>
#include <array>

int main()
{
    std::array array{ 1, 2, 3 };

    // Просимо наш масив вказати нам початкову і кінцеву точки за допомогою функцій begin() і end()
    auto begin{ array.begin() };
    auto end{ array.end() };

    for (auto p{ begin }; p != end; ++p) // виконуємо інкремент для переходу до наступного елементу
    {
        std::cout << *p << ' '; // розіменовуємо вказівник для отримання поточного значення елементу
    }
    std::cout << '\n';

    return 0;
}