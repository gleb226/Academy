#include<iostream>
#include<cstdarg>
using namespace std;

/*
 Для вказівки того, що функція приймає необмежену
 кількість параметрів, потрібно вказати ...
 У нашій функції є один відомий параметр — це
 numOfArgs
 Цей параметр містить число переданих змінних
 параметрів
*/
int GetMin(int numOfArgs, ...) {
	int minVal;
	va_list va;
	// ініціалізуємо va для проходу по списку параметрів
	// numOfArgs — найправіший відомий параметр
	va_start(va, numOfArgs);
	// отримуємо перше значення зі списку
	minVal = va_arg(va, int);
	int tempVal = 0;
	/*
	Ми вже отримали перше значення зі списку.
	Саме тому ми ведемо цикл до numOfArgs — 1
	*/
	for (int i = 0; i < numOfArgs — 1; i++) {
		// У циклі отримуємо одне значення за іншим
		tempVal = va_arg(va, int);

		if (minVal > tempVal)
			minVal = tempVal;
	}
	// коректне завершення роботи зі змінними списку
	va_end(va);
	return minVal;
}

int main() {
	int res = GetMin(5, 10, -33, -1, 4, 9);
	cout << "Minimum is: " << res;
	return 0;
}
