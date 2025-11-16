#include <cstring>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
	std::string_view sv{ "balloon" };

	sv.remove_suffix(3);

	// Створення об'єкту std::string з об'єкту std::string_view
	std::string str{ sv };

	// Отримуємо рядок C-style з нуль-термінатором
	auto szNullTerminated{ str.c_str() };

	// Передаємо рядок з нуль-термінатором в функцію, яку ми хочемо використовувати
	std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";

	return 0;
}