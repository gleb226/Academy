#include <iostream>

int main()
{
	int array[4] = { 5, 8, 6, 4 };
	std::cout << *array; // виведеться 5

	int* ptr = array;
	std::cout << *ptr; // виведеться 5

	return 0;
}