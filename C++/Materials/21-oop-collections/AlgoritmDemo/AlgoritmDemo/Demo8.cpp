#include <iostream>
#include <vector>
#include <algorithm>

// Клас, що представляє особу
class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    // Метод для отримання віку особи
    int getAge() const {
        return age;
    }

    // Перевантаження оператору < для порівняння за віком
    bool operator<(const Person& other) const {
        return age < other.age;
    }

    // Метод для виведення даних про особу
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main8() {
    // Створення вектора об'єктів класу Person
    std::vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20},
        {"David", 35},
        {"Eve", 28}
    };

    // Виведення вмісту вектора перед сортуванням
    std::cout << "Before nth_element:" << std::endl;
    for (const auto& person : people) {
        person.display();
    }

    // Використання std::nth_element для вибору елемента з другим за віком
    size_t n = 2; // Вибираємо другу за віком особу
    std::nth_element(people.begin(), people.begin() + n - 1, people.end(),
        [](const Person& p1, const Person& p2) {
            return p1.getAge() < p2.getAge();
        });

    // Виведення результату після вибору n-го елемента
    std::cout << "\nAfter nth_element (n = " << n << "):" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        people[i].display();
    }

    return 0;
}