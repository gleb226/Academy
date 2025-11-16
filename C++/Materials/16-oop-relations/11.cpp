
#include <iostream>
#include <string>

class Human
{
public:
    std::string m_name;
    int m_age;

    Human(std::string name = "", int age = 0)
        : m_name(name), m_age(age)
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

};

// BasketballPlayer відкрито наслідує Human
class BasketballPlayer : public Human
{
public:
    double m_gameAverage;
    int m_points;

    BasketballPlayer(double gameAverage = 0.0, int points = 0)
        : m_gameAverage(gameAverage), m_points(points)
    {
    }
};

int main()
{
    // Створюємо нового Баскетболіста
    BasketballPlayer anton;

    // Присвоюємо йому ім'я (ми можемо зробити це напряму, тому що m_name є public)
    anton.m_name = "Anton";

    // Виводимо ім'я Баскетболіста
    std::cout << anton.getName() << '\n'; // використовуємо метод getName(), який ми успадкували від класу Human

    return 0;
}