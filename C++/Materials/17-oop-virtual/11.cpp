#include <iostream>
#include <string>

// Ідентифікатори класів
enum ClassID
{
	PARENT,
	CHILD
	// Тут можна додати ще кілька класів
};

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
	virtual ClassID getClassID() { return PARENT; }
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

	std::string& getName() { return m_name; }
	virtual ClassID getClassID() { return CHILD; }

};

Parent* getObject(bool bReturnChild)
{
	if (bReturnChild)
		return new Child(1, "Banana");
	else
		return new Parent(2);
}

int main()
{
	Parent* p = getObject(true);

	if (p->getClassID() == CHILD)
	{
		// Ми вже довели, що p вказує на об'єкт класу Child, тому ніяких проблем тут не повинно бути
		Child* ch = static_cast<Child*>(p);
		std::cout << "The name of the Child is: " << ch->getName() << '\n';
	}

	delete p;

	return 0;
}