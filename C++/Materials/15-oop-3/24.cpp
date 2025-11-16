#include <iostream>

class Number
{
private:
    int m_number;
public:
    Number(int number = 0)
        : m_number(number)
    {
    }

    Number& operator++(); // версія префікс
    Number& operator--(); // версія префікс

    Number operator++(int); // версія постфікс
    Number operator--(int); // версія постфікс

    friend std::ostream& operator<< (std::ostream& out, const Number& n);
};

Number& Number::operator++()
{
    // Якщо значенням змінної m_number є 8, то скидаємо значення m_number в 0
    if (m_number == 8)
        m_number = 0;

    // В протилежному випадку, просто збільшуємо m_number на одиницю
    else
        ++m_number;

    return *this;
}

Number& Number::operator--()
{
    // Якщо значенням змінної m_number є 0, то присвоюємо m_number значення 8
    if (m_number == 0)
        m_number = 8;

    // В протилежному випадку, просто зменшуємо m_number на одиницю
    else
        --m_number;

    return *this;
}

Number Number::operator++(int)
{
    // Створюємо тимчасовий об'єкт класу Number з поточним значенням змінної m_number
    Number temp(m_number);

    // Використовуємо оператор інкременту версії префікс для реалізації перевантаження оператора інкременту версії постфікс
    ++(*this); // реалізація перевантаження

    // Повертаємо тимчасовий об'єкт
    return temp;
}

Number Number::operator--(int)
{
    // Створюємо тимчасовий об'єкт класу Number з поточним значенням змінної m_number
    Number temp(m_number);

    // Використовуємо оператор декременту версії префікс для реалізації перевантаження оператора декременту версії постфікс
    --(*this); // реалізація перевантаження

    // Повертаємо тимчасовий об'єкт
    return temp;
}

std::ostream& operator<< (std::ostream& out, const Number& n)
{
    out << n.m_number;
    return out;
}

int main()
{
    Number number(6);

    std::cout << number;
    std::cout << ++number; // викликається Number::operator++();
    std::cout << number++; // викликається Number::operator++(int);
    std::cout << number;
    std::cout << --number; // викликається Number::operator--();
    std::cout << number--; // викликається Number::operator--(int);
    std::cout << number;

    return 0;
}