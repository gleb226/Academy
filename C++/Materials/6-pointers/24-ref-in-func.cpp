#include <iostream>
using namespace std;

// Обмін з використанням покажчиків
void interchangePtr(int* u, int* v) {
	int temp = *u;
	*u = *v;
	*v = temp;
}

// Обмін з використанням посилань 
void interchangeRef(int& u, int& v) {
	int temp = u;
	u = v;
	v = temp;
}

int main() {
	int x = 5, y = 10;
	cout << "Change with pointers:\n";
	cout << "x = " << x << " y = " << y << "\n";

	// використаємо покажчикиs
	interchangePtr(&x, &y);
	cout << "x = " << x << " y = " << y << "\n";
	cout << "----------------------------- " << "\n";
	cout << "Change with references:\n";
	cout << "x = " << x << " y = " << y << "\n";

	// використаємо посилання
	interchangeRef(x, y);
	cout << "x = " << x << " y = " << y << "\n";

	return 0;
}