#include <iostream> 
#include <cassert>

class Drob
{
private:
    int numerator;
    int denominator;

    // Конструктор копіювання (закритий)
    Drob(const Drob& drob): numerator(drob.numerator), denominator(drob.denominator)
    {
        // Немає необхідності виконувати перевірку denominator тут, так як ця перевірка вже здійснюється в конструкторі класу Drob
        std::cout << "Copy constructor worked here!\n"; // просто, щоб показати, що це працює
    }

public:
    // Конструктор за замовчуванням
    Drob(int numerator = 0, int denominator = 1) :
        numerator(numerator), denominator(denominator)
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
};

std::ostream& operator << (std::ostream& out, const Drob& d1)
{
    out << d1.numerator << "/" << d1.denominator;
    return out;
}

int main()
{
    Drob sixSeven(6, 7); // пряма ініціалізація об'єкта класу Drob, викликається конструктор Drob(int, int)
    Drob dCopy(sixSeven); // конструктор копіювання є закритим, тому цей рядок викличе помилку компіляції
    std::cout << dCopy << '\n';
}