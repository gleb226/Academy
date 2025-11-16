#include <iostream>
#include <string>
using namespace std;

void second() {
	cout << "\nSecond function\n";
}

void first() {
	cout << "\nBegin first function\n";
	second();
	cout << "\nEnd first function\n";
}

int main()
{
	first();
	return 0;
}