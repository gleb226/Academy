#include <array>
#include <iostream>
#include <iterator> // для std::begin() і std::end()

int main()
{
    std::array array{ 1, 2, 3 };

    // Використовуємо std::begin() і std::end() для отримання початкової і кінцевої точок array
    auto begin{ std::begin(array) };
    auto end{ std::end(array) };

    for (auto p{ begin }; p != end; ++p) // виконуємо інкремент для переходу до наступного елементу
    {
        std::cout << *p << ' '; // розіменовуємо вказівник для отримання поточного значення елементу
    }
    std::cout << '\n';

    return 0;
}