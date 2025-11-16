#include <iostream>

int main()
{
    enum Fruits
    {
        LEMON, // LEMON знаходиться всередині тієї ж області видимості, що і Fruits
        KIWI
    };

    enum Colors
    {
        PINK, // PINK знаходиться всередині тієї ж області видимості, що і Colors
        GRAY
    };

    Fruits fruit = LEMON; // Fruits і LEMON доступні в одній області видимості (додавати префікс не потрібно)
    Colors color = PINK; // Colors і PINK доступні в одній області видимості (додавати префікс не потрібно)

    if (fruit == color) // компілятор порівнюватиме ці змінні, як цілі числа
        std::cout << "fruit and color are equal\n"; // і виявить, що вони рівні!
    else
        std::cout << "fruit and color are not equal\n";

    return 0;
}