#include <iostream>

int main()
{
    std::cout << "Enter a positive integer: ";
    int length;
    std::cin >> length;

    int* array = new int[length]; // використовуємо оператор new[] для виділення масиву. Зверніть увагу, змінна length не обов'язково повинна бути константою!

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 7; // присвоюємо елементу під індексом 0 значення 7

    delete[] array; // використовуємо оператор delete[] для звільнення виділеної масиву пам'яті
    array = 0; // використовуйте nullptr замість 0 в C++11

    return 0;
}