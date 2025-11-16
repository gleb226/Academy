#include <iostream>
#include <string>
#include <sstream> // для std::stringstream
#include <cstdlib> // для exit()

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		// В деяких операційних системах argv[0] може бути просто порожнім рядком, без імені програми

		// Обробляємо випадки, коли argv[0] може бути порожнім або не порожнім
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		exit(1);
	}

	std::stringstream convert(argv[1]); // створюємо змінну stringstream з іменем convert, ініціалізуючи її значенням argv[1]

	int myint;
	if (!(convert >> myint)) // виконуємо конвертацію
		myint = 0; // якщо конвертація зазнає невдачі, то присвоюємо myint значення за замовчуванням

	std::cout << "Got integer: " << myint << '\n';

	return 0;
}