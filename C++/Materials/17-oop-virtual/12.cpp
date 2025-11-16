#include <iostream>
#include <string>

class Parent
{
protected:
	int m_value;

public:
	Parent(int value)
		: m_value(value)
	{
	}

	virtual ~Parent() {}
};

class Child : public Parent
{
protected:
	std::string m_name;

public:
	Child(int value, std::string name)
		: Parent(value), m_name(name)
	{
	}

	const std::string& getName() { return m_name; }
};

int main()
{
	Child banana(1, "Banana");
	Parent& p = banana;
	Child& ch = dynamic_cast<Child&>(p); // використовуємо оператор dynamic_cast для конвертації посилання класу Parent в посилання класу Child

	std::cout << "The name of the Child is: " << ch.getName() << '\n';

	return 0;
}