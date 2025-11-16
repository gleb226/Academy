#include <iostream>
#include <functional>

using namespace std;

int main() {
	char* chPtr; // тип char займає 1 байт
	int* iPtr; // тип int займає 4 байти

	struct Something
	{
		int nX, nY, nZ;
	};

	Something* somethingPtr;

	std::cout << sizeof(chPtr) << '\n'; // виведеться 8
	std::cout << sizeof(iPtr) << '\n'; // виведеться 8
	std::cout << sizeof(somethingPtr) << '\n'; // виведеться 8
	return 0;
}