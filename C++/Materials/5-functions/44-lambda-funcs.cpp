#include <iostream>
#include <functional>

using namespace std;

int main() {
	int x = 0;
	int y = 42;

	auto qqq = [x, &y] {
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		++y; // OK 
		};

	x = y = 77;
	qqq();
	qqq();
	std::cout << "final y: " << y << std::endl;

	return 0;
}
