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
	// Виділяємо Item і передаємо його в std::shared_ptr
	auto ptr1 = std::make_shared<Item>();
	{
		auto ptr2 = ptr1; // створюємо ptr2 з ptr1, використовуючи семантику копіювання

		std::cout << "Killing one shared pointer\n";
	} // ptr2 виходить з області видимості тут, але більше нічого не відбувається

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 виходить з області видимості тут, і виділений Item також знищується тут
