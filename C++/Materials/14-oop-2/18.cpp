#include <iostream> 
#include <cassert>

class Drob
{
private:
    int numerator;
    int denominator;

public:
    // Конструктор за замовчуванням
    Drob(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator)
    {
        assert(denominator != 0);
    }

    // Конструктор копіювання
    Drob(const Drob& copy) : numerator(copy.numerator), denominator(copy.denominator)
    {
        // Немає необхідності виконувати перевірку denominator тут, так як вона здійснюється в конструкторі за замовчуванням
        std::cout << "Copy constructor worked here!\n"; // просто щоб показати, що це працює
    }

    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
    int getNumerator() { return numerator; }
    void setNumerator(int numerator) { this->numerator = numerator; }
};

std::ostream& operator<<(std::ostream& out, const Drob& d1)
{
    out << d1.numerator << "/" << d1.denominator;
    return out;
}

Drob makeNegative(Drob d) // правильно було б тут використати константне посилання
{
    d.setNumerator(-d.getNumerator());
    return d;
}

int main()
{
    Drob sixSeven(6, 7);
    std::cout << makeNegative(sixSeven);

    return 0;
}