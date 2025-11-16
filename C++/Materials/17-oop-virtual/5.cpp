#include <iostream>

class Parent
{
public:
	// Цей метод getThis() повертає вказівник на клас Parent
	virtual Parent* getThis() { std::cout << "called Parent::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Parent\n"; }
};

class Child : public Parent
{
public:
	// Зазвичай, типи повернення перевизначень і віртуальних функцій батьківського класу повинні співпадати.
	// Однак, оскільки Child наслідує клас Parent, наступний метод може повертати Child* замість Parent*
	virtual Child* getThis() { std::cout << "called Child::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Child\n"; }
};

int main()
{
	Child ch;
	Parent* p = &ch;
	ch.getThis()->printType(); // викликається Child::getThis(), повертається Child*, викликається Child::printType()
	p->getThis()->printType(); // викликається Child::getThis(), повертається Parent*, викликається Parent::printType()
}