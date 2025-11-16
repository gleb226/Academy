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
std::ranges::views::filter;

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

int main1() {
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

    // Відфільтровані студенти
    vector<shared_ptr<Person>> filteredPeople;

    // Фільтруємо студентів старших за 20 років та копіюємо їх у новий вектор
    copy_if(people, std::back_inserter(filteredPeople), [](const shared_ptr<Person>& person) {
        return person->age > 20;
    });

    // Використовуємо for_each для друку відфільтрованих студентів
    cout << "\nList of students older than 20:" << endl;
    for_each(filteredPeople, [](const shared_ptr<Person>& person) {
        person->print();
    });

    // Використовуємо for_each та фільтр для друку студентів старших за 20 років
    cout << "List of students older than 20:" << endl;
    for (auto person : people | 
        filter([](auto person) { return person->age > 20; }))
    {
        person->print();
    }

    for_each(filteredPeople | filter([](auto person) { return person->age > 20; }), 
        [](const shared_ptr<Person>& person) {
            person->print();
        });

    return 0;
}