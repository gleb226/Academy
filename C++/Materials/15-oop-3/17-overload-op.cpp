#include <iostream>

class Dollars
{
private:
    int m_dollars;

public:
    Dollars(int dollars) { m_dollars = dollars; }

    // Виконуємо Dollars + int
    Dollars operator+(int value);

    int getDollars() { return m_dollars; }
};

// Примітка: Ця функція є методом класу!
// Замість параметру dollars в перевантаженні через дружню функцію тут неявний параметр, на який вказує вказівник *this
Dollars Dollars::operator+(int value)
{
    return Dollars(m_dollars + value);
}

int main()
{
    Dollars dollars1(7);
    Dollars dollars2 = dollars1 + 3;
    std::cout << "I have " << dollars2.getDollars() << " dollars.\n";

    return 0;
}