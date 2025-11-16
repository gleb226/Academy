#include <iostream>

int main()
{
	int array[4] = { 5, 8, 6, 4 };

	std::cout << sizeof(array) << '\n'; // виведеться sizeof(int) * довжина array

	int* ptr = array;
	std::cout << sizeof(ptr) << '\n'; // виведеться розмір вказівника

	return 0;
}