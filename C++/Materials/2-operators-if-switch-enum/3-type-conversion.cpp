#include <iostream>
using namespace std;

int main() {
	// оголошення змінних і запит на ввід даних
	float digit;
	cout << "Enter a digit:";
	cin >> digit;

	/* Навіть якщо користувач ввів число з дійсною частиною, результат виразу запишеться в int, 
	і дійсна частина буде втрачена; розділивши число на 100, ми отримаємо кількість сотень у ньому. */
	int res = digit / 100;
	cout << res << "There are this many hundreds in your digit!!!\n\n";

	return 0;
}