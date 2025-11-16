#include <array>
#include <iostream>

int main()
{
    std::array data{ 0, 1, 2, 3, 4, 5, 6 };

    auto begin{ &data[0] };

    // Зверніть увагу, що тут ми вказуємо на місце, яке слідує за останнім елементом
    auto end{ begin + std::size(data) };

    // Цикл for з використанням вказівника
    for (auto ptr{ begin }; ptr != end; ++ptr) // виконуємо інкремент для переходу до наступного елементу
    {
        std::cout << *ptr << ' '; // розіменовуємо вказівник для отримання поточного значення елементу
    }
    std::cout << '\n';

    return 0;
}