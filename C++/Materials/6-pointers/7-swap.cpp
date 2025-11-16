#include <iostream>
using namespace std;

/* Передача змінних через покажчик
 Усередині міняємо значення змінних, на які
 вказують покажчики */
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int av = 5, bv = 9;
	swap(&av, &bv);
	// 9 5
	cout << av << " " << bv << endl;
	return 0;
}