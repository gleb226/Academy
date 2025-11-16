#include <iostream>

int main()
{
    int math[] = { 0, 1, 4, 5, 7, 8, 10, 12, 15, 17, 30, 41 };
    for (auto number : math) // тип number визначається автоматично, ґрунтуючись на типі елементів масиву math
        std::cout << number << ' ';

    return 0;
}