#include <iostream>

class Parent
{
public:
    int m_id;

    Parent(int id = 0)
        : m_id(id)
    {
        std::cout << "Parent\n";
    }

    int getId() const { return m_id; }
};

class Child: public Parent
{
public:
    double m_value;

    Child(double value = 0.0)
        : m_value(value)
    {
        std::cout << "Child\n";
    }

    double getValue() const { return m_value; }
};

int main()
{
    std::cout << "Instantiating Parent:\n";
    Parent dParent;

    std::cout << "Instantiating Child:\n";
    Child dChild;

    return 0;
}