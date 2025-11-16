#include <iostream>
#include <string>

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};

class ArrayInt
{
private:

	int m_data[4]; // заради збереження простоти прикладу вкажемо значення 4 в якості довжини масиву
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
	catch (ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
}