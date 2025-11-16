#include <iostream> 
#include <cassert>

class Drob
{
private:
    int numerator;
    int denominator;

public:
    // Конструктор за замовчуванням
    Drob(int numerator = 0, int denominator = 1): numerator(numerator), denominator(denominator)
    { 
        assert(denominator != 0);
    }

    // Конструктор копіювання
    Drob(const Drob& drob): numerator(drob.numerator), denominator(drob.denominator)
        // Примітка: Ми маємо прямий доступ до членів об'єкту drob, оскільки ми зараз знаходимося всередині класу Drob
    {
        // Немає необхідності виконувати перевірку denominator тут, так як ця перевірка вже здійснюється в конструкторі класу Drob
        std::cout << "Copy constructor worked here!\n"; // просто, щоб показати, що це працює
    }

    friend std::ostream& operator << (std::ostream& out, const Drob& d1);
};

std::ostream& operator << (std::ostream& out, const Drob& d1)
{
    out << d1.numerator << "/" << d1.denominator;
    return out;
}

int main()
{
    Drob sixSeven(6, 7); // пряма ініціалізація об'єкта класу Drob, викликається конструктор Drob(int, int)
    Drob dCopy(sixSeven); // пряма ініціалізація, викликається конструктор копіювання класу Drob
    std::cout << dCopy << '\n';
}