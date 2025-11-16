
#include <iostream>
#include <string>
#include <utility>

template<class T>
void swap(T& x, T& y)
{
	T tmp{ std::move(x) }; // викликає конструктор переміщення
	x = std::move(y); // викликає оператор присвоювання переміщенням
	y = std::move(tmp); // викликає оператор присвоювання переміщенням
}

int main()
{
	std::string x{ "Anton" };
	std::string y{ "Max" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	swap(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}