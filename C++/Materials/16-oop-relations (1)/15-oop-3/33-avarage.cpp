#include <iostream>
#include <cstdint> // для цілочисельних значень фіксованого розміру

class Average
{
private:
    int32_t m_total = 0; // сума всіх отриманих значень
    int8_t m_numbers = 0; // кількість всіх отриманих значень

public:
    Average()
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Average& average)
    {
        // Середнє_значення = сума_всіх_отриманих_значень / кількість_всіх_отриманих_значень.
        // Слід пам'ятати, що тут повинне виконуватися ділення типу з плаваючою крапкою (а не типу int)
        out << static_cast<double>(average.m_total) / average.m_numbers;

        return out;
    }

    // Оскільки operator+=() змінює свій лівий операнд, то перевантаження слід виконувати через метод класу
    Average& operator+=(int num)
    {
        // Збільшуємо суму всіх отриманих значень новим значенням
        m_total += num;
        // І додаємо одиницю до загальної кількості отриманих чисел
        ++m_numbers;

        // Повертаємо поточний об'єкт, щоб мати можливість виконувати "ланцюжок" операцій з +=
        return *this;
    }
};

int main()
{
    Average avg;

    avg += 5;
    std::cout << avg << '\n'; // 5 / 1 = 5

    avg += 9;
    std::cout << avg << '\n'; // (5 + 9) / 2 = 7

    avg += 19;
    std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

    avg += -9;
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

    (avg += 7) += 11; // виконання "ланцюжка" операцій
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

    Average copy = avg;
    std::cout << copy << '\n';

    return 0;
}