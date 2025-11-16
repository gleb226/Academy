#include <iostream>

class Fruit
{
public:
	// Ми перемістили FruitList всередину класу під специфікатор доступу public
	enum FruitList
	{
		AVOCADO,
		BLACKBERRY,
		LEMON
	};

private:
	FruitList type;

public:


	Fruit(FruitList type) :
		type(type)
	{
	}

	FruitList getType() { return type; }
};

int main()
{
	// Доступ до FruitList здійснюється через Fruit
	Fruit avocado(Fruit::AVOCADO);

	if (avocado.getType() == Fruit::AVOCADO)
		std::cout << "I am an avocado!";
	else
		std::cout << "I am not an avocado!";

	return 0;
}