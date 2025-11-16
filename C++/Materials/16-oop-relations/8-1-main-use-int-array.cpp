#include <iostream>
#include "ArrayInt.h"

int main()
{
    // Оголошуємо масив з 10-ма елементами
    ArrayInt array(10);

    // Заповнюємо масив числами від 1 до 10
    for (int i = 0; i < 10; i++)
        array[i] = i + 1;

    // Змінюємо розмір масиву до 7 елементів
    array.resize(7);

    // Додаємо число 15 перед елементом з індексом 4
    array.insertBefore(15, 4);

    // Видаляємо елемент з індексом 5
    array.remove(5);

    // Додаємо числа 35 і 50 в кінець і в початок
    array.insertAtEnd(35);
    array.insertAtBeginning(50);

    // Виводимо всі елементи масиву на екран
    for (int j = 0; j < array.getLength(); j++)
        std::cout << array[j] << " ";

    return 0;
}