#include <iostream>

class Dollars
{
private:
	int dollars;

public:
	Dollars(int dollars) { this->dollars = dollars; }

	// Виконуємо Dollars + int через дружню функцію
	friend Dollars operator+(const Dollars& d1, int value);

	// Виконуємо int + Dollars через дружню функцію
	friend Dollars operator+(int value, const Dollars& d1);


	int getDollars() { return dollars; }
};

// Примітка: Ця функція не є методом класу!
Dollars operator+(const Dollars& d1, int value)
{
	// Використовуємо конструктор Dollars і operator+(int, int).
	// Ми маємо доступ до закритого члену dollars, оскільки ця функція є дружньою класу Dollars
	return Dollars(d1.dollars + value);
}

// Примітка: Ця функція не є методом класу!
Dollars operator+(int value, const Dollars& d1)
{
	// Використовуємо конструктор Dollars і operator+(int, int).
	// Ми маємо доступ до закритого члену dollars, оскільки ця функція є дружньою класу Dollars
	return Dollars(d1.dollars + value);
}

int main()
{
	Dollars d1 = Dollars(5) + 5;
	Dollars d2 = 5 + Dollars(5);

	std::cout << "I have " << d1.getDollars() << " dollars." << std::endl;
	std::cout << "I have " << d2.getDollars() << " dollars." << std::endl;

	return 0;
}