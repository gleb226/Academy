#include <iostream>

template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Конструктор копіювання, який виконує глибоке копіювання x.m_ptr в m_ptr
	Auto_ptr4(const Auto_ptr4& x)
	{
		m_ptr = new T;
		*m_ptr = *x.m_ptr;
	}

	// Конструктор переміщення, який передає право власності на x.m_ptr в m_ptr
	Auto_ptr4(Auto_ptr4&& x)
		: m_ptr(x.m_ptr)
	{
		x.m_ptr = nullptr; // ми поговоримо про це трішки пізніше
	}

	// Оператор присвоювання копіюванням, який виконує глибоке копіювання x.m_ptr в m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& x)
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

	// Оператор присвоювання переміщенням, який передає право власності на x.m_ptr в m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& x)
	{
		// Перевірка на самоприсвоювання
		if (&x == this)
			return *this;

		// Видаляємо все, що до цього моменту може зберігати вказівник
		delete m_ptr;

		// Передаємо право власності на x.m_ptr в m_ptr
		m_ptr = x.m_ptr;
		x.m_ptr = nullptr; // ми поговоримо про це трішки пізніше

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

Auto_ptr4<Item> generateItem()
{
	Auto_ptr4<Item> item(new Item);
	return item; // це значення, що повертається, призведе до виклику конструктора переміщення
}

int main()
{
	Auto_ptr4<Item> mainItem;
	mainItem = generateItem(); // ця операція присвоювання призведе до виклику оператора присвоювання переміщенням

	return 0;
}