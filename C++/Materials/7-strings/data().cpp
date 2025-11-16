#include <cstring>
#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{ "balloon" };

	// Видаляємо символ "b"
	str.remove_prefix(1);

	// Видаляємо частину "oon"
	str.remove_suffix(3);

	// Пам'ятайте, що попередні 2 команди не змінюють початковий рядок, вони лише працюють з його представленням
	std::cout << str << " has " << std::strlen(str.data()) << " letter(s)\n";
	std::cout << "str.data() is " << str.data() << '\n';
	std::cout << "str is " << str << '\n';

	return 0;
}