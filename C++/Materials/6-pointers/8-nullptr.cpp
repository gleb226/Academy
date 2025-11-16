#include <iostream>
using namespace std;

int main()
{
	// Покажчик не ініціалізовано
	// У ньому випадкове значення
	int* ptr;
	// зараз ptr — нульовий покажчик
	// так робити не рекомендується
	ptr = 0;
	cout << ptr << endl;

	// Спадок, отриманий від мови С
	// так робити не рекомендується
	ptr = NULL;
	cout << ptr << endl;

	// сучасний спосіб С++
	// створення нульового покажчика
	ptr = nullptr;
	cout << ptr << endl;

	if (ptr == nullptr) {
		cout << "\n\nNull pointer was found!" << endl;
	}

	return 0;
}