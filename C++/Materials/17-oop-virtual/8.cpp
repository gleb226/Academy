#include <iostream>
#include <string>

class Animal // це абстрактний батьківський клас
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // зверніть увагу, speak() є чистою віртуальною функцією
};

const char* Animal::speak()
{
    return "buzz"; // реалізація за замовчуванням
}

class Dragonfly : public Animal
{

public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() // цей клас вже не є абстрактним, тому що ми перевизначили функцію speak()
    {
        return Animal::speak(); // використовується реалізація за замовчуванням класу Animal
    }
};

int main()
{
    Dragonfly dfly("Barbara");
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
}