#include <iostream>
#include <string>

int main()
{
	std::cout << "Pick 1 or 2: ";
	int choice;
	std::cin >> choice;

	std::cin.ignore(32767, '\n'); // видаляємо символ нового рядка з вхідного потоку даних

	std::cout << "Now enter your name: ";
	std::string myName;
	std::getline(std::cin, myName);

	std::cout << "Hello, " << myName << ", you picked " << choice << '\n';

	return 0;
}