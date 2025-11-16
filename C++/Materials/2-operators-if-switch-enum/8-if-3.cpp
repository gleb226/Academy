#include <iostream>
using namespace std;

int main() {
	int A, B; // оголосимо дві змінні

	// просимо користувача ввести в них дані
	cout << "Enter your first number:\n";
	cin >> A;
	cout << "Enter your second number:\n";
	cin >> B;
	
	if (B != 0) { // якщо В не дорівнює нулю,
		cout << "Result A/B=" << A << "/" << B << "=" << A / B;
		// виконуємо обчислення
	}
	// в іншому випадку не робимо нічого
	cout << "\nThe end.\n";

	return 0;
}