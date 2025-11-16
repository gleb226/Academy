#include <iostream>
#include <array>

int main()
{
	std::array<double, 4> myarray{ 8.0, 6.4, 4.3, 1.9 };
	std::cout << "length: " << myarray.size();

	return 0;
}