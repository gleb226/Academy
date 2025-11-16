#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
void insertSort(T a[], long size) {
	T x;
	long i, j;
	// цикл проход≥в, i Ч номер проходу 
	for (i = 0;i < size;i++) {
		x = a[i];
		// пошук м≥сц€ елемента в готов≥й
		// посл≥довност≥
		for (j = i - 1;j >= 0 && a[j] > x;j--)
			// зрушуЇмо елемент направо поки не д≥йшли
			a[j + 1] = a[j];
		// м≥сце знайдено, вставити елемент
		a[j + 1] = x;
	}
}

int main() {
	srand(time(NULL));
	const long SIZE = 10;
	int ar[SIZE];

	// до сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		ar[i] = rand() % 100;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	insertSort(ar, SIZE);
	// п≥сл€ сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	return 0;
}