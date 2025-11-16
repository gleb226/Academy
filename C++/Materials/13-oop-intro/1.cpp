#include <iostream>

class DateClass
{
public:
    int m_day;
    int m_month;
    int m_year;

    void print()
    {
        std::cout << m_day << "/" << m_month << "/" << m_year;
    }
};

int main()
{
    DateClass today{ 12, 11, 2018 };

    today.m_day = 18; // використовуємо оператор вибору членів для вибору змінної-члена m_day об'єкта today класу DateClass
    today.print(); // використовуємо оператор вибору членів для виклику метода print() об'єкта today класу DateClass

    return 0;
}