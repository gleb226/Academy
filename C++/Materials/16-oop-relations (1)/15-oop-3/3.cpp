#include <iostream>

enum FruitList
{
	AVOCADO,
	BLACKBERRY,
	LEMON
};

class Fruit
{
private:
	FruitList m_type;

public:


	Fruit(FruitList type) :
		m_type(type)
	{
	}

	FruitList getType() { return m_type; }
};

int main()
{
	Fruit avocado(AVOCADO);

	if (avocado.getType() == AVOCADO)
		std::cout << "I am an avocado!";
	else
		std::cout << "I am not an avocado!";

	return 0;
}