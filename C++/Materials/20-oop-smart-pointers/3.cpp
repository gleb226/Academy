
#include <iostream>

template<class T>
class Auto_ptr2
{
	T* m_ptr;
public:
	Auto_ptr2(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// Конструктор копіювання, який реалізує семантику переміщення
	Auto_ptr2(Auto_ptr2& a) // примітка: Посилання не є константним
	{
		m_ptr = a.m_ptr; // переміщуємо наш "звичайний" вказівник від джерела до нашого локального об'єкта
		a.m_ptr = nullptr; // підтверджуємо, що джерело більше не володіє вказівником
	}

	// Оператор присвоювання, який реалізує семантику переміщення
	Auto_ptr2& operator=(Auto_ptr2& a) // примітка: Посилання не є константним
	{
		if (&a == this)
			return *this;

		delete m_ptr; // підтверджуємо, що видалили будь-який вказівник, який наш локальний об'єкт мав до цього
		m_ptr = a.m_ptr; // потім переміщуємо наш "звичайний" вказівник з джерела до нашого локального об'єкта
		a.m_ptr = nullptr; // підтверджуємо, що джерело більше не володіє вказівником
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Item
{
public:
	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
};

int main()
{
	Item* superItem = new Item;

	Item& ssuperItem;

	Auto_ptr2<Item> item1(new Item);
	Auto_ptr2<Item> item2; // почнемо з nullptr

	std::cout << "item1 is " << (item1.isNull() ? "null\n" : "not null\n");
	std::cout << "item2 is " << (item2.isNull() ? "null\n" : "not null\n");

	item2 = item1; // item2 тепер є "власником" значення item1, об'єкту item1 присвоюється null

	std::cout << "Ownership transferred\n";

	std::cout << "item1 is " << (item1.isNull() ? "null\n" : "not null\n");
	std::cout << "item2 is " << (item2.isNull() ? "null\n" : "not null\n");

	return 0;
}