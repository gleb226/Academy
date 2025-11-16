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

int main()
{
	std::unique_ptr<Item> item(new Item);

	if (item) // використовуємо неявну конвертацію item в тип bool, щоб переконатися, що item володіє Item-ом
		std::cout << *item; // виводимо Item, яким володіє item

	return 0;
}