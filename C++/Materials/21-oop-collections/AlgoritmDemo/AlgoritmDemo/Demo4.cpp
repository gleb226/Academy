#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Визначення класу Employee
class Employee {
public:
    string name;
    int age;

    // Конструктор
    Employee(string n, int a) : name(move(n)), age(a) {}

    // Метод для друку інформації про співробітника
    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Власна реалізація for_each
template <typename Iterator, typename Func>
void for_each(Iterator first, Iterator last, Func f) {
    while (first != last) {
        f(*first);
        ++first;
    }
}

int main4() {
    // Створення вектора співробітників
    vector<Employee> employees{
        {"Alice", 30},
        {"Bob", 24},
        {"Charlie", 29},
        {"David", 35},
        {"Eve", 28}
    };

    // Виведення інформації про кожного співробітника
    cout << "Employee Information:" << endl;
    for_each(employees.begin(), employees.end(), [](const Employee& emp) {
        emp.print();
        });

    for_each(employees.begin(), employees.end(), [](const Employee& emp) {
        emp.print();
        });

    // Обчислення середнього віку співробітників
    int totalAge = accumulate(employees.begin(), employees.end(), 0, [](int sum, const Employee& emp) {
        return sum + emp.age;
        });
    double averageAge = static_cast<double>(totalAge) / employees.size();

    // Виведення середнього віку
    cout << "\nAverage Age: " << averageAge << endl;

    return 0;
}
