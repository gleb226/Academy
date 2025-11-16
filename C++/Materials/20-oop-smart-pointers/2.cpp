
#include <iostream>

template<class T>
class Auto_ptr1
{
	T* m_ptr;
public:
	// Отримуємо вказівник для "володіння" через конструктор
	Auto_ptr1(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	// Деструктор подбає про видалення вказівника
	~Auto_ptr1()
	{
		delete m_ptr;
	}

	// Виконуємо перевантаження оператора розіменування і оператора ->, щоб мати можливість використовувати Auto_ptr1 як m_ptr
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

// Клас для перевірки працездатності вищенаведеного коду
class Item
{
public:
	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
	void sayHi() { std::cout << "Hi!\n"; }
};

void myFunction()
{
	Auto_ptr1<Item> ptr(new Item); // ptr тепер "володіє" Item-ом

	int a;
	std::cout << "Enter an integer: ";
	std::cin >> a;

	if (a == 0)
		return; // передчасне повернення функції

	// Використання ptr
	ptr->sayHi();
}

int main()
{
	myFunction();

	return 0;
}