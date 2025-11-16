#include <iostream>
#include <memory> // для std::unique_ptr і std::make_unique

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }
};


int main()
{
    // Створюємо об'єкт з динамічно виділеним Fraction з numerator = 7 і denominator = 9
    std::unique_ptr<Fraction> f1 = std::make_unique<Fraction>(7, 9);
    std::cout << *f1 << '\n';

    // Створюємо об'єкт з динамічно виділеним масивом Fraction довжиною 5.
    // Використовуємо автоматичне визначення типу даних за допомогою ключового слова auto
    auto f2 = std::make_unique<Fraction[]>(5);
    std::cout << f2[0] << '\n';

    return 0;
}