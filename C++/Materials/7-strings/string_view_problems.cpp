#include <iostream>
#include <string>
#include <string_view>

std::string_view askForName()
{
	std::cout << "What's your name?\n";

	// Використовуємо std::string, оскільки std::cin змінюватиме рядок
	std::string str{};
	std::cin >> str;

	// Ми переключаємося на std::string_view тільки в демонстраційних цілях.
	// Якщо ви вже маєте std::string, то немає необхідності переключатися на std::string_view
	std::string_view view{ str };

	std::cout << "Hello " << view << '\n';

	return view;
} // str знищується і, таким чином, знищується і рядок, створений str

int main()
{
	std::string_view view{ askForName() };

	// view намагається звернутися до рядка, якого вже не існує
	std::cout << "Your name is " << view << '\n'; // невизначені результати

	return 0;
}