#include <iostream>

class Dollars
{
private:
	int dollars;

public:
	Dollars(int dollars) { this->dollars = dollars; }

	// Виконуємо Dollars + Dollars через дружню функцію
	friend Dollars operator+(const Dollars& d1, const Dollars& d2);

	// Виконуємо Dollars - Dollars через дружню функцію
	friend Dollars operator-(const Dollars& d1, const Dollars& d2);

	int getDollars() const { return dollars; }
};

// Примітка: Ця функція не є методом класу!
Dollars operator+(const Dollars& d1, const Dollars& d2)
{
	// Використовуємо конструктор Dollars і operator+(int, int).
	// Ми маємо доступ до закритого члену dollars, оскілька ця функція є дружньою класу Dollars
	return Dollars(d1.dollars + d2.dollars);
}

// Примітка: Ця функція не є методом класу!
Dollars operator-(const Dollars& d1, const Dollars& d2)
{
	// Використовуємо конструктор Dollars і operator-(int, int).
	// Ми маємо доступ до закритого члену dollars, оскільки ця функція є дружньою класу Dollars
	return Dollars(d1.dollars - d2.dollars);
}

int main()
{
	Dollars dollars1(5);
	Dollars dollars2(3);
	Dollars dollarsSum = dollars1 - dollars2;
	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;

	return 0;
}