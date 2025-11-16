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

void takeOwnership(std::unique_ptr<Item> item)
{
	if (item)
		std::cout << *item;
} // Item знищується тут

int main()
{
	auto ptr = std::make_unique<Item>();

	//    takeOwnership(ptr); // це не скомпілюється. Ми повинні використати семантику переміщення
	takeOwnership(std::move(ptr)); // використовуємо семантику переміщення

	std::cout << "Ending program\n";

	return 0;
}