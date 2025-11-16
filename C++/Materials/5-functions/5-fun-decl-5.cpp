#include <iostream>
using namespace std;

// малює лінію з символа — symb, довжиною count 
void anyLine(char symb, int count) {
	for (int i = 0;i < count;i++)
		cout << symb;
	cout << "\n\n";
}

int main() {
	anyLine('+', 3); // вивід лінії з трьох плюсів
	anyLine('=', 5); // вивід лінії з п'яти знаків
	// рівності
	return 0;
}