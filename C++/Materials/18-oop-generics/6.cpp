#include <iostream>

template <class T, int size> // size є non-type параметром шаблону
class StaticArray_Base
{
protected:
	// Параметр size відповідає за довжину масиву
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
	virtual void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << m_array[i] << ' ';
		std::cout << "\n";
	}
};

template <class T, int size> // size є non-type параметром шаблону
class StaticArray : public StaticArray_Base<T, size>
{
public:
	StaticArray()
	{

	}
};

template <int size> // size є non-type параметром шаблону
class StaticArray<double, size> : public StaticArray_Base<double, size>
{
public:

	virtual void print() override
	{
		for (int i = 0; i < size; i++)
			std::cout << std::scientific << this->m_array[i] << " ";
		// Примітка: Префікс this-> на вищенаведеному рядку необхідний. Чому? Читайте тут - https://stackoverflow.com/a/6592617
		std::cout << "\n";
	}
};

int main()
{
	// Оголошуємо цілочисельний масив довжиною 5
	StaticArray<int, 5> intArray;

	// Заповнюємо його, а потім виводимо на екран
	for (int count = 0; count < 5; ++count)
		intArray[count] = count;
	intArray.print();

	// Оголошуємо масив типу double довжиною 4
	StaticArray<double, 4> doubleArray;

	// Заповнюємо його, а потім виводимо на екран
	for (int count = 0; count < 4; ++count)
		doubleArray[count] = (4. + 0.1 * count);
	doubleArray.print();

	return 0;
}