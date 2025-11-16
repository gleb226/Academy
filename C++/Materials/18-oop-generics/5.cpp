#include <iostream>
#include <cstring>

template <class T, int size> // size є non-type параметром шаблону
class StaticArray
{
private:
	// Параметр size відповідає за довжину масиву
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
void print(StaticArray<T, size>& array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count] << ' ';
}

// Шаблон функції print() з частково спеціалізованим шаблоном класу StaticArray<char, size> в якості параметра
template <int size>
void print(StaticArray<char, size>& array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count];
}

int main()
{
	// Оголошуємо масив типу char довжиною 14
	StaticArray<char, 14> char14;

	strcpy_s(char14.getArray(), 14, "Hello, world!");

	// Виводимо елементи масиву
	print(char14);

	// Тепер оголошуємо масив типу char довжиною 12
	StaticArray<char, 12> char12;

	strcpy_s(char12.getArray(), 12, "Hello, dad!");

	// Виводимо елементи масиву
	print(char12);

	return 0;
}