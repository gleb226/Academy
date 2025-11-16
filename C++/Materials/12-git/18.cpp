#include <iostream>
#include <string>

int main()
{
    std::string hello = "Hello, world!";
    int index;

    do
    {
        std::cout << "Enter an index: ";
        std::cin >> index;

        // Обробляємо випадок, коли користувач ввів нецілочисельне значення
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            index = -1; // переконуємося, що index має неприпустиме значення, щоб цикл продовжувався
            continue; // цей continue може здатися тут зайвим, але він явно вказує на готовність припинити виконання цієї ітерації циклу
        }

    } while (index < 0 || index >= hello.size()); // обробляємо випадок, коли користувач ввів значення поза діапазону

    std::cout << "Letter #" << index << " is " << hello[index] << std::endl;

    return 0;
}