#include <iostream>
#include <string>

int main()
{
    try
    {
        // Тут ми пишемо стейтменти, які генеруватимуть наступний виняток
        throw - 1; // типовий стейтмент throw
    }
    catch (int a)
    {
        // Будь-які винятки типу int, згенеровані в блоці try, наведеному вище, обробляються тут
        std::cerr << "We caught an int exception with value: " << a << '\n';
    }
    catch (double) // ми не вказуємо ім'я змінної, тому що в цьому немає необхідності (ми її ніде в блоці не використовуємо)
    {
        // Будь-які винятки типу double, згенеровані в блоці try, наведеному вище, обробляються тут
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string& str) // ловимо винятки по константному посиланню
    {
        // Будь-які винятки типу std::string, згенеровані всередині блоку try, наведеному вище, обробляються тут
        std::cerr << "We caught an exception of type std::string" << '\n';
    }

    std::cout << "Continuing our way!\n";

    return 0;
}