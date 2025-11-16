#include <iostream>
using namespace std;

int main() {
	int digit, sum = 0;
	for (;;) { // реалізація нескінченного циклу
		cout << "Enter digit:";
		cin >> digit; // ввід числа
		if (digit == 0) // якщо введено 0
			break; // зупинити цикл
		sum += digit; // накопичення суми
	}

	// показ результату
	cout << "Sum of digits" << sum << "\n\n";
	return 0;
}