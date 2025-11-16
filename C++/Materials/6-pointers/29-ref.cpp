#include <iostream>

// ref - це посилання на переданий аргумент, а не копія аргументу
void changeN(int& ref)
{
	ref = 8;
}

int main()
{
	int x = 7;

	std::cout << x << '\n';

	changeN(x); // зверніть увагу, цей аргумент не обов'язково повинен бути посиланням

	std::cout << x << '\n';
	return 0;
}