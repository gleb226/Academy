#include <iostream>
using namespace std;

// Має міняти значення змінних місцями 
void change(int one, int two) {
	// 1 2 
	cout << one << " " << two << "\n\n";
	int temp = one;
	one = two;
	two = temp;
	cout << one << " " << two << "\n\n"; // 2 1
}

int main() {
	int a = 1, b = 2;

	cout << a << " " << b << "\n\n"; // 1 2
	// передача за значенням
	change(a, b);
	cout << a << " " << b << "\n\n"; // 1 2
	return 0;
}