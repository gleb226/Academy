#include <iostream> 
#include <string>

class Employee
{
private:
    int id;
    std::string name;

public:
    Employee(int id = 0, const std::string& name = "") :
        id(id), name(name)
    {
        std::cout << "Employee " << name << " created.\n";
    }

    // Використовуємо делегуючі конструктори для зменшення дубльованого коду
    Employee(const std::string& name) : Employee(0, name) { }
};

int main()
{
    Employee a;
    Employee b("Ivan");

    return 0;
}