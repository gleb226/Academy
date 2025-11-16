#include <iostream>

class IDGenerator
{
private:
    static int s_nextID; // оголошення статичної змінної-члена

public:
    static int getNextID(); // оголошення статичного методу
};

// Визначення статичної змінної-члена знаходиться поза тілом класу. Зверніть увагу, ми не використовуємо тут ключове слово static.
// Починаємо генерувати ID з 1
int IDGenerator::s_nextID = 1;

// Визначення статичного методу знаходиться поза тілом класу. Зверніть увагу, ми не використовуємо тут ключове слово static
int IDGenerator::getNextID() { return s_nextID++; }

int main()
{
    for (int count = 0; count < 4; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}