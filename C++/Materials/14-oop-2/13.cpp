#include <iostream>
#include <vector>

class Something
{
private:
    static std::vector<char> s_mychars;

public:
    class _nested // визначаємо вкладений клас з іменем _nested
    {
    public:
        _nested() // конструктор _nested() ініціалізує нашу статичну змінну-член
        {
            s_mychars.push_back('o');
            s_mychars.push_back('a');
            s_mychars.push_back('u');
            s_mychars.push_back('i');
            s_mychars.push_back('e');
        }
    };

    // Статичний метод для виводу s_mychars
    static void getSomething() {
        for (auto const& element : s_mychars)
            std::cout << element << ' ';
    }
private:
    static _nested s_initializer; // використовуємо статичний об'єкт класу _nested для гарантії того, що конструктор _nested() виконається
};

std::vector<char> Something::s_mychars; // визначаємо нашу статичну змінну-член
Something::_nested Something::s_initializer; // визначаємо наш статичний s_initializer, який викличе конструктор _nested() для ініціалізації s_mychars

int main() {
    Something::getSomething();
    return 0;
}