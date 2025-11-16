#include <iostream>
#include <functional>

using namespace std;

int main() {
	int id = 0;
	auto f = [id]() mutable {
		std::cout << "id: " << id << std::endl;
		++id; // OK 
		};
	id = 42;

	f();
	f();
	f();

	std::cout << id << std::endl;

	return 0;
}
