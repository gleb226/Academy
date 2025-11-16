#include <iostream>

class Values
{
private:
    int m_value1;
    double m_value2;
    char m_value3;

public:
    Values(int value1, double value2, char value3 = 'd')
        : m_value1(value1), m_value2(value2), m_value3(value3) // напряму ініціалізуємо змінні-члени класу
    {
        // Немає необхідності у використанні операцій присвоювання
    }

    void print()
    {
        std::cout << "Values(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }

};

int main()
{
    Values value(3, 4.5); // value1 = 3, value2 = 4.5, value3 = 'd' (значення за замовчуванням)
    value.print();
    return 0;
}