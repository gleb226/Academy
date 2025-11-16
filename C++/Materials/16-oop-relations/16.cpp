#include <string>

class Human
{
private:
    std::string m_name;
    int m_age;

public:
    Human(std::string name, int age)
        : m_name(name), m_age(age)
    {
    }

    std::string getName() { return m_name; }
    int getAge() { return m_age; }
};

class Employee
{
private:
    std::string m_employer;
    double m_wage;

public:
    Employee(std::string employer, double wage)
        : m_employer(employer), m_wage(wage)
    {
    }

    std::string getEmployer() { return m_employer; }
    double getWage() { return m_wage; }
};

//  лас Teacher в≥дкрито насл≥дуЇ властивост≥ клас≥в Human ≥ Employee
class Teacher : public Human, public Employee
{
private:
    int m_teachesGrade;

public:
    Teacher(std::string name, int age, std::string employer, double wage, int teachesGrade)
        : Human(name, age), Employee(employer, wage), m_teachesGrade(teachesGrade)
    {
    }
};