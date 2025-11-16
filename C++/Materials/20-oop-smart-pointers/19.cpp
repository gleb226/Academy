#include <iostream>
#include <memory> // для std::shared_ptr

class Item
{
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};

int main()
{
    Item* item = new Item;
    std::shared_ptr<Item> ptr1(item);
    {
        std::shared_ptr<Item> ptr2(item); // створюємо ptr2 напряму з item (замість ptr1)

        std::cout << "Killing one shared pointer\n";
    } // ptr2 виходить з області видимості тут, і виділений Item знищується також тут

    std::cout << "Killing another shared pointer\n";

    return 0;
} // ptr1 виходить з області видимості тут, і вже видалений Item знову знищується тут
