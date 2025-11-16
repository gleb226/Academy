#include <iostream>

int main()
{
    int math[] = { 0, 1, 4, 5, 7, 8, 10, 12, 15, 17, 30, 41 };
    for (int number : math) // ітерація по масиву math
        std::cout << number << ' '; // отримуємо доступ до елементу масиву в цій ітерації через змінну number

    return 0;
}