#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{ "Peach" };

	std::cout << str << '\n';

	// Ігноруємо перший символ
	str.remove_prefix(1);

	std::cout << str << '\n';

	// Ігноруємо останні 2 символи
	str.remove_suffix(2);

	std::cout << str << '\n';

	return 0;
}