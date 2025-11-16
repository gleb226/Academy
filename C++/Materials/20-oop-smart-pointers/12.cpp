#include <iostream>
#include <memory> // для std::unique_ptr

class Item
{
public:
	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
};

int main()
{
	std::unique_ptr<Item> item1(new Item); // виділення Item
	std::unique_ptr<Item> item2; // присвоюється значення nullptr

	std::cout << "item1 is " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
	std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null\n" : "null\n");

	// item2 = item1; // не скомпілюється: семантика копіювання відключена
	item2 = std::move(item1); // item2 тепер володіє item1, а для item1 присвоюється значення null

	std::cout << "Ownership transferred\n";

	std::cout << "item1 is " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
	std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null\n" : "null\n");

	return 0;
} // Item знищується тут, коли item2 виходить з області видимості
