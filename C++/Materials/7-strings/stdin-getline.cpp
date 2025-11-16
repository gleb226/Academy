#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string myName;
    std::getline(std::cin, myName); // повністю вилучаємо рядок в змінну myName

    std::cout << "Enter your age: ";
    std::string myAge;
    std::getline(std::cin, myAge); // повністю вилучаємо рядок в змінну myAge

    std::cout << "Your name is " << myName << " and your age is " << myAge;
}