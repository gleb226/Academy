#include <iostream>

enum Colors
{
	COLOR_YELLOW, // присвоюється 0
	COLOR_WHITE,  // присвоюється 1
	COLOR_ORANGE, // присвоюється 2
	COLOR_GREEN,  // присвоюється 3
	COLOR_RED,    // присвоюється 4
	COLOR_GRAY,   // присвоюється 5
	COLOR_PURPLE, // присвоюється 6
	COLOR_BROWN   // присвоюється 7
};

int main()
{
	Colors paint(COLOR_RED);
	std::cout << paint;

	return 0;
}