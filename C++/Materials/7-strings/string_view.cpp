#include <iostream>
#include <string_view>

int main()
{
	std::string_view text{ "hello" }; // представлення для рядка "hello", яке зберігається у бінарному вигляді
	std::string_view str{ text }; // представлення цього ж рядка - "hello"
	std::string_view more{ str }; // представлення цього ж рядка - "hello"

	std::cout << text << ' ' << str << ' ' << more << '\n';

	return 0;
}