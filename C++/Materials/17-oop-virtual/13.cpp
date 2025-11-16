#include <iostream>

class Parent
{
public:
	Parent() {}

	// Перевантаження оператора виводу <<
	friend std::ostream& operator<<(std::ostream& out, const Parent& p)
	{
		// Делегуємо виконання операції виводу методу print()
		return p.print(out);
	}

	// Робимо метод print() віртуальним
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Parent";
		return out;
	}
};

class Child : public Parent
{
public:
	Child() {}

	// Перевизначення методу print() для роботи з об'єктами класу Child
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Child";
		return out;
	}
};

int main()
{
	Parent p;
	std::cout << p << '\n';

	Child ch;
	std::cout << ch << '\n'; // зверніть увагу, все працює навіть без наявності перевантаження оператора виводу в класі Child

	Parent& pref = ch;
	std::cout << pref << '\n';

	return 0;
}