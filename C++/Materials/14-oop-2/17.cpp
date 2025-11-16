#include <iostream> 
#include <cassert>

class Drob
{
private:
    int numerator;
    int denominator
        ;

public:
    // Конструктор за замовчуванням
    Drob(int numerator = 0, int denominator = 1): numerator(numerator), denominator(denominator)
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<< (std::ostream& out, const Drob& d1);
};

std::ostream& operator<< (std::ostream& out, const Drob& d1)
{
    out << d1.numerator << "/" << d1.denominator;
    return out;
}

int main()
{
    Drob seven = Drob(7);
    std::cout << seven;
    return 0;
}