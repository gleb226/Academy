#include <iostream>

int main()
{
    enum class Fruits // додання "class" до enum визначає перерахування з обмеженою областю видимості, замість стандартного "глобального" перерахування
    {
        LEMON, // LEMON знаходиться всередині тієї ж області видимості, що і Fruits
        Kiwi
    };

    enum class Colors
    {
        PINK, // PINK знаходиться всередині тієї ж області видимості, що і Colors
        GRAY
    };

    Fruits fruit = Fruits::LEMON; // примітка: LEMON напряму не доступний, ми повинні використовувати Fruits::LEMON
    Colors color = Colors::PINK; // примітка: PINK напряму не доступний, ми повинні використовувати Colors::PINK

    if (fruit == color) // помилка компіляції, оскільки компілятор не знає як порівнювати різні типи: Fruits і Colors
        std::cout << "fruit and color are equal\n";
    else
        std::cout << "fruit and color are not equal\n";

    return 0;
}