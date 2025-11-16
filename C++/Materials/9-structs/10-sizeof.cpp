#include <iostream>

struct Employee
{
    short id;
    int age;
    double salary;
};

int main()
{
    std::cout << "The size of Employee is " << sizeof(Employee) << "\n";

    return 0;
}