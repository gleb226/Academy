#include <iostream>
#include <string>

class Employee
{
public:
    std::string m_name;
    int m_id;
    double m_wage;

    // Метод виводу інформації про працівника на екран
    void print()
    {
        std::cout << "Name: " << m_name <<
            "\nId: " << m_id <<
            "\nWage: $" << m_wage << '\n';
    }
};

int main()
{
    // Визначаємо двох працівників
    Employee john{ "John", 5, 30.00 };
    Employee max{ "Max", 6, 32.75 };

    // Виводимо інформацію про працівників на екран
    john.print();
    std::cout << std::endl;
    max.print();

    return 0;
}