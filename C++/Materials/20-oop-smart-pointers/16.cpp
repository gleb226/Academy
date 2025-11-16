#include <iostream>
#include <memory> // для std::unique_ptr

class Item
{
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }

    friend std::ostream& operator<<(std::ostream& out, const Item& item)
    {
        out << "I am an Item!\n";
        return out;
    }
};

// Ця функція використовує тільки Item, тому ми передаємо вказівник на Item, а не посилання на весь std::unique_ptr<Item>
void useItem(Item* item)
{
    if (item)
        std::cout << *item;
}

int main()
{
    auto ptr = std::make_unique<Item>();

    useItem(ptr.get()); // примітка: Метод get() використовується для отримання вказівника на Item

    std::cout << "Ending program\n";

    return 0;
} // Item знищується тут