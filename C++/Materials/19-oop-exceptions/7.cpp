
#include <iostream>
#include <string>
#include <exception> // для std::exception

class ArrayException : public std::exception
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error(error)
	{
	}

	// Повертаємо std::string в якості константного рядка C-style
//	const char* what() const { return m_error.c_str(); } // до C++11
	const char* what() const noexcept { return m_error.c_str(); } // C++11 і новіші версії
};

class ArrayInt
{
private:

	int m_data[4]; // щоб не ускладнювати, вкажемо значення 4 в якості довжини масиву
public:
	ArrayInt() {}

	int getLength() { return 4; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}

};

int main()
{
	ArrayInt array;

	try
	{
		int value = array[7];
	}
	catch (ArrayException& exception) // спочатку ловимо винятки дочірнього класу-винятку
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}
}a