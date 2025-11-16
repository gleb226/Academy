#include <iostream>
#include <string>
#include <array>

int main() {
    std::array<std::string, 8> names = {"Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly"};

    std::string inputName;
    bool found = false;

    std::cout << "Enter a name: ";
    std::getline(std::cin, inputName);

    found = false;
    for (const std::string& name : names) {
        if (name == inputName) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << inputName << " was found." << std::endl;
    } else {
        std::cout << inputName << " was not found." << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Enter a name: ";
    std::getline(std::cin, inputName);

    found = false;
    for (const std::string& name : names) {
        if (name == inputName) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << inputName << " was found." << std::endl;
    } else {
        std::cout << inputName << " was not found." << std::endl;
    }

    return 0;
}