#include <iostream>

class Parent
{
private: // наш m_id тепер закритий
    int m_id;

public:
    Parent(int id = 0)
        : m_id(id)
    {
    }

    int getId() const { return m_id; }
};
class Child : public Parent
{
private: // наш m_value тепер закритий
    double m_value;

public:
    Child(double value = 0.0, int id = 0)
        : Parent(id), // викликається конструктор Parent(int) зі значенням id!
        m_value(value)
    {
    }

    double getValue() const { return m_value; }
};

int main()
{
    Child child(1.5, 7); // викликається конструктор Child(double, int)
    std::cout << "ID: " << child.getId() << '\n';
    std::cout << "Value: " << child.getValue() << '\n';

    return 0;
}