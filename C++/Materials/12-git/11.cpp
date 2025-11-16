#include <iostream>

int sumArray(int array[]) // array - це вказівник
{
    int sum = 0;
    for (const auto& number : array) // помилка компіляції, розмір масиву невідомий
        sum += number;

    return sum;
}

int main()
{
    int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
    std::cout << sumArray(array); // array конвертується у вказівник тут
    return 0;
}