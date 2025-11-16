#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // Ми робимо цей конструктор protected, тому що не хочемо, щоб користувачі мали можливість створювати об'єкти класу Animal напряму,
    // але хочемо, щоб в дочірніх класах доступ був відкритий
    Animal(std::string name)
        : m_name(name)
    {
    }

public:
    std::string getName() { return m_name; }
    const char* speak() { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {
    }

    const char* speak() { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {
    }

    const char* speak() { return "Woof"; }
};

void report(Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat("Matros");
    Dog dog("Barsik");

    report(cat);
    report(dog);
}