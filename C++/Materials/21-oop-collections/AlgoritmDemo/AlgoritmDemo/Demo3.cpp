#include <algorithm>
#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <vector>

using std::cout,
std::cin,
std::endl,
std::string,
std::vector,
std::shared_ptr,
std::make_shared,
std::ranges::for_each,
std::ranges::copy_if,
std::back_inserter,
std::ranges::transform;

// Клас Person
class Person {
public:
    string name;
    int age;

    // Конструктор
    Person(string name, int age) : name(name), age(age) {}

    // Метод друку інформації про об'єкт
    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main3() {
    // Створюємо вектор студентів за допомогою make_shared
    vector<shared_ptr<Person>> people;
    people.push_back(make_shared<Person>("Alice", 20));
    people.push_back(make_shared<Person>("Bob", 22));
    people.push_back(make_shared<Person>("Charlie", 19));
    people.push_back(make_shared<Person>("David", 21));
    people.push_back(make_shared<Person>("Eve", 23));
    people.push_back(make_shared<Person>("Vladislav", 15));

    // Використовуємо for_each для друку всіх студентів
    cout << "List of students:" << endl;
    for_each(people, [](const shared_ptr<Person>& person) {
        person->print();
    });

    // Отримуємо всі імена людей у вектор string
    vector<string> names;

    transform(people, back_inserter(names), [](auto person) {
        return person->name;
    });

    vector<shared_ptr<Person>> modifiedPeople;

    transform(people, back_inserter(modifiedPeople), [](auto person) {
        person->name[0] = tolower(person->name[0]);
        return person;
    });

    // Друкуємо всі імена
    cout << "\nList of names:" << endl;
    for (const auto& name : names) {
        cout << name << endl;
    }

    for_each(people, [](const shared_ptr<Person>& person) {
        person->print();
        });

    return 0;
}

