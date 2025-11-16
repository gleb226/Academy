#include <iostream>

class Number
{
private:
    int _number;
public:
    Number(int number = 0)
        : _number(number)
    {
    }

    Number& operator++();
    Number& operator--();

    friend std::ostream& operator<< (std::ostream& out, const Number& n);
};

Number& Number::operator++()
{
    // Якщо значенням змінної _number є 8, то скидаємо значення _number в 0
    if (_number == 8)
        _number = 0;

    // В протилежному випадку, просто збільшуємо _number на одиницю
    else
        ++_number;

    return *this;
}

Number& Number::operator--()
{
    // Якщо значенням змінної _number є 0, то присвоюємо _number значення 8
    if (_number == 0)
        _number = 8;

    // В протилежному випадку, просто зменшуємо _number на одиницю
    else
        --_number;

    return *this;
}

std::ostream& operator<< (std::ostream& out, const Number& n)
{
    out << n._number;
    return out;
}

int main()
{
    Number number(7);

    std::cout << number;
    std::cout << ++number;
    std::cout << ++number;
    std::cout << --number;
    std::cout << --number;

    return 0;
}