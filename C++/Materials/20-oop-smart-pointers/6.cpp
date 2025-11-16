#include <iostream>

template<class T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr3()
	{
		delete m_ptr;
	}

	// Конструктор копіювання, який виконує глибоке копіювання x.m_ptr в m_ptr
	Auto_ptr3(const Auto_ptr3& x)
	{
		m_ptr = new T;
		*m_ptr = *x.m_ptr;
	}

	// Оператор присвоювання копіюванням, який виконує глибоке копіювання x.m_ptr в m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& x)
	{
		// Перевірка на самоприсвоювання
		if (&x == this)
			return *this;

		// Видаляємо все, що до цього моменту може зберігати вказівник
		delete m_ptr;

		// Копіюємо переданий об'єкт
		m_ptr = new T;
		*m_ptr = *x.m_ptr;

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

Auto_ptr3<Item> generateItem()
{
	Auto_ptr3<Item> item(new Item);
	return item; // це значення, що повертається, призведе до виклику конструктора копіювання
}

int main()
{
	Auto_ptr3<Item> mainItem;
	mainItem = generateItem(); // ця операція присвоювання призведе до виклику оператора присвоювання копіюванням

	return 0;
}